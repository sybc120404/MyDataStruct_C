## 通用链表

本项目是一个通用链表

### 运行环境

本项目使用CUnit进行接口测试，需要保证运行环境安装Cunit，并且需要修改CMakeLists.txt进行正确链接
```
# 添加第三方静态库目录
link_directories(/home/csy/cunit/lib)   # cunit lib目录

# 链接库到可执行文件
target_link_libraries(testMyList listLib libcunit.a libcunit.so) # 添加cunit静态、动态库
```

### 构建方法

```bash
mkdir build
cd build
cmake ..
make
valgrind --leak-check=full ./testMyList     // 检查内容泄露，需要安装valgrind
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

- `LIST* listCreate()`：创建一个链表
- `RET_VAL listDestory(LIST *list)`：销毁一个链表
- `RET_VAL listNodeAdd(IN LIST *list, void *pData, IN int idx)`：指定位置处加入新链表节点，idx从1开始
- `RET_VAL listNodeDel(IN LIST *list, IN int idx)`：删除idx位置处的节点，idx从1开始
- `RET_VAL listNodeGetByIdx(IN LIST *list, IN int idx, IN size_t dataSize, OUT void* pData)`：获取idx位置节点的data
- `RET_VAL listNodeSetByIdx(IN LIST *list, IN int idx, IN size_t dataSize, IN void* pData)`：设置idx位置节点的data
- `RET_VAL listNodeIsExist(IN LIST *list, IN size_t dataSize, IN void* pData, OUT int *exist)`：判断是否存在data节点
- `RET_VAL listNodeForEach(IN LIST *list, IN LIST_FOR_EACH_FUNC pFunc)`：对于每一个节点，执行pFunc操作，pFunc是一个函数指针，详见定义
- `RET_VAL listPrintfDemo()`：打印链表的demo，实际上应该使用链表的用户自己定义