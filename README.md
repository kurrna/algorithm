# 算法设计期末复习项目

本项目使用C++实现和测试各种经典算法。采用模块化设计，易于扩展。

## 软件环境

- C++ 17
- CLion 2025.3

## 项目结构

```
algorithm/
├── CMakeLists.txt          # CMake构建配置
├── main.cpp                # 主程序入口（简洁，只负责注册测试）
├── README.md               # 项目说明
├── TODO.md                 # 待实现算法清单（已按课程与拓展分类）
├── algorithms/             # 算法实现目录
│   ├── AlgorithmTemplate.h # 新算法模板
│   ├── YourAlgorithm.cpp   # 你的算法实现
│   └── YourAlgorithm.h
└── tests/                  # 测试类目录
    ├── TestBase.h          # 测试基类
    ├── TestManager.h       # 测试管理器
    ├── TestTemplate.h      # 新测试模板
    └── YourAlgorthmTest.h  # 你的算法测试
```

## 已实现的算法

[TODO.md](./TODO.md)

## 编译和运行

```bash
# 使用CMake
cd cmake-build-debug
cmake ..
cmake --build .
.\algorithm.exe  # Windows
```

或者使用CLion直接打开项目并运行。

## 快速开始：添加新算法

1. **创建算法实现**：在 `algorithms/` 目录创建 `YourAlgorithm.h`
2. **创建测试类**：复制 `tests/TestTemplate.h` 并修改
3. **注册测试**：在 `main.cpp` 中添加两行代码

示例：
```cpp
// main.cpp
#include "tests/YourAlgorithmTest.h"  // 第1行

// 在 main 函数中
manager.registerTest(std::make_shared<YourAlgorithmTest>());  // 第2行
```

## 测试管理器功能

```cpp
// 运行所有测试
manager.runAll();

// 运行特定测试
manager.runTest("QuickSort");

// 列出所有测试
manager.listTests();
```

## TODO.md 已更新

为了便于复习与实现，`TODO.md` 已重构为两个部分：

- `2025 秋 - 算法设计（课程部分）`：按课程讲次列出本学期核心实现任务（优先级高）
- `拓展部分`：进阶数据结构与算法，适合作为延伸练习或项目扩展

条目来自课程讲义（`lists.txt`），请根据实现进度在 `TODO.md` 中更新复选状态。

## 示例输出

```
============================================
      算法设计期末复习 - 算法测试程序      
============================================

========== 测试快速排序 ==========
测试整数数组排序：
排序前: [64, 34, 25, 12, 22, 11, 90]
排序后: [11, 12, 22, 25, 34, 64, 90]
...

========== 测试Dijkstra算法 ==========
从节点 0 到各节点的最短距离:
  到节点 0: 0
  到节点 1: 3
...

============================================
              测试完成！                    
============================================
```

## 更多信息

- 📋 查看 [TODO.md](TODO.md) 查看待实现算法列表

