//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_BFS_HPP
#define ALGORITHM_BFS_HPP

#include <vector>
#include <queue>

class BFS {
public:
    // 使用邻接表表示图（0-based 顶点编号）
    // 提供简单的 BFS 接口：给定顶点数 n、边列表和起点 s，返回遍历序列或距离等。
    struct BFSResult {
        std::vector<int> order; // BFS 访问顺序
        std::vector<int> dist; // 到起点的距离，未到达为 -1
        std::vector<int> parent; // BFS 树的父节点，根的 parent 为 -1
    };

    // edges: each pair is (u, v)。默认是有向图；若 undirected 为 true，则添加双向边。
    static BFSResult solve(int n, const std::vector<std::pair<int, int>> &edges, int s);
};

#endif // ALGORITHM_BFS_HPP
