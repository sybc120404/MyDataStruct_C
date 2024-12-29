## MyDataStruct_C

本项目使用C语言实现常见数据结构，目前包括

- lockLib: 锁，包括读写锁
- listLib: 通用链表

详见src目录与include目录

此外包含调试打印等额外支持，详见lib目录

### 运行环境

本项目使用 CUnit 进行接口测试，需要保证运行环境安装 CUnit，并且需要修改 `CMakeLists.txt` 进行正确链接：

```cmake
# 添加第三方静态库目录
link_directories(/home/csy/cunit/lib)   # CUnit lib 目录

# 链接库到可执行文件
target_link_libraries(testMyList listLib libcunit.a libcunit.so) # 添加 CUnit 静态、动态库
```

### 构建方法

```bash
mkdir build
cd build
cmake ..
make
valgrind --leak-check=full ./testMyList     # 检查内存泄露，需要安装 valgrind
sudo ./testLock                             # 测试读写锁，需要sudo运行
```

## 设计文档

### 锁

锁的实现调用POSIX的读写锁，这里仅做了一层封装

对外接口
- `LOCK`作为`pthread_rwlock_t`的别名
- `LOCK_INIT`：初始化锁
- `LOCK_DESTORY`：销毁锁
- `LOCK_WRITE_TAKE`：获取写锁
- `LOCK_WRITE_RELEASE`：释放写锁
- `LOCK_READ_TAKE`：获取读锁
- `LOCK_READ_RELEASE`：释放读锁


### 通用链表

#### list_node

`list_node` 作为链表的结点，包含两个字段：

```c
/* struct of list node */
typedef struct list_node {
    void *pData;                /* data */
    struct list_node *next;     /* next field */
} LIST_NODE;
```

1. `pData` 是一个 `void` 指针，指向数据，数据的保存不由链表节点保证。
2. `next` 是指向链表下一个节点的指针。

#### list

`list` 记录的是链表，定义如下：

```c
/* struct of list manager */
typedef struct list {
    LIST_NODE *headNode;        /* head node of list */
    int len;                    /* length of list, exclude headNode */
} LIST;
```

1. `headNode` 指向链表头，这是一个哑节点，仅用于标记链表起始，方便代码实现。
2. `len` 表示链表长度，为数据节点的个数，不含哑节点。

#### 对外接口

- `LIST* listCreate()`：创建一个链表。
- `RET_VAL listDestroy(LIST *list)`：销毁一个链表。
- `RET_VAL listNodeAdd(IN LIST *list, void *pData, IN int idx)`：在指定位置处加入新链表节点，`idx` 从 1 开始。
- `RET_VAL listNodeDel(IN LIST *list, IN int idx)`：删除 `idx` 位置处的节点，`idx` 从 1 开始。
- `RET_VAL listNodeGetByIdx(IN LIST *list, IN int idx, IN size_t dataSize, OUT void* pData)`：获取 `idx` 位置节点的数据。
- `RET_VAL listNodeSetByIdx(IN LIST *list, IN int idx, IN size_t dataSize, IN void* pData)`：设置 `idx` 位置节点的数据。
- `RET_VAL listNodeIsExist(IN LIST *list, IN size_t dataSize, IN void* pData, OUT int *exist)`：判断是否存在指定数据的节点。
- `RET_VAL listNodeForEach(IN LIST *list, IN LIST_FOR_EACH_FUNC pFunc)`：对每一个节点执行 `pFunc` 操作，`pFunc` 是一个函数指针，详见定义。
- `RET_VAL listPrintfDemo()`：打印链表的示例，实际使用中应由链表的用户自行定义。