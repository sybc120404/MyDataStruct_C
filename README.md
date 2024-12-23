## 通用链表

本项目是一个通用链表

### 构建方法

```bash
mkdir build
cd build
cmake ..
make
./myList
```

### 设计文档

#### list node

listNode作为链表的结点，包含两个field
```c
/* struct of list node */
typedef struct list_node
{
    void *pData;                /* data */
    struct list_node *next;     /* next filed */
}LIST_NODE;
```
1. `pData`是一个`void`指针，指向数据，数据的保存不由链表节点保证
2. `next`则是指向链表下一个节点的指针

#### list

list记录的是链表，定义如下
```c
/* struct of list manager */
typedef struct list
{
    LIST_NODE *headNode;        /* head node of list */
    int len;                    /* length of list, exclude headNode */
}LIST;
```
1. `headNode`指向链表头，这是一个哑节点，仅用于标记链表起始，方便代码实现
2. `len`表示链表长度，为数据节点的个数，不含哑节点

#### 对外接口：

- `RET_VAL listCreate(OUT LIST *list);`：创建一个链表
- `RET_VAL listDestory(LIST *list);`：销毁一个链表
- `RET_VAL listNodeAdd(IN LIST *list, void *pData, IN int idx)`：指定位置处加入新链表节点