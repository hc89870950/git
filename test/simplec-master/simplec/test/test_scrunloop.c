﻿#include <schead.h>
#include <scrunloop.h>

#define _INT_SLEEP		(1000)

// 一直写数据
static void _run(char * msg) {
	static int _cnt = 0;
	printf("%d = %s.\n", ++_cnt, msg);
}

// 需要处理的函数操作, 写数据进去
static srl_t _write(srl_t s) {
	int i;
	char * msg;
	
	// 写五次数据
	for (i = 0; i < 5; ++i) {
		msg = malloc(sizeof(int));
		msg[0] = i + '0';
		msg[1] = '\0';
		srl_push(s, msg);
	}

	sh_msleep(_INT_SLEEP);

	// 再写五次数据
	for (i = 5; i < 10; ++i) {
		msg = malloc(sizeof(int));
		msg[0] = i + '0';
		msg[1] = '\0';
		srl_push(s, msg);
	}

	sh_msleep(_INT_SLEEP);

	return s;
}

//
// 测试轮询器代码是否可以奔跑
//
void test_scrunloop(void) {
	pthread_t th;
	srl_t s = srl_create(_run, free);

	// 开启线程, 跑起来测试
	if (pthread_create(&th, NULL, (start_f)_write, s) < 0) {
		srl_delete(s);
		CERR_EXIT("pthread_create is _run s = %p error!", s);
	}

	// 开始奔跑等待了
	pthread_join(th, NULL);

	srl_delete(s);
}