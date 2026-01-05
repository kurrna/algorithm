cmake_minimum_required(VERSION 3.29)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

# 包含算法头文件目录
include_directories(${PROJECT_SOURCE_DIR})

# 收集所有算法源文件
file(GLOB ALGORITHM_SOURCES
        "src/algorithms/*.cpp"
)

# 收集所有算法头文件
file(GLOB ALGORITHM_HEADERS
        "src/algorithms/*.hpp"
)

# 收集所有测试头文件
file(GLOB TEST_HEADERS
        "src/tests/*.hpp"
)

# 创建可执行文件
add_executable(algorithm
        src/main.cpp
        ${ALGORITHM_SOURCES}
        ${ALGORITHM_HEADERS}
        ${TEST_HEADERS}
)

# 设置输出目录
set_target_properties(algorithm PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
