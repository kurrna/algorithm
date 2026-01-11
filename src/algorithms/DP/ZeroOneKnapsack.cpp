//
// Created by Kurna on 2026/1/11.
//

#include "../ZeroOneKnapsack.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

int ZeroOneKnapsack::solve(const std::vector<int>& volumes, const std::vector<int>& prices, int C) {
    if (C <= 0) return 0;
    if (volumes.size() != prices.size()) {
        throw std::invalid_argument("volumes and prices must have the same length");
    }
    size_t n = volumes.size();
    if (n == 0) return 0;

    std::vector<int> dp(C + 1, 0);
    for (size_t i = 0; i < n; ++i) {
        int vol = volumes[i];
        int val = prices[i];
        if (vol > C) continue;  // 不能放入背包
        for (int w = C; w >= vol; --w) {
            dp[w] = std::max(dp[w], dp[w - vol] + val);
        }
    }
    return dp[C];
}