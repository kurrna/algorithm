//
// Created by Kurna on 2026/1/13.
//

#ifndef ALGORITHM_MAXFLOW_HPP
#define ALGORITHM_MAXFLOW_HPP

#include <vector>

class MaxFlow {
public:
    struct Edge {
        int u, v;
        long long cap;
        Edge(int a, int b, long long c) : u(a), v(b), cap(c) {}
    };

    // 输入：顶点数 n，边表（有向带容量），源点 s，汇点 t
    // 返回最大流 value
    static long long solve(int n, const std::vector<Edge>& edges, int s, int t);

private:

};


#endif //ALGORITHM_MAXFLOW_HPP
