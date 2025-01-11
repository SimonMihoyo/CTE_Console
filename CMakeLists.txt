cmake_minimum_required(VERSION 3.10)

project(CTE_Console)

# 设置使用的 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# 使用 file(GLOB ...) 搜索 src/main 目录下的所有 .cpp 文件
file(GLOB SOURCE_FILES src/Main/*.cpp)

# 打印源文件列表，进行调试
message("Source files: ${SOURCE_FILES}")

# set(CMAKE_EXE_LINKER_FLAGS "-static")

# 添加可执行文件
add_executable(CTE_Console ${SOURCE_FILES}
        src/Headers/common.h)

#
if(WIN32)

    # 设置链接库目录
    target_link_directories(CTE_Console PRIVATE lib)
endif ()

# 设置头文件目录
target_include_directories(CTE_Console PRIVATE src/Header)


