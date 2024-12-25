#include "listLib.h"

int main()
{
    LIST *list = NULL;

    printf("rv = %d\n", listCreate(&list));

    printf("rv = %d\n", listDestory(list));

    return 0;
}