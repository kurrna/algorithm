//
// Created by Kurna on 2026/1/11.
//

#ifndef ALGORITHM_MAXSUBARRAY_HPP
#define ALGORITHM_MAXSUBARRAY_HPP

#include <vector>

class MaxSubArray {
public:
    // 记录最优子数组
    std::vector<int> Rec;

    // 输入为空时返回 0，Rec 也清空
    int solve(const std::vector<int>& arr);
private:
    
};


#endif //ALGORITHM_MAXSUBARRAY_HPP
