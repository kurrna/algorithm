//
// Created by Kurna on 2026/1/10.
//

#include "CountingSort.hpp"
#include <algorithm>

// 计数排序实现
void CountingSort::solve(std::vector<int> &vec) {
    if (vec.size() <= 1) return;
    int n = static_cast<int>(vec.size());
    int minVal = *std::min_element(vec.begin(), vec.end());
    int maxVal = *std::max_element(vec.begin(), vec.end());
    int k = maxVal - minVal + 1;
    std::vector<int> count(k, 0);
    for (int j = 0; j < n; ++j) {
        count[vec[j] - minVal] += 1;
    }
    for (int i = 1; i < k; ++i) {
        count[i] += count[i - 1];
    }
    std::vector<int> output(n);
    for (int j = n - 1; j >= 0; --j) {
        output[count[vec[j] - minVal] - 1] = vec[j]; // 比vec[j]小的元素个数即为其排序后的位置（从0开始计数）
        count[vec[j] - minVal] -= 1;
    }
    vec = std::move(output);
}
