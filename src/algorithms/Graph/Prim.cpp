//
// Created by Kurna on 2026/1/12.
//

#include "Prim.hpp"
#include <queue>
#include <vector>
#include <limits>

std::vector<int> Prim::solve(const Graph &graph, int start) {
    int n = static_cast<int>(graph.size());
    std::vector<int> parent(n, -1);
    if (n == 0) return parent;

    // dist[u] 表示当前 V_A 到 u 的最小横跨边权重
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist(n, INF);
    std::vector<bool> inMST(n, false);

    // min-heap of (dist, vertex)
    using P = std::pair<int,int>;
    std::priority_queue<P, std::vector<P>, std::greater<>> pq;

    // 初始化起点
    dist[start] = 0;
    parent[start] = -1;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (inMST[u]) continue; // 已加入 MST
        inMST[u] = true;

        // 访问所有邻边，尝试更新横跨边
        for (const auto &e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            if (!inMST[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
                // DecreaseKey
                pq.emplace(dist[v], v);
            }
        }
    }

    return parent;
}
