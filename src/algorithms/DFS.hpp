//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_DFS_HPP
#define ALGORITHM_DFS_HPP

#include <vector>
#include <utility>

class DFS {
public:
    struct DFSResult {
        std::vector<int> order;
        std::vector<int> depths;
        std::vector<int> parents;
    };

    // 使用边列表表示图（每个 pair 为 (u, v)），默认无向图。
    static DFSResult solve(int n, const std::vector<std::pair<int,int>>& edges, int s, bool undirected = true);
private:

};


#endif //ALGORITHM_DFS_HPP
