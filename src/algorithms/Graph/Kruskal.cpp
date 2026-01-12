//
// Created by Kurna on 2026/1/13.
//

#include "Kruskal.hpp"
#include <algorithm>

// 并查集实现
namespace {
    struct DSU {
        std::vector<int> p;
        std::vector<int> r;
        DSU(int n): p(n), r(n,0) { for (int i=0;i<n;i++) p[i]=i; }
        int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
        bool unite(int a,int b){
            a=find(a); b=find(b); if (a==b) return false;
            if (r[a]<r[b]) p[a]=b; else if (r[b]<r[a]) p[b]=a; else { p[b]=a; r[a]++; }
            return true;
        }
    };
}

std::vector<int> Kruskal::solve(int n, const std::vector<Edge>& edges) {
    std::vector<int> parent(n, -1);
    if (n == 0) return parent;

    // 按权重升序排序边
    std::vector<Edge> es = edges;
    std::sort(es.begin(), es.end(), [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });

    DSU dsu(n);
    int added = 0;
    for (const auto &e : es) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            // 若某一端 parent 未设置则记录父节点
            if (parent[e.v] == -1 && e.v != 0) parent[e.v] = e.u;
            else if (parent[e.u] == -1 && e.u != 0) parent[e.u] = e.v;

            added++;
            if (added == n-1) break;
        }
    }

    // 确保至少保留一个根（使 parent[root] == -1），若所有节点 parent 都被设置则将节点0重设为根
    bool hasRoot = false;
    for (int i=0;i<n;i++) if (parent[i] == -1) { hasRoot = true; break; }
    if (!hasRoot && n>0) parent[0] = -1;

    return parent;
}
