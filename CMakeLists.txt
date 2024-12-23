# 指定最低CMake版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本
project(MyProject VERSION 1.0)

# 添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加源文件
add_library(listLib src/listLib.c)    # 创建库目标listLib
add_executable(myList src/main.c) # 创建可执行文件目标myList

# 链接库到可执行文件
target_link_libraries(myList listLib)