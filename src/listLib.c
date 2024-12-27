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

LIST* listCreate()
{
    LIST_NODE *listHead = NULL;
    LIST *list = NULL;

    list = (LIST*) malloc(sizeof(LIST));
    if(NULL == list)
    {
        goto done;
    }

    memset(list, 0, sizeof(LIST));

    /* create a dummy node as listHead */
    listHead = listNodeCreate(NULL);
    if(!listHead)
    {
        free(list);
        list = NULL;
        goto done;
    }

    list->headNode = listHead;
    list->len = 0;

done:
    return list;
}

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

RET_VAL listLenGet(IN LIST *list, OUT int *listLen)
{
    PFM_ENSURE_RET(NULL != list && NULL != listLen, RET_VAL_BAD_PARAM);

    *listLen = list->len;

    return RET_VAL_NO_ERROR;
}

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
        curNode = curNode->next;
    }

    newNode->next = curNode->next;
    curNode->next = newNode;

    ++ (list->len);

    return RET_VAL_NO_ERROR;
}

RET_VAL listNodeDel(IN LIST *list, IN int idx)
{
    LIST_NODE *preNode = NULL;
    LIST_NODE *delNode = NULL;
    int i = 1;

    PFM_ENSURE_RET((NULL != list) && (idx > 0) && (idx <= list->len), RET_VAL_BAD_PARAM);

    preNode = list->headNode;
    for(i = 1; i < idx; ++ i)
    {
        preNode = preNode->next;
    }

    delNode = preNode->next;
    preNode->next = delNode->next;

    -- (list->len);

    listNodeDestroy(delNode);

    return RET_VAL_NO_ERROR;
}

RET_VAL listNodeForEach(IN LIST *list, IN LIST_FOR_EACH_FUNC pFunc)
{
    int i = 0;
    LIST_NODE *curNode = NULL;

    PFM_ENSURE_RET((NULL != list) && (NULL != pFunc), RET_VAL_BAD_PARAM);

    curNode = list->headNode->next;

    for(i = 0; i < list->len; ++ i)
    {
        pFunc(curNode);
        curNode = curNode->next;
    }

    return RET_VAL_NO_ERROR;
}

RET_VAL listSort(IN LIST *list, IN LIST_NODE_CMP_FUNC pFunc)
{
    PFM_ENSURE_RET(NULL != list && NULL != pFunc, RET_VAL_BAD_PARAM);

    return RET_VAL_NO_ERROR;
}