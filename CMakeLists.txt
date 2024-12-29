# 指定最低CMake版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本
project(MyProject VERSION 1.0)

# set(CMAKE_VERBOSE_MAKEFILE ON)  # 对于make时实际使用的编译选项很重要

# 添加编译选项
set(CMAKE_CXX_FLAG_OPT "-O")
set(CMAKE_CXX_FLAG_WARN "-Wall")
set(CAMKE_CXX_FLAGS_CUnit "-lcunit -lncurses")

# 添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/include)

# 添加源文件
add_library(listLib src/listLib.c)    # 创建库目标listLib
add_library(lockLib src/lockLib.c)    # 创建库目标lockLib
add_library(rpcLib src/rpcLib.c)      # 创建库目标rpcLib

# 添加可执行文件
add_executable(testMyList src/testMyList.c) # 创建可执行文件目标myList
add_executable(testLock src/testLock.c) # 创建可执行文件目标testLock
add_executable(testRpc src/testRpc.c) # 创建可执行文件目标testRpc

# 添加第三方静态库目录
link_directories(/home/csy/cunit/lib)

# 链接库到可执行文件
target_link_libraries(testMyList listLib libcunit.a libcunit.so)
target_link_libraries(testLock lockLib)
target_link_libraries(testRpc rpcLib)

# 针对不同的目标使用不同的编译选项
target_compile_options(testMyList PRIVATE ${CMAKE_CXX_FLAG_OPT} ${CMAKE_CXX_FLAG_WARN} ${CMAKE_CXX_FLAGS_CUnit})
target_compile_options(testLock PRIVATE ${CMAKE_CXX_FLAG_WARN} ${CMAKE_CXX_FLAG_OPT})
target_compile_options(testRpc PRIVATE ${CMAKE_CXX_FLAG_WARN} ${CMAKE_CXX_FLAG_OPT})