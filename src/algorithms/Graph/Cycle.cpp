//
// Created by Kurna on 2026/1/12.
//

#include "Cycle.hpp"
#include <vector>
#include <functional>

std::vector<int> Cycle::solve(int n, const std::vector<std::pair<int,int>>& edges) {
    std::vector<int> empty;
    if (n <= 0) return empty;

    std::vector<std::vector<int>> g(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        g[u].push_back(v);
    }

    // 0 = unvisited, 1 = visiting, 2 = visited
    std::vector<int> color(n, 0);
    std::vector<int> parent(n, -1);
    std::vector<int> cycle;
    bool found = false;

    std::function<void(int)> dfs = [&](int u){
        if (found) return;
        color[u] = 1;
        for (int v : g[u]) {
            if (found) return;
            if (color[v] == 0) {
                parent[v] = u;
                dfs(v);
            } else if (color[v] == 1) {
                // 找到环，从 u 回溯到 v
                found = true;
                int cur = u;
                cycle.push_back(v); // 将环的起点也加入
                while (cur != v && cur != -1) {
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                // cycle currently contains [v, u, ..., v?] maybe reverse order; make it v..u
                std::reverse(cycle.begin(), cycle.end());
                return;
            }
        }
        color[u] = 2;
    };

    for (int i = 0; i < n && !found; ++i) {
        if (color[i] == 0) dfs(i);
    }

    if (!found) return empty;
    return cycle;
}
