//
// Created by Kurna on 2026/1/12.
//

#include "TopoSort.hpp"

#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

// 原有的基于入度的 Kahn 算法实现（保留）
std::vector<int> TopoSort::solve_BFS(int n, const std::vector<std::pair<int,int>>& edges) {
    std::vector<int> empty;
    if (n <= 0) return empty;

    std::vector<std::vector<int>> g(n);
    std::vector<int> indeg(n, 0);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        g[u].push_back(v);
        indeg[v]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) return {}; // 有环
    return order;
}

// 基于 DFS 的拓扑排序实现：包含环检测
std::vector<int> TopoSort::solve_DFS(int n, const std::vector<std::pair<int,int>>& edges) {
    if (n <= 0) return {};

    std::vector<std::vector<int>> g(n);
    for (const auto &e : edges) {
        int u = e.first, v = e.second;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        g[u].push_back(v);
    }

    std::vector<int> visited(n, 0); // 0=unvisited,1=visiting,2=visited
    std::vector<int> order;
    order.reserve(n);
    bool hasCycle = false;

    std::function<void(int)> dfs = [&](int u) {
        if (hasCycle) return;
        visited[u] = 1;
        for (int v : g[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (hasCycle) return;
            } else if (visited[v] == 1) {
                // 回边，发现环
                hasCycle = true;
                return;
            }
        }
        visited[u] = 2;
        order.push_back(u);
    };

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) dfs(i);
        if (hasCycle) return {};
    }

    std::reverse(order.begin(), order.end());
    return order;
}
