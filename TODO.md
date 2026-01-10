# 待实现/已实现算法清单（按课程与拓展分类）

本文件将实现任务按两部分分类：

- 2025 秋 - 算法设计（课程部分）：按照课程大纲列出本学期核心算法（优先实现）
- 拓展部分：课程之外或进阶的算法与数据结构（可选/进阶实现）

---

# 2025 秋 - 算法设计（课程部分）

以下条目基于[课程讲义](./lists.txt)，按讲次/主题组织，带复选框以便跟踪进度。

## 排序与分治
- [x] [归并排序（MergeSort）](./src/algorithms/MergeSort.cpp)
- [x] [快速排序（QuickSort）](./src/algorithms/QuickSort.cpp)
- [ ] 堆排序（HeapSort）
- [x] [选择问题（Selection）](./src/algorithms/SelectionProblem.cpp)
- [x] [分治中的求解递推式（Recurrences / Master Theorem）](./notes.md)

## 子数组 / 分治应用
- [x] [最大子数组问题（Maximum Contiguous Subarray）](./src/algorithms/MaximumContiguousSubarray.cpp)
- [ ] 最大子数组（进阶/第二讲，MaxSubArrayII）
- [x] [计数逆序对（Counting Inversion）](./src/algorithms/CountingInversion.cpp)

## 数学与代数工具
- [x] *多项式乘法（Polynomial Multiplication）
- [ ] 矩阵乘法与优化（Matrix Multiplication / 矩阵链乘法）

## 贪心与动态规划基础
- [ ] 活动选择问题（Activity Selection）
- [ ] 霍夫曼编码（Huffman Coding）
- [ ] 分数背包（Fractional Knapsack）
- [ ] 0-1 背包（0-1 Knapsack）
- [ ] 编辑距离（Edit Distance）

## 字符串与检索
- [ ] 最长公共子序列（LCS）
- [ ] 最长公共子串（Longest Common Substring）

## 图算法（核心）
- [ ] 图基础（Graph 表示与基本性质）
- [ ] 广度优先搜索（BFS）
- [ ] 深度优先搜索（DFS）
- [ ] 有向图的 DFS 与强连通分量（Directed DFS / SCC）
- [ ] 拓扑排序（Topological Sort）
- [ ] 图中的环检测（Cycle detection）

## 最短路径与最小生成树
- [ ] Dijkstra 最短路（Dijkstra）
- [ ] Bellman-Ford（Bellman-Ford）
- [ ] Floyd-Warshall（All-pairs shortest paths）
- [ ] Prim 最小生成树（Prim）
- [ ] Kruskal 最小生成树（Kruskal）

## 其他核心主题
- [ ] 布尔与复杂度（P vs NP / NP-Complete）
- [ ] 最终复习/综合题目（Final Review）

---

# 拓展部分（进阶与数据结构）

## 数据结构
- [ ] 二叉搜索树（BST）
- [ ] AVL 树
- [ ] 红黑树（Red-Black Tree）
- [ ] 并查集（Union-Find）
- [ ] 线段树（Segment Tree）
- [ ] 字典树（Trie）
- [ ] 堆（实现细节与优先队列进阶）

## 算法进阶
- [ ] KMP 字符串匹配（KMP）
- [ ] Boyer-Moore
- [ ] Rabin-Karp
- [ ] 回溯与搜索技巧（例如 N 皇后）
- [ ] 位运算技巧、双指针技巧
- [ ] 匈牙利/二分匹配与一般匹配（Matching）
- [ ] 最大流（Max Flow / Ford-Fulkerson / Edmonds-Karp / Dinic）

## 其他算法
- [x] [插入排序](./src/algorithms/InsertionSort.cpp)

