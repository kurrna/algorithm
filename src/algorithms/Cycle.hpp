//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_CYCLE_HPP
#define ALGORITHM_CYCLE_HPP

#include <vector>
#include <utility>

class Cycle {
public:
    // 在有向图中寻找任意一个环（simple cycle）。
    // 输入：顶点数 n（顶点编号 0..n-1），边列表 edges（每个 pair 为 u->v）。
    // 输出：若存在环，返回包含环中顶点按顺序的向量（起点可任意），否则返回空向量。
    static std::vector<int> solve(int n, const std::vector<std::pair<int,int>>& edges);

private:

};


#endif //ALGORITHM_CYCLE_HPP
