## 25秋算法设计复习笔记

#### Lecture01_Abstact

- 算法：给定计算问题，算法是一系列良定义的计算步骤。

- [插入排序](./src/algorithms/InsertionSort.cpp)算法（稳定排序）
  
  - 将数组待排序元素依次插入到已排序部分，使已排序部分保持升序的性质
  - 时间复杂度：$O(n^2)$
  - 空间复杂度：$O(1)$
  
- [选择排序](./src/algorithms/SelectionSort.cpp)算法（不稳定排序）
  
  - 第一次遍历找最小元素；第二次遍历找次小元素；……；第n次遍历找第n小元素
  - 时间复杂度：$O(n^2)$
  - 空间复杂度：$O(1)$
  
- 算法的性质：有穷性、确定性、可行性

- 时间复杂度：渐进分析最坏情况（确定上界）

  | 渐进记号              | 名称       |
  | --------------------- | ---------- |
  | $T(n) = \Theta(g(n))$ | 渐近紧确界 |
  | $T(n) = O(g(n))$      | 渐近上界   |
  | $T(n) = \Omega(g(n))$ | 渐进下界   |
  
- $T(n) = \Theta(g(n))$等价于$T(n) = O(g(n))$且$T(n) = \Omega(g(n))$，故算法的时间复杂度通常使用用渐近记号$O$表示。
  
  ```mermaid
  flowchart TB
      A[算法设计与分析] --> B[分而治之篇]
      A --> C[动态规划篇]
      A --> D[贪心策略篇]
      A --> E[图算法篇]
  
      subgraph B[分而治之篇]
          B1[归并排序]
          B2[递归式求解]
          B3[最大子数组I]
          B4[逆序对计数]
          B5[快速排序]
          B6[次序选择]
      end
  
      subgraph C[动态规划篇]
          C1[0-1背包]
          C2[最大子数组II]
          C3[最长公共子序列]
          C4[最长公共子串]
          C5[编辑距离]
          C6[钢条切割]
          C7[矩阵链乘法]
      end
  
      subgraph D[贪心策略篇]
          D1[部分背包]
          D2[霍夫曼编码]
          D3[任务调度]
          D4[活动选择]
          D5[最小生成树]
          D6[单源最短路径]
      end
  
      subgraph E[图算法篇]
          E1[广度优先搜索]
          E2[深度优先搜索]
          E3[环路存在性判断]
          E4[拓扑排序]
          E5[强连通分量]
          E6[全点对最短路径]
          E7[二分图匹配]
      end
  ```
  

----

### 一、分而治之篇

#### Lecture02_MergeSort & Lecture03_Solving_Recurrences

- [归并排序](src/algorithms/DevideConquer/MergeSort.cpp)算法（稳定排序）

  - 基于分治，拆$\log_2(n)$次，合并时从左到右扫描，需要额外空间存储合并过程
  - 时间复杂度：$O(n\log(n))$
  - 空间复杂度：$O(n)$

- 递归式复杂度分析：

  - $T(n)$：完成`MergeSort(A, 1, n)`（递归式算法）的运行时间，$T(n) = 2T(n/2) + O(n)$

  - 递归树法：共$log_2(n) + 1$层，每一层的代价为$O(n)$

  - 代入法：猜测$T(n) = \Theta(n\log(n))$，使用数学归纳法证明

  - **主定理法**：

    - 对于形如$T(n) = aT(\frac{n}{b}) + f(n)$的递归式，每层共a个分支，以因子b速度下降，层数$\log_b(n) + 1$，其叶节点代价之和为$a^{log_b(n)} * 1$，即$n_{log_b(a)}$。

    - 故$T(n) = \Theta(n^{\log_b(a)}) + \sum_{i=0}^{\log_b(n-1)}a^if(\frac{n}{b^i})$。

    - 根据根节点代价$f(n)$与叶节点代价之和$n_{log_b(a)}$的大小

      | 运行时间                          | 代价比较                             |
    | --------------------------------- | ------------------------------------ |
      | $T(n) = \Theta(f(n))$             | $f(n)=\Omega(n^{log_b(a+\epsilon)})$ |
    | $T(n)=\Theta(n^{log_b(a)}log(n))$ | $f(n)=\Theta(n^{log_b(a)})$          |
      | $T(n)=\Theta(n^{log_b(a)})$       | $f(n) = O(n^{log_b(a-\epsilon)})$    |
  
    - 若$f(n) = n^k$，则有如下简化形式：
    
      | 运行时间                        | 代价比较                           |
      | ------------------------------- | ---------------------------------- |
      | $T(n) = \Theta(n^k)$           | $k > log_b(a)$ |
      | $T(n)=\Theta(n^klog(n))$ | $k = log_b(a)$ |
      | $T(n)=\Theta(n^{log_b(a)})$       | $k < log_b(a)$ |

    - 另有主定理扩展形式：对于$f(n)=\Theta(n^{log_b(a)}log^k(n))$

      | 运行时间                        | 代价比较                           |
      | ------------------------------- | ---------------------------------- |
      | $T(n)=\Theta(n^{log_b(a)}log^{k+1}(n))$ | $k > -1$ |
      | $T(n)=\Theta(n^{log_b(a)}loglog(n))$ | $k = -1$ |
      | $T(n)=\Theta(n^{log_b(a)})$ | $k < -1$ |

