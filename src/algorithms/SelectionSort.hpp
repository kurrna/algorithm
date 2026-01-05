//
// Created by Kurna on 2026/1/5.
//

#ifndef ALGORITHM_SELECTIONSORT_HPP
#define ALGORITHM_SELECTIONSORT_HPP

#include <vector>

/**
 * 选择排序算法
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * 算法原理：
 * 1. 在未排序部分找到最小元素
 * 2. 将最小元素与未排序部分的第一个元素交换
 * 3. 缩小未排序部分的范围，重复步骤 1-2
 */
class SelectionSort {
public:
    static void solve(std::vector<int>& vec);

private:
    // 辅助函数：交换两个元素
    static void swap(int& a, int& b) noexcept;
};


#endif //ALGORITHM_SELECTIONSORT_HPP
