#include <scjson.h>

//
// test scjson gbk 
//
void test_scjson_gbk(void) {
    char * json = u8"{ \"name\" : \"n��h��8\" }";

    printf("json :\n %s\n", json);

    // ������ json ����
    cjson_t root = cjson_newstr(json);
    CERR_IF(NULL == root);

    cjson_t name = cjson_getobject(root, "name");
    printf("name -> %s\n", name->vs);
    // ��� UTF-8 ���ļ���
    tstr_fwrites("logs/jstr.log", name->vs);

    // ͨ�� json ���󹹽� json ������
    char * jstr = cjson_getstr(root);
    CERR_IF(NULL == jstr);

    //�Ϸ���Χֱ����� ����
    printf("jstr :\n %s\n", jstr);

    // �ͷ��ڴ�
    free(jstr);
    cjson_delete(root);
}
