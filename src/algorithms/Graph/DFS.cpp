//
// Created by Kurna on 2026/1/12.
//

#include "DFS.hpp"
#include <vector>
#include <functional>

DFS::DFSResult DFS::solve(int n, const std::vector<std::pair<int,int>>& edges, int s, bool undirected) {
    DFSResult res;
    res.order.clear();
    res.depths.assign(n, -1);
    res.parents.assign(n, -1);

    if (n <= 0) return res;

    std::vector<std::vector<int>> g(n);
    for (const auto &e : edges) {
        int u = e.first;
        int v = e.second;
        if (u < 0 || u >= n || v < 0 || v >= n) continue; // 忽略无效边
        g[u].push_back(v);
        if (undirected) g[v].push_back(u);
    }

    std::vector<char> visited(n, 0);
    std::function<void(int,int)> dfs = [&](int u, int depth) {
        visited[u] = 1;
        res.order.push_back(u);
        res.depths[u] = depth;
        for (int v : g[u]) {
            if (!visited[v]) {
                res.parents[v] = u;
                dfs(v, depth + 1);
            }
        }
    };

    if (s < 0 || s >= n) return res; // 起点非法
    res.parents[s] = -1;
    dfs(s, 0);

    return res;
}