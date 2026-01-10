//
// Created by Kurna on 2026/1/11.
//

#ifndef ALGORITHM_LONGESTCOMMONSUBSTRING_HPP
#define ALGORITHM_LONGESTCOMMONSUBSTRING_HPP

#include <vector>

class LongestCommonSubstring {
public:
    // 计算两个整数序列的最长公共子串（连续），返回该子串（按原始顺序）
    // 如果没有公共子串，返回空向量
    static std::vector<int> solve(const std::vector<int>& a, const std::vector<int>& b);

private:
    
};


#endif //ALGORITHM_LONGESTCOMMONSUBSTRING_HPP
