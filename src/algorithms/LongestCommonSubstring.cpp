//
// Created by Kurna on 2026/1/11.
//

#include "LongestCommonSubstring.hpp"

#include <vector>

std::vector<int> LongestCommonSubstring::solve(const std::vector<int>& a, const std::vector<int>& b) {
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());
    if (n == 0 || m == 0) return {};

    // dp[i][j] 表示以 a[i-1] 和 b[j-1] 结尾的最长公共后缀长度
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    int bestLen = 0;
    int bestEnd = -1; // 在 a 中的结束索引（0-based）

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > bestLen) {
                    bestLen = dp[i][j];
                    bestEnd = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    if (bestLen == 0) return {};
    std::vector<int> res;
    for (int k = bestEnd - bestLen + 1; k <= bestEnd; ++k) {
        res.push_back(a[k]);
    }
    return res;
}
