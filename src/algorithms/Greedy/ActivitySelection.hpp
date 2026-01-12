//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_ACTIVITYSELECTION_HPP
#define ALGORITHM_ACTIVITYSELECTION_HPP

#include <vector>

class ActivitySelection {
public:
    // 输入：交替的开始/结束时间向量 [s1,f1,s2,f2,...]
    // 输出：被选择活动的原始索引（0-based），按选择顺序返回（贪心，不带权重）
    static std::vector<int> solve(const std::vector<int>& times);

    // 带权活动选择（动态规划）
    // 输入：开始时间向量 starts, 结束时间向量 finishes, 权重向量 weights（等长）
    // 输出：被选活动的原始索引（0-based），按选择顺序返回，输出为使总权重最大的互不冲突子集
    static std::vector<int> solveWeighted(const std::vector<int>& starts,
                                          const std::vector<int>& finishes,
                                          const std::vector<int>& weights);
private:
    
};


#endif //ALGORITHM_ACTIVITYSELECTION_HPP
