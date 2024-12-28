/*
    Author: Cai
    Data:   29Dec24
    Description:    C header of listLib
*/
#ifndef _LIST_LIB__
#define _LIST_LIB__
/*==========================
    include files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "err.h"
#include "def.h"
#include "debug.h"

/*==========================
    typedef 
*/

/* struct of list node */
typedef struct list_node
{
    void *pData;                /* data */
    struct list_node *next;     /* next filed */
}LIST_NODE;

/* struct of list manager */
typedef struct list
{
    LIST_NODE *headNode;        /* head node of list */
    int len;                    /* length of list, exclude headNode */
}LIST;

/* func for foreach */
typedef void (*LIST_FOR_EACH_FUNC)(IN LIST_NODE*);        /* define a type:  LIST_FOR_EACH_FUNC -> void (*) (LIST_NODE*)*/
/* func for compare */
typedef void (*LIST_NODE_CMP_FUNC)(IN LIST_NODE*, IN LIST_NODE*);

/*==========================
    function declaration
*/

/*
    name:       listCreate
    brief:      create a list
    param_in:   None
    param_out:  None
    output:     ptr to list
*/
LIST* listCreate();

/*
    name:       listDestory
    brief:      destroy a list
    param_in:   list - ptr to list
    param_out:  None
    output:     error code
*/
RET_VAL listDestory(LIST *list);

/*
    name:       listLenGet
    brief:      get length of a list, exclude listHead
    param_in:   list - ptr to list
    param_out:  listLen - ptr to length of list
    output:     error code
*/
RET_VAL listLenGet(IN LIST *list, OUT int *listLen);

/*
    name:       listNodeAdd
    brief:      add a node in idx of list
    param_in:   list - ptr to list
                pData - ptr to data of node
                idx - index of node to add, idx start from 1
    param_out:  None
    output:     error code
*/
RET_VAL listNodeAdd(IN LIST *list, void *pData, IN int idx);

/*
    name:       listNodeDel
    brief:      delete a node of idx of list
    param_in:   list - ptr to list
                idx - index of node to add, idx start from 1
    param_out:  None
    output:     error code
*/
RET_VAL listNodeDel(IN LIST *list, IN int idx);

/*
    name:       listNodeGetByIdx
    brief:      get a node of idx of list
    param_in:   list - ptr to list
                idx - index of node to add, idx start from 1
                dataSize - sizeof(data)
    param_out:  pData   - pointer of data
    output:     error code
*/
RET_VAL listNodeGetByIdx(IN LIST *list, IN int idx, IN size_t dataSize, OUT void* pData);

/*
    name:       listNodeSetByIdx
    brief:      set data of a node of idx of list
    param_in:   list - ptr to list
                idx - index of node to add, idx start from 1
                dataSize - sizeof(data)
                pData   - pointer of data
    param_out:  None
    output:     error code
*/
RET_VAL listNodeSetByIdx(IN LIST *list, IN int idx, IN size_t dataSize, IN void* pData);

/*
    name:       listNodeIsExist
    brief:      check if list node exist in list, by data
    param_in:   list - ptr to list
                dataSize - sizeof(data)
                pData   - pointer of data
    param_out:  exist - pointer to result, 1-exist, 0-not_exist
    output:     error code
*/
RET_VAL listNodeIsExist(IN LIST *list, IN size_t dataSize, IN void* pData, OUT int *exist);

/*
    name:       listNodeForEach
    brief:      for each node, perform pFunc
    param_in:   list - ptr to list
                pFunc - ptr to function
    param_out:  None
    output:     error code
*/
RET_VAL listNodeForEach(IN LIST *list, IN LIST_FOR_EACH_FUNC pFunc);

#endif