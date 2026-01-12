//
// Created by Kurna on 2026/1/13.
//

#include "MaxFlow.hpp"
#include <vector>
#include <algorithm>
#include <limits>
#include <functional>

struct EdgeInternal {
    int to;
    long long cap;
    int rev; // 反向边在 edges 列表的位置
    EdgeInternal(int _to, long long _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};

long long MaxFlow::solve(int n, const std::vector<Edge>& edges, int s, int t) {
    // 构建邻接的残量图
    std::vector<std::vector<EdgeInternal>> g(n);
    auto addEdge = [&](int u, int v, long long c){
        EdgeInternal a(v, c, (int)g[v].size());
        EdgeInternal b(u, 0, (int)g[u].size());
        g[u].push_back(a);
        g[v].push_back(b);
    };

    for (const auto &e : edges) addEdge(e.u, e.v, e.cap);

    long long flow = 0;
    const long long INF = std::numeric_limits<long long>::max() / 8;

    while (true) {
        std::vector<int> parent_v(n, -1), parent_eidx(n, -1);
        std::vector<char> visited(n, 0);
        // 使用显式栈的 DFS 来寻找一条从 s 到 t 的增广路径
        std::function<bool(int)> dfs;
        dfs = [&](int u)->bool{
            if (u == t) return true;
            visited[u] = 1;
            for (int i = 0; i < (int)g[u].size(); ++i) {
                auto &ed = g[u][i];
                if (ed.cap > 0 && !visited[ed.to]) {
                    parent_v[ed.to] = u;
                    parent_eidx[ed.to] = i;
                    if (dfs(ed.to)) return true;
                }
            }
            return false;
        };

        if (!dfs(s)) break; // 无增广路径

        // 反向追踪找到的路径，求最小剩余容量
        long long aug = INF;
        int v = t;
        while (v != s) {
            int u = parent_v[v];
            int ei = parent_eidx[v];
            aug = std::min(aug, g[u][ei].cap);
            v = u;
        }

        // 更新残量图
        v = t;
        while (v != s) {
            int u = parent_v[v];
            int ei = parent_eidx[v];
            auto &fwd = g[u][ei];
            auto &rev = g[v][fwd.rev];
            fwd.cap -= aug;
            rev.cap += aug;
            v = u;
        }

        flow += aug;
    }

    return flow;
}
