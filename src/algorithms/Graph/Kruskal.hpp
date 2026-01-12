//
// Created by Kurna on 2026/1/13.
//

#ifndef ALGORITHM_KRUSKAL_HPP
#define ALGORITHM_KRUSKAL_HPP

#include <vector>

class Kruskal {
public:
    // 无向带权边
    struct Edge {
        int u;
        int v;
        int w;
        Edge(int a, int b, int c) : u(a), v(b), w(c) {}
    };

    // 运行 Kruskal 算法，返回 parent 数组（parent[root] = -1）
    // 参数：顶点数 n（0-based），边列表
    static std::vector<int> solve(int n, const std::vector<Edge>& edges);

private:

};


#endif //ALGORITHM_KRUSKAL_HPP
