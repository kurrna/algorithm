#ifndef ALGORITHM_DIRECTEDDFS_HPP
#define ALGORITHM_DIRECTEDDFS_HPP

#include <vector>
#include <utility>

class DirectedDFS {
public:
    struct DFSResult {
        std::vector<int> order;   // 访问顺序
        std::vector<int> depths;  // 每个节点从起点的深度，未访问为 -1
        std::vector<int> parents; // 每个节点的父节点，根的 parent 为 -1
    };

    // 使用边列表表示有向图：edges 中的 pair(u,v) 表示 u -> v
    // n 为顶点数，s 为起点
    static DFSResult solve(int n, const std::vector<std::pair<int,int>>& edges, int s);
};

#endif //ALGORITHM_DIRECTEDDFS_HPP

