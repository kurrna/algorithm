//
// Created by Kurna on 2026/1/11.
//

#include "MatrixChainMul.hpp"
#include <climits>

// 定义静态成员
std::vector<std::vector<int>> MatrixChainMul::s;

std::vector<int> MatrixChainMul::solve(const std::vector<int>& p) {
    if (p.size() < 2) return {};
    int n = static_cast<int>(p.size()) - 1; // 矩阵个数

    // dp 使用 1..n 的索引
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, 0));
    s.assign(n + 1, std::vector<int>(n + 1, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j] + static_cast<long long>(p[i - 1]) * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    long long ans = dp[1][n];
    return {static_cast<int>(ans)};
}
