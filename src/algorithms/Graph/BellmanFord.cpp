//
// Created by Kurna on 2026/1/13.
//

#include "BellmanFord.hpp"
#include <limits>

BellmanFord::Result BellmanFord::solve(int n, const std::vector<Edge>& edges, int s) {
    Result res;
    res.dist.assign(n, std::numeric_limits<long long>::max() / 4);
    res.parent.assign(n, -1);
    res.hasNegativeCycle = false;

    if (n == 0) return res;
    if (s < 0 || s >= n) return res;

    res.dist[s] = 0;

    // 松弛 n-1 次
    for (int iter = 0; iter < n - 1; ++iter) {
        bool updated = false;
        for (const auto &e : edges) {
            if (res.dist[e.u] < std::numeric_limits<long long>::max() / 8) {
                long long nd = res.dist[e.u] + static_cast<long long>(e.w);
                if (nd < res.dist[e.v]) {
                    res.dist[e.v] = nd;
                    res.parent[e.v] = e.u;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }

    // 检测负权回路
    for (const auto &e : edges) {
        if (res.dist[e.u] < std::numeric_limits<long long>::max() / 8) {
            long long nd = res.dist[e.u] + static_cast<long long>(e.w);
            if (nd < res.dist[e.v]) {
                res.hasNegativeCycle = true;
                break;
            }
        }
    }

    return res;
}
