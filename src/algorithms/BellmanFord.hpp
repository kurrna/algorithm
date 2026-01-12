//
// Created by Kurna on 2026/1/13.
//

#ifndef ALGORITHM_BELLMANFORD_HPP
#define ALGORITHM_BELLMANFORD_HPP

#include <vector>

class BellmanFord {
public:
    struct Edge {
        int u;
        int v;
        int w;
        Edge(int a, int b, int c) : u(a), v(b), w(c) {}
    };

    struct Result {
        std::vector<long long> dist; // 最短距离
        std::vector<int> parent;     // 最短路径树的前驱
        bool hasNegativeCycle = false; // 是否存在负权回路
    };

    // n: 顶点数（0-based），edges: 边表，s: 源点
    static Result solve(int n, const std::vector<Edge>& edges, int s);

private:

};


#endif //ALGORITHM_BELLMANFORD_HPP
