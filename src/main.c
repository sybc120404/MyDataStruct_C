#include "listLib.h"

static void printfInt(LIST_NODE *node)
{
    if(NULL != node && NULL != node->pData)
    {
        printf("data: %d\n", *(int*)(node->pData));
    }
    else
    {
        printf("-\n");
    }

    return;
}

int main()
{
    LIST *list = listCreate();
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    if(NULL != list)
    {
        printf("list create OK.\n");
    }
    else
    {
        printf("list create FAIL.\n");
        return 0;
    }

    listNodeAdd(list, &a, 1);
    listNodeAdd(list, &b, 2);
    listNodeAdd(list, &c, 3);
    listNodeDel(list, 3);
    listNodeAdd(list, &d, 3);

    listNodeForEach(list, printfInt);

    printf("rv = %d\n", listDestory(list));

    DBG("common printf: %s", "hello world");
    DBG_ALZ("always printf");
    DBG_ERR("error fail");

    return 0;
}