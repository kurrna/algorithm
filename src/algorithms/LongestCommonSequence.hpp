//
// Created by Kurna on 2026/1/11.
//

#ifndef ALGORITHM_LONGESTCOMMONSEQUENCE_HPP
#define ALGORITHM_LONGESTCOMMONSEQUENCE_HPP

#include <vector>

class LongestCommonSequence {
public:
    // 使用动态规划计算两个整数序列的最长公共子序列（LCS）
    // 返回值为 LCS 本身（按原始顺序）
    static std::vector<int> solve(const std::vector<int>& a, const std::vector<int>& b);
private:
    
};


#endif //ALGORITHM_LONGESTCOMMONSEQUENCE_HPP
