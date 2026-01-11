//
// Created by Kurna on 2026/1/11.
//

#include "LongestCommonSequence.hpp"

#include <vector>
#include <algorithm> // 为了 std::reverse

std::vector<int> LongestCommonSequence::solve(const std::vector<int>& a, const std::vector<int>& b) {
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());
    if (n == 0 || m == 0) return {};

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    std::vector<std::vector<char>> rec(n + 1, std::vector<char>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                rec[i][j] = 'D'; // 对角表示匹配并继承自 dp[i-1][j-1]
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    rec[i][j] = 'U';
                } else {
                    dp[i][j] = dp[i][j - 1];
                    rec[i][j] = 'L';
                }
            }
        }
    }

    // 使用在填表阶段同时计算好的方向表回溯构建 LCS（从 dp[n][m] 开始）
    int i = n, j = m;
    std::vector<int> lcs;
    while (i > 0 && j > 0) {
        if (rec[i][j] == 'D') {
            // 对角：当前位置是匹配字符
            lcs.push_back(a[i - 1]);
            --i; --j;
        } else if (rec[i][j] == 'U') {
            --i;
        } else { // 'L'
            --j;
        }
    }

    // 目前 lcs 为逆序，需要翻转
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}
