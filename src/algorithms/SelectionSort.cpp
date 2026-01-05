//
// Created by Kurna on 2026/1/5.
//

#include "SelectionSort.hpp"

/**
 * 选择排序的核心实现
 *
 * 算法步骤：
 * 第一遍：从所有 n 个元素中找最小的，与第 1 个元素交换
 * 第二遍：从剩下 n-1 个元素中找最小的，与第 2 个元素交换
 * ...以此类推，直到只剩 1 个元素
 */
void SelectionSort::solve(std::vector<int>& vec) {
    size_t n = vec.size();

    if (n <= 1) return;
    // 遍历每个位置
    for (size_t i = 0; i < n - 1; ++i) {
        // 假设当前位置是最小元素的索引
        size_t minIndex = i;

        // 在未排序部分寻找最小元素
        for (size_t j = i + 1; j < n; ++j) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }

        // 如果找到更小的元素，与当前位置交换
        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}

void SelectionSort::swap(int& a, int& b) noexcept {
    int temp = a;
    a = b;
    b = temp;
}
