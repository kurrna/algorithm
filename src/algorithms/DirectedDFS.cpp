#include "DirectedDFS.hpp"
#include <vector>
#include <functional>

DirectedDFS::DFSResult DirectedDFS::solve(int n, const std::vector<std::pair<int,int>>& edges, int s) {
    DFSResult res;
    res.order.clear();
    res.depths.assign(n, -1);
    res.parents.assign(n, -1);

    if (n <= 0) return res;

    std::vector<std::vector<int>> g(n);
    for (const auto &[fst, snd] : edges) {
        int u = fst;
        int v = snd;
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        g[u].push_back(v);
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

    if (s < 0 || s >= n) return res;
    res.parents[s] = -1;
    dfs(s, 0);

    return res;
}

