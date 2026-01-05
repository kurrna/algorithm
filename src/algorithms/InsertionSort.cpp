//
// Created by Kurna on 2026/1/5.
//

/**
 * 插入排序
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */

#include "InsertionSort.hpp"

std::vector<int> InsertionSort::solve(const std::vector<int> &vec) {
    const size_t n = vec.size();
    std::vector<int> sorted;
    for (auto i = 0; i < n; ++i) {
        insertToSorted(sorted, vec[i]);
    }
    return sorted;
}

void InsertionSort::insertToSorted(std::vector<int> &vec, const int num) {
    auto pos = vec.end();
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it > num) {
            pos = it;
            break;
        }
    }
    vec.insert(pos, num);
}
