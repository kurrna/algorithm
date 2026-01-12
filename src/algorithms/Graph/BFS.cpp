//
// Created by Kurna on 2026/1/12.
//

#include "BFS.hpp"
#include <vector>
#include <queue>

BFS::BFSResult BFS::solve(int n, const std::vector<std::pair<int,int>>& edges, int s) {
    BFSResult res;
    res.order.clear();
    res.dist.assign(n, -1);
    res.parent.assign(n, -1);

    std::vector<std::vector<int>> g(n);
    for (const auto &[fst, snd] : edges) {
        int u = fst;
        int v = snd;
        g[u].push_back(v);
    }

    if (s < 0 || s >= n) return res; // 起点非法，返回空结果

    std::queue<int> q;
    q.push(s);
    res.dist[s] = 0;
    res.parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.order.push_back(u);
        for (int v : g[u]) {
            if (res.dist[v] == -1) {
                res.dist[v] = res.dist[u] + 1;
                res.parent[v] = u;
                q.push(v);
            }
        }
    }

    return res;
}
