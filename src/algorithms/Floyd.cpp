//
// Created by Kurna on 2026/1/13.
//

#include "Floyd.hpp"
#include <vector>

std::vector<std::vector<long long>> Floyd::solve(const std::vector<std::vector<long long>>& adj) {
    int n = static_cast<int>(adj.size());
    std::vector<std::vector<long long>> dist = adj; // 复制

    // 若传入为空或不为 n x n 的方阵，则返回空矩阵
    for (int i = 0; i < n; ++i) {
        if ((int)dist[i].size() != n) return {};
    }

    // 标准 Floyd–Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] >= INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] >= INF) continue;
                long long nd = dist[i][k] + dist[k][j];
                if (nd < dist[i][j]) dist[i][j] = nd;
            }
        }
    }

    return dist;
}
