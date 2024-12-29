#include <stdio.h>
#include <assert.h>
#include "listLib.h"
#include "CUnit/Basic.h"

/* 测试listCreate和listDestroy方法 */
void test_listCreate()
{
    LIST *list = NULL;
    LIST *listEmpty = NULL;

    list = listCreate();
    CU_ASSERT(NULL != list);

    CU_ASSERT(RET_VAL_NO_ERROR == listDestory(list));
    CU_ASSERT(RET_VAL_NO_ERROR != listDestory(listEmpty));

    return;
}

/* 测试listNodeAdd/Del/Get/Set方法 */
void test_listNodeAddDelGetSet()
{
    LIST *list = listCreate();
    LIST *listNull = NULL;
    int node0 = 0;
    int node1 = 1;
    int node2 = 2;
    int node3 = 3;
    int nodeTmp = 0;

    CU_ASSERT(RET_VAL_NO_ERROR != listNodeAdd(listNull, &node0, 1));    /* null list */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeAdd(list, &node1, 2));        /* error index */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeAdd(list, &node1, -1));       /* error index */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeDel(listNull, 1))             /* del null list */

    listPrintfIntDemo(list);

    CU_ASSERT(RET_VAL_NO_ERROR == listNodeAdd(list, &node0, 1));
    CU_ASSERT(RET_VAL_NO_ERROR == listNodeAdd(list, &node1, 1));
    CU_ASSERT(RET_VAL_NO_ERROR == listNodeAdd(list, &node2, 2));
    CU_ASSERT(RET_VAL_NO_ERROR == listNodeAdd(list, &node3, 3));

    listPrintfIntDemo(list);

    CU_ASSERT(RET_VAL_NO_ERROR != listNodeGetByIdx(listNull, 1, sizeof(int), &nodeTmp));    /* get null list */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeGetByIdx(list, 0, sizeof(int), &nodeTmp));        /* get error index */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeGetByIdx(list, 6, sizeof(int), &nodeTmp));        /* get error index */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeGetByIdx(list, 1, sizeof(int), NULL));
    CU_ASSERT(RET_VAL_NO_ERROR == listNodeGetByIdx(list, 1, sizeof(int), &nodeTmp));
    CU_ASSERT(1 == nodeTmp);

    CU_ASSERT(RET_VAL_NO_ERROR == listNodeDel(list, 1));
    CU_ASSERT(RET_VAL_NO_ERROR == listNodeDel(list, 2));
    listPrintfIntDemo(list);

    CU_ASSERT(RET_VAL_NO_ERROR == listNodeSetByIdx(list, 1, sizeof(int), &node1));
    CU_ASSERT(RET_VAL_NO_ERROR == listNodeGetByIdx(list, 1, sizeof(int), &nodeTmp) && 1 == nodeTmp);

    CU_ASSERT(RET_VAL_NO_ERROR != listNodeDel(listNull, -1))             /* del error index */
    CU_ASSERT(RET_VAL_NO_ERROR != listNodeDel(list, 4))                  /* del error index */

    CU_ASSERT(RET_VAL_NO_ERROR == listDestory(list));

    return;
}

/* ============================================================ */

/* 描述测试方法 */
CU_TestInfo testCase0[] = {
    {"test_for_listCreate:\r\n", test_listCreate},
    {"test_for_listNodeAddDel:\r\n", test_listNodeAddDelGetSet},
    CU_TEST_INFO_NULL
};

/* suite初始化 */
static int suite_init() {return 0;}
/* suite清理 */
static int suite_clean() {return 0;}

/* suite数组，包含若干个测试方法 */
CU_SuiteInfo suites[] = {
    {"testSuite0", suite_init, suite_clean, NULL, NULL, testCase0},
    CU_SUITE_INFO_NULL
};

/* 测试类的调用总接口 */
void AddTests()
{
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());

    if(CUE_SUCCESS != CU_register_suites(suites))
    {
        exit(EXIT_FAILURE);
    }
}

/* 运行测试的入口函数 */
int runTest()
{
    if(CU_initialize_registry())
    {
        DBG_ERR("init test registry failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        AddTests();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}

int main()
{
    return runTest();
}