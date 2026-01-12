//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_PRIM_HPP
#define ALGORITHM_PRIM_HPP

#include <vector>

class Prim {
public:
    // 边结构（目标节点，权重）
    struct Edge {
        int to;
        int weight;
        Edge(int t, int w) : to(t), weight(w) {}
    };

    // 图的邻接表表示
    using Graph = std::vector<std::vector<Edge>>;

    // 运行 Prim 算法，返回 parent 数组（parent[root] = -1）
    // 若图不连通，未被访问到的节点 parent 保持为 -1
    static std::vector<int> solve(const Graph &graph, int start = 0);

private:
    
};


#endif //ALGORITHM_PRIM_HPP
