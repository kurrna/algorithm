//
// Created by Kurna on 2026/1/11.
//

#include "MinimumEditDistance.hpp"
#include <vector>
#include <algorithm>

// 定义静态成员
std::vector<std::string> MinimumEditDistance::editOp;

int MinimumEditDistance::solve(std::string &s, std::string &t) {
    editOp.clear();
    int m = static_cast<int>(s.size());
    int n = static_cast<int>(t.size());
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<char>> rec(m + 1, std::vector<char>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i; // 删除操作
        if (i > 0) rec[i][0] = 'D';
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j; // 插入操作
        if (j > 0) rec[0][j] = 'I';
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // 字符相同，无需操作
                rec[i][j] = 'M';
            } else {
                // 选择三种操作中的最小
                int delCost = dp[i - 1][j] + 1; // 删除 s[i-1]
                int insCost = dp[i][j - 1] + 1; // 在 s 中插入 t[j-1]
                int repCost = dp[i - 1][j - 1] + 1; // 替换 s[i-1] -> t[j-1]

                if (repCost <= delCost && repCost <= insCost) {
                    dp[i][j] = repCost;
                    rec[i][j] = 'R';
                } else if (delCost <= insCost) {
                    dp[i][j] = delCost;
                    rec[i][j] = 'D';
                } else {
                    dp[i][j] = insCost;
                    rec[i][j] = 'I';
                }
            }
        }
    }

    // 回溯从 (m,n) 构造操作序列（从后向前），然后反转为正向
    int i = m, j = n;
    while (i > 0 || j > 0) {
        char op = rec[i][j];
        if (op == 'M') {
            // 匹配，无操作
            editOp.emplace_back("无需操作");
            --i; --j;
        } else if (op == 'R') {
            // 替换 s[i-1] -> t[j-1]
            editOp.push_back("替换 '" + std::string(1, s[i-1]) + "' 为 '" + std::string(1, t[j-1]) + "'");
            --i; --j;
        } else if (op == 'D') {
            // 删除 s[i-1]
            editOp.push_back("删除 '" + std::string(1, s[i-1]) + "'");
            --i;
        } else if (op == 'I') {
            // 插入 t[j-1]
            editOp.push_back("插入 '" + std::string(1, t[j-1]) + "'");
            --j;
        } else {
            // 边界情况：当 i==0 或 j==0 时，dir 可能为 0
            if (i > 0 && j == 0) {
                editOp.push_back("删除 '" + std::string(1, s[i-1]) + "'");
                --i;
            } else if (j > 0 && i == 0) {
                editOp.push_back("插入 '" + std::string(1, t[j-1]) + "'");
                --j;
            } else {
                break;
            }
        }
    }

    std::reverse(editOp.begin(), editOp.end());
    return dp[m][n];
}