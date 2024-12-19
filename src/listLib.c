/*
    Author: Cai
    Data:   29Dec24
    Description:    C file of listLib
*/

/*==========================
    include files
*/
#include "../include/listLib.h"

/*==========================
    data declaration
*/

/*==========================
    function definition
*/

/*
    name:       listCreate
    brief:      create a list
    param_in:   list, should be NULL
    param_out:  None
    output:     error code
*/
RET_VAL listCreate(OUT LIST *list)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_RET(NULL == list, RET_VAL_BAD_PARAM);

    list = (LIST*) malloc(sizeof(LIST));
    if(NULL == list)
    {
        ret = RET_VAL_NO_MEMORY;
        goto done;
    }

    memset(list, 0, sizeof(LIST));

done:
    return ret;
}

/*
    name:       listDestory
    brief:      destroy a list
    param_in:   None
    param_out:  None
    output:     error code
*/
RET_VAL listDestory()
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    return ret;
}

/* test main */
int main()
{
    LIST *list = NULL;

    printf("rv = %d\n", listCreate(list));

    return 0;
}