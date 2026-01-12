//
// Created by Kurna on 2026/1/12.
//

#include "SCC.hpp"
#include <vector>
#include <functional>

std::vector<int> SCC::solve(int n, const std::vector<std::pair<int,int>>& edges) {
    if (n <= 0) return {};

    std::vector<std::vector<int>> g(n), gr(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        g[u].push_back(v);
        gr[v].push_back(u); // reverse edge
    }

    std::vector<char> visited(n, 0);
    std::vector<int> order;
    order.reserve(n);

    std::function<void(int)> dfs1 = [&](int u) {
        visited[u] = 1;
        for (int v : gr[u]) if (!visited[v]) dfs1(v);
        order.push_back(u);
    };

    for (int i = 0; i < n; ++i) if (!visited[i]) dfs1(i);

    // second pass on original graph g in reverse finishing order
    std::vector<int> comp(n, -1);
    int cid = 0;
    std::function<void(int)> dfs2 = [&](int u) {
        comp[u] = cid;
        for (int v : g[u]) if (comp[v] == -1) dfs2(v);
    };

    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int u = order[i];
        if (comp[u] == -1) {
            dfs2(u);
            ++cid;
        }
    }

    return comp;
}