---

#### Lecture04_Maximum_Contiguous_Subarray

- [最大子数组](src/algorithms/DevideConquer/MaximumContiguousSubarray.cpp)：最大子数组之和=max(以A[mid]结尾的最大子数组之和+以A[mid+1]开头的最大子数组之和，LEFT部分最大子数组，RIGHT部分最大子数组)
  - **分治法**：$O(n\log(n))$
  - 空间复杂度：$O(1)$
  - 【更快的算法】动态规划：$O(n)$

---

#### Lecture05_Counting_Inversion

- [逆序对计数](./src/algorithms/Counting_Inversion.cpp)：逆序对总数[1, n] = max(逆序对总数[1, mid], 逆序对总数[mid+1, n], 跨越mid的逆序对数目)，
- 计算跨越mid的逆序对数目，在合并时对数组进行归并排序的同时计算逆序对数目。
  - 分治法：$O(n\log(n))$
  - 空间复杂度：$O(n)$

---

#### Lecture06_Polynomial_Multiplication

- 多项式乘法：将系数数组A和B根据指数$\frac{n}{2}$的大小关系分别划分为两个子数组$A_0$，$A_1 * x^\frac{n}{2}$和$B_0$，$B_1 * \frac{n}{2}$，递归三次分别求解$A_0B_0$，$(A_0 + A_1)(B_0 + B_1)$，$A_1B_1$。这样两个交叉项可由三个结果计算出来。
  - 改进的分治法：$O(n^{\log(3)})$
  - 【更快的算法】快速傅里叶变换：$O(n\log(n))$

---

#### Lecture07_Quicksort

- [快速排序](src/algorithms/DevideConquer/QuickSort.cpp)算法（不稳定排序）
  - 与归并排序相比，侧重分解，并且不需要额外的空间且缓存友好。使用最简单的优化方式：随机选取主元。
  - 最好情况：$O(nlog(n))$
  - 最坏情况：$O(n^2)$
  - 随机主元期望时间复杂度：$O(nlog(n))$

---

#### Lecture08_Selection_Problem

- [次序选择问题](src/algorithms/DevideConquer/SelectionProblem.cpp)：求数组中第k小的元素，不必对所有元素排序，选取一个主元进行位置划分后左边的元素有$pivotIdx - start$个，若$k-1 < pivotIdx - start + 1$，则数组第k小元素在左边，若大于则在右边。
  - 最好情况：$O(n)$
  - 最坏情况：$O(n^2)$
  - 随机主元期望时间复杂度：$O(n)$

---

#### Lecture09_HeapSort_LowerBound

- 优先队列：支持将新元素插入队列Insert和将队列中最小元素出队Extract_Min
- (二叉)堆：支持Insert和Extract-Min的时间复杂度都为$O(log(n))$
  - 相当于一棵完全二叉树，包含n个节点的堆的高度为$log(n)$
  - 小根堆(最小堆)：父节点的值不大于其左右孩子节点的值
  - 使用数组实现：对于每个元素$a[i]$，其左孩子下标$2i+1$，右孩子下标$2i + 2$，父节点下标为$\lfloor \frac{n}{2} \rfloor$
  - 插入Insert：若父节点大于当前节点则不断向上冒泡直到满足最小堆的有序性
  - 最小值出队Extract-Min：直接移除根节点，将最后一个节点复制道跟节点，不断向下冒泡直到满足最小堆的有序性（与值较小的孩子节点进行交换）
