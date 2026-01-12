//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_TOPOSORT_HPP
#define ALGORITHM_TOPOSORT_HPP

#include <vector>
#include <utility>

class TopoSort {
public:
    // 对有向图进行拓扑排序。
    // 输入：顶点数 n（0..n-1）和有向边列表 edges（每个 pair 为 u->v）。
    // 输出：如果存在拓扑序，返回一个长度为 n 的排列；如果存在环，返回空向量。
    static std::vector<int> solve_BFS(int n, const std::vector<std::pair<int,int>>& edges);
    static std::vector<int> solve_DFS(int n, const std::vector<std::pair<int,int>>& edges);
private:

};


#endif //ALGORITHM_TOPOSORT_HPP
