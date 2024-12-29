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
}

/* 描述测试方法 */
CU_TestInfo testCase0[] = {
    {"test_for_listCreate: ", test_listCreate},
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