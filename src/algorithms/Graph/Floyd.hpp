//
// Created by Kurna on 2026/1/13.
//

#ifndef ALGORITHM_FLOYD_HPP
#define ALGORITHM_FLOYD_HPP

#include <vector>

class Floyd {
public:
    // 使用 long long 表示权重，INF 表示无穷大
    static constexpr long long INF = (long long)1e15;

    // 输入：邻接矩阵（权重，无法直接连通的位置用 INF 表示）
    // 输出：所有点对最短路径距离矩阵（dist[i][j]）
    static std::vector<std::vector<long long>> solve(const std::vector<std::vector<long long>>& adj);

private:

};


#endif //ALGORITHM_FLOYD_HPP
