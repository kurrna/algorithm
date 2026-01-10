//
// Created by Kurna on 2026/1/11.
//

#ifndef ALGORITHM_ZEROONEKNAPSACK_HPP
#define ALGORITHM_ZEROONEKNAPSACK_HPP

#include <vector>

class ZeroOneKnapsack {
public:
    // 使用 0-1 背包的 1D DP 实现
    // volumes: 每件物品体积
    // prices: 每件物品价值
    // C: 背包最大容量
    // 返回：在容量 C 下可取得的最大总价值（int）
    static int solve(const std::vector<int>& volumes, const std::vector<int>& prices, int C);
};

#endif //ALGORITHM_ZEROONEKNAPSACK_HPP
