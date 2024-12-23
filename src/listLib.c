/*
    Author: Cai
    Data:   29Dec24
    Description:    C file of listLib
*/

/*==========================
    include files
*/
#include "listLib.h"

/*==========================
    data declaration
*/

/*==========================
    static function definition
*/

/*
    name:       listNodeCreate
    brief:      create a list node
    param_in:   pData - prt to data
    param_out:  None
    output:     ptr to list node
*/
static LIST_NODE* listNodeCreate(IN void *pData)
{
    LIST_NODE *listNode = NULL;

    listNode = (LIST_NODE*) malloc(sizeof(LIST_NODE));
    if(NULL != listNode)
    {
        memset(listNode, 0, sizeof(LIST_NODE));
        listNode->pData = pData;
    }

    return listNode;
}

/*
    name:       listNodeDestroy
    brief:      destroy a list node
    param_in:   listNode - list node to be destroyed
    param_out:  None
    output:     error code
*/
static RET_VAL listNodeDestroy(IN LIST_NODE *listNode)
{
    PFM_ENSURE_RET(NULL != listNode, RET_VAL_BAD_PARAM);

    free(listNode);

    return RET_VAL_NO_ERROR;
}

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
    LIST *listTmp = NULL;
    RET_VAL ret = RET_VAL_NO_ERROR;
    LIST_NODE *listHead = NULL;

    PFM_ENSURE_RET(NULL == list, RET_VAL_BAD_PARAM);

    listTmp = (LIST*) malloc(sizeof(LIST));
    if(NULL == listTmp)
    {
        ret = RET_VAL_NO_MEMORY;
        goto done;
    }

    memset(listTmp, 0, sizeof(LIST));

    /* create a dummy node as listHead */
    listHead = listNodeCreate(NULL);
    if(!listHead)
    {
        free(listTmp);
        ret = RET_VAL_NO_MEMORY;
    }
    
    listTmp->headNode = listHead;
    listTmp->len = 0;

    memcpy(list, listTmp, sizeof(LIST));

done:
    return ret;
}

/*
    name:       listDestory
    brief:      destroy a list
    param_in:   None
    param_out:  None
    output:     error code
    Others:

              cur
    HEAD  ->  A  ->  B  ->  C  ->  D  ->
*/
RET_VAL listDestory(IN LIST *list)
{
    RET_VAL ret = RET_VAL_NO_ERROR;
    LIST_NODE *listHead = NULL;
    LIST_NODE *curNode = NULL;

    PFM_ENSURE_DONE(NULL != list, ret, RET_VAL_BAD_PARAM);

    listHead = list->headNode;
    while(listHead->next)
    {
        curNode = listHead->next;
        listHead->next = curNode->next;
        listNodeDestroy(curNode);
    }

done:
    /* free dummy node */
    listNodeDestroy(list->headNode);
    free(list);
    return ret;
}

/*
    name:       listLenGet
    brief:      get length of a list, exclude listHead
    param_in:   list - ptr to list
    param_out:  listLen - ptr to length of list
    output:     error code
*/
RET_VAL listLenGet(IN LIST *list, OUT int *listLen)
{
    PFM_ENSURE_RET(NULL != list && NULL != listLen, RET_VAL_BAD_PARAM);

    *listLen = list->len;

    return RET_VAL_NO_ERROR;
}

/*
    name:       listNodeAdd
    brief:      add a node in idx of list
    param_in:   list - ptr to list
                pData - ptr to data of node
                idx - index of node to add, idx start from 1
    param_out:  None
    output:     error code
*/
RET_VAL listNodeAdd(IN LIST *list, void *pData, IN int idx)
{
    int curIdx = 1;
    LIST_NODE *curNode = NULL;
    LIST_NODE *newNode = NULL;

    PFM_ENSURE_RET((NULL != list) && (idx > 0) && (idx <= (list->len+1)), RET_VAL_BAD_PARAM);

    newNode = listNodeCreate(pData);
    PFM_ENSURE_RET(NULL != newNode, RET_VAL_NO_MEMORY);

    /* find the front of node to add */
    curNode = list->headNode;
    for(curIdx = 1; curIdx < idx; ++ curIdx)
    {
        curNode = curNode;
    }

    newNode->next = curNode->next;
    curNode->next = newNode;

    ++ (list->len);

    return RET_VAL_NO_ERROR;
}