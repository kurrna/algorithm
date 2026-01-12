//
// Created by Kurna on 2026/1/13.
//

#include "Matching.hpp"
#include <queue>
#include <algorithm>
#include <functional>

Matching::Result Matching::solve(int nL, int nR, const std::vector<std::pair<int,int>>& edges) {
    Result res;
    res.matchL.assign(nL, -1);
    res.matchR.assign(nR, -1);

    // 构建邻接表
    std::vector<std::vector<int>> adj(nL);
    for (const auto &e : edges) {
        int u = e.first;
        int v = e.second;
        if (u >= 0 && u < nL && v >= 0 && v < nR) adj[u].push_back(v);
    }

    // 匈牙利（Kuhn）算法：对每个左侧顶点尝试找增广路
    std::vector<char> color(nL, 0); // DFS 访问标记（L 侧）

    std::function<bool(int)> dfs = [&](int u) -> bool {
        if (color[u]) return false;
        color[u] = 1;
        for (int v : adj[u]) {
            int mu = res.matchR[v];
            // 如果 v 未匹配，或可以通过替换 mu 的匹配找到增广路
            if (mu == -1 || dfs(mu)) {
                res.matchL[u] = v;
                res.matchR[v] = u;
                return true;
            }
        }
        return false;
    };

    int matching = 0;
    for (int u = 0; u < nL; ++u) {
        std::fill(color.begin(), color.end(), 0);
        if (dfs(u)) matching++;
    }

    res.size = matching;
    return res;
}
