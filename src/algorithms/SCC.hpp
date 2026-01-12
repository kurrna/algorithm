//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_SCC_HPP
#define ALGORITHM_SCC_HPP

#include <vector>
#include <utility>

class SCC {
public:
    // 使用 Kosaraju 算法返回每个顶点的 SCC id（0..k-1）
    // 输入：顶点数 n（0..n-1）和有向边列表 edges（每个 pair 为 u->v）
    // 输出：长度为 n 的向量 comp，comp[i] 表示顶点 i 所属的 SCC 编号；若 n<=0 返回空向量
    static std::vector<int> solve(int n, const std::vector<std::pair<int,int>>& edges);
private:

};


#endif //ALGORITHM_SCC_HPP
