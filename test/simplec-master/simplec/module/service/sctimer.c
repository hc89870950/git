﻿#include <list.h>
#include <scatom.h>
#include <sctimer.h>

// 使用到的定时器结点
struct stnode {
    $LIST_HEAD;

    int id;                 // 当前定时器的id
    struct timespec tv;     // 运行的具体时间
    node_f timer;           // 执行的函数事件
    void * arg;             // 执行函数参数
};					   
							   
// 当前链表对象管理器			  
struct stlist {				   
    int lock;               // 加锁用的
    int nowid;              // 当前使用的最大timer id
    bool status;            // false表示停止态, true表示主线程loop运行态
    struct stnode * head;   // 定时器链表的头结点
};

// 定时器对象的单例, 最简就是最复杂
static struct stlist _st;

// 先创建链表对象处理函数
static struct stnode * _stnode_new(int s, node_f timer, void * arg) {
	struct stnode * node = malloc(sizeof(struct stnode));
	if (NULL == node)
		RETURN(NULL, "malloc struct stnode is error!");

	// 初始化, 首先初始化当前id
	node->id = ATOM_INC(_st.nowid);
	timespec_get(&node->tv, TIME_UTC);
	node->tv.tv_sec += s / 1000;
	node->tv.tv_nsec += (s % 1000) * 1000000;
	node->timer = timer;
	node->arg = arg;

	return node;
}

// 得到等待的微秒时间, <=0的时候头时间就可以执行了
static inline int _stlist_sus(struct stlist * st) {
	struct timespec t[1], * v = &st->head->tv;
	timespec_get(t, TIME_UTC);
	return (int)((v->tv_sec - t->tv_sec) * 1000000
		+ (v->tv_nsec - t->tv_nsec) / 1000);
}

// 重新调整, 只能在 _stlist_loop 后面调用, 线程安全,只加了一把锁
static void _stlist_run(struct stlist * st) {
	struct stnode * sn;

	ATOM_LOCK(st->lock); // 加锁防止调整关系覆盖,可用还是比较重要的
	sn = st->head;
	st->head = list_next(sn);
	ATOM_UNLOCK(st->lock);

	sn->timer(sn->arg);
	free(sn);
}

// 运行的主loop,基于timer管理器
static void * _stlist_loop(struct stlist * st) {
	// 正常轮询,检测时间
	while (st->head) {
		int nowt = _stlist_sus(st);
		if (nowt > 0) {
			usleep(nowt);
			continue;
		}
		_stlist_run(st);
	}

	// 已经运行结束
	st->status = false;
	return NULL;
}

// st < sr 返回 < 0, == 返回 0, > 返回 > 0
static inline int _stnode_cmptime(const struct stnode * sl, const struct stnode * sr) {
	if (sl->tv.tv_sec != sr->tv.tv_sec)
		return (int)(sl->tv.tv_sec - sr->tv.tv_sec);
	return (int)(sl->tv.tv_nsec - sr->tv.tv_nsec);
}

//
// st_add - 添加定时器事件,虽然设置的属性有点多但是都是必要的
// intval	: 执行的时间间隔, <=0 表示立即执行, 单位是毫秒
// timer	: 定时器执行函数
// arg		: 定时器参数指针
// return	: 返回这个定时器的唯一id
//
int 
st_add_(int intval, node_f timer, void * arg) {
	struct stnode * now;
	// 各种前戏操作
	if (intval <= 0) {
		timer(arg);
		return SufBase;
	}

	now = _stnode_new(intval, timer, arg);
	if (NULL == now) {
		RETURN(ErrAlloc, "_new_stnode is error intval = %d.", intval);
	}

	ATOM_LOCK(_st.lock); //核心添加模块 要等, 添加到链表, 看线程能否取消等

	list_add(&_st.head, _stnode_cmptime, now);

	// 这个时候重新开启线程
	if(!_st.status) {
		if (async_run(_stlist_loop, &_st)) {
			list_destroy(&_st.head, free);
			RETURN(ErrFd, "pthread_create is error!");
		}
		_st.status = true;
	}

	ATOM_UNLOCK(_st.lock);
	
	return now->id;
}

// 通过id开始查找
static inline int _stnode_cmpid(int id, const struct stnode * sr) {
	return id - sr->id;
}

//
// st_del - 删除指定事件
// id		: st_add 返回的定时器id
// return	: void
//
void 
st_del(int id) {
	struct stnode * node;
	if (!_st.head) return;

	ATOM_LOCK(_st.lock);
	node = list_findpop(&_st.head, _stnode_cmpid, id);
	ATOM_UNLOCK(_st.lock);

	free(node);
}