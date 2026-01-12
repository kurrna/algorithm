//
// Created by Kurna on 2026/1/13.
//

#ifndef ALGORITHM_MATCHING_HPP
#define ALGORITHM_MATCHING_HPP

#include <vector>

class Matching {
public:
    struct Result {
        std::vector<int> matchL; // matchL[u] = v 或 -1
        std::vector<int> matchR; // matchR[v] = u 或 -1
        int size = 0; // 匹配大小
    };

    // nL: 左侧顶点数，nR: 右侧顶点数，edges: (u in [0,nL), v in [0,nR))
    static Result solve(int nL, int nR, const std::vector<std::pair<int,int>>& edges);

private:

};


#endif //ALGORITHM_MATCHING_HPP
