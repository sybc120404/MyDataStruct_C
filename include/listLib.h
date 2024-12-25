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

/*==========================
    function declaration
*/

/*
    name:       listCreate
    brief:      create a list
    param_in:   None
    param_out:  None
    output:     error code
*/
RET_VAL listCreate(OUT LIST **list);

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

#endif