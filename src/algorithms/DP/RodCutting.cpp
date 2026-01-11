//
// Created by Kurna on 2026/1/11.
//

#include "../RodCutting.hpp"

std::vector<int> RodCutting::rec;

int RodCutting::solve(std::vector<int> &vec) {
    int n = static_cast<int>(vec.size()) - 1;
    rec.resize(n + 1, 0);
    std::vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int maxVal = -1;
        for (int j = 1; j <= i; ++j) {
            if (maxVal < vec[j] + dp[i - j]) {
                maxVal = vec[j] + dp[i - j];
                // 记录长度为 i 的钢条最佳切割的第一段长度 j
                rec[i] = j;
            }
        }
        dp[i] = maxVal;
    }
    return dp[n];
}