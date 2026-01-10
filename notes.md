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

#### Lecture02_MergeSort & Lecture03_Solving_Recurrences

- [归并排序](./src/algorithms/MergeSort.cpp)算法（稳定排序）

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

- [最大子数组](./src/algorithms/MaximumContiguousSubarray.cpp)：最大子数组之和=max(以A[mid]结尾的最大子数组之和+以A[mid+1]开头的最大子数组之和，LEFT部分最大子数组，RIGHT部分最大子数组)
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

- [快速排序](./src/algorithms/QuickSort.cpp)：与归并排序相比，侧重分解，并且不需要额外的空间且缓存友好。使用最简单的优化方式：随机选取主元。
  - 最好情况：$O(nlog(n))$
  - 最坏情况：$O(n^2)$
  - 随机主元法期望时间复杂度：$O(nlog(n))$

---

#### Lecture08_Selection_Problem

- 