- [堆排序](src/algorithms/DevideConquer/HeapSort.cpp)算法（不稳定排序）
  - 建立一个有n个节点的二叉堆（更有效的建堆方法$O(n)$），执行n次Extract-Min操作。
  - 时间复杂度：$O(nlog(n))$
  - 空间复杂度：$O(1)$
- 排序算法的下界
  - 定理：任何**基于比较的**排序算法其时间复杂度的下界均为$\Omega(n\log(n))$（使用决策树模型证明）
  - 推论：堆排序以及归并排序是渐进最优的基于比较的排序算法
- [计数排序](./src/algorithms/CountingSort.cpp)算法（稳定排序）
  - 对于元素x，确定小于x的元素的数量i，将x放在输出数组的i+1位置
  - 时间复杂度：$O(n + k)$
  - 空间复杂度：$O(n + k)$

---

### 二、动态规划篇

#### Lecture10_0-1_Knapsack

- [0-1背包问题](./src/algorithms/ZeroOneKnapsack.cpp)
  - 输入：n个商品组成集合O，每个商品有两个属性$v_i$和$p_i$，分别表示体积和价格；背包容量为C
  - 输出：求解一个商品子集，总价值最高且容量小于C
  - 蛮力枚举：$O(2^n)$
  - 带缓存递归：自顶向下，在递归过程求解
  - 递推求解：自底向上，$O(nC)$
- 动态规划一般步骤
  - 问题分析：$P[n, C]$：前$n$个商品可选、背包剩余容量为$C$时的最大总价格
  - 递推关系：$P[i, c] = max\{P[i - 1, c], P[i - 1, c - v_i] + p_i\}$
    - 分析最优子结构：问题的最优解由相关子问题最优解组合而成，子问题可以独立求解
  - 自底向上：初始化$P[i, 0] = 0, P[0, c] = 0$，依次求解问题
  - 决策过程：回溯追踪最优方案，使用$Rec[i, c]$记录决策过程

---

#### Lecture11_MaxSubArrayII

- [最大子数组](./src/algorithms/MaxSubArray.cpp)（动态规划）
  - 时间复杂度：$O(n)$

---

#### Lecture12_Longest_Common_Sequence

- [最长公共子序列问题](./src/algorithms/LongestCommonSequence.cpp)
  - 给定两个序列X和Y，求其最大公共子序列（即去掉任意多个元素剩下的部分）
  - 使用追踪数组Rec记录这一步是"L", "U"还是"LU"
  - 时间复杂度：$O(n * m)$

---

#### Lecture13_Longest_Common_Substring

- [最长公共子串问题](./src/algorithms/LongestCommonSubstring.cpp)
  - 与最大公共子序列不同的是不需要求解子问题
  - 时间复杂度：$O(n * m)$

---

#### Lecture14_MED

- [编辑距离问题](./src/algorithms/MinimumEditDistance.cpp)
  - 使用$Rec[i,j]$保存子问题来源，上侧"U"则操作为删除s[i]，左侧"L"则操作为插入t[j]，对角线"D"则为用t[j]替换s[i]。最后根据数组Rec输出最少编辑操作。
  - 时间复杂度：$O(n * m)$

---

#### Lecture15_RodCutting

- [钢条切割问题](./src/algorithms/RodCutting.cpp)
  - 输入钢条价格表$p[1\ldots n]$，输出最大收益$C[n]$与钢条切割方案
  - 使用rec[i]记录长度为i的钢条切割的第一段应该是多少
  - 时间复杂度：$O(n^2)$

---

#### Lecture16_MatrixMul

- [矩阵链乘法（Matrix Chain Mul）](./src/algorithms/MatrixChainMul.cpp)
  - 输入：n个矩阵组成的矩阵链；矩阵链$U_{1\ldots n}$对应的维度数分别为$p_0, p_1, \ldots ,p_n$，$U_i$的维度为$p_{i-1} * p_i$
  - 输出：找到一种加括号的方式，以确定矩阵链乘法的计算顺序，使得最小化矩阵链标量乘法的次数
  - $dp[i, j] = dp[i, k] + dp[k + 1, j] + p_{i-1}p_kp_j$，$dp[i, j]$表示计算矩阵链$U_{i\ldots j}$所需标量乘法的最小次数
  - 时间复杂度：$O(n^3)$

---

​	
