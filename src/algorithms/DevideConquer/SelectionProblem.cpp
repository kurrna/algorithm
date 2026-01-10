//
// Created by Kurna on 2026/1/10.
//

#include "../SelectionProblem.hpp"
#include <cstdlib>

int SelectionProblem::solve(std::vector<int> &vec, int k) {
    return partition(vec, k, 0, vec.size() - 1);
}

int SelectionProblem::partition(std::vector<int> &vec, int k, int start, int end) {
    if (end <= start) {
        return vec[start];
    }
    int pivotIdx = start + rand() % (end - start + 1);
    int pivot = vec[pivotIdx];
    std::swap(vec[pivotIdx], vec[end]);
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (vec[j] < pivot) {
            std::swap(vec[i+1], vec[j]);
            i++;
        }
    }
    std::swap(vec[end], vec[i+1]);
    // 第k小的元素，角标应为 k-1，此时主元脚标 i+1，左边的元素个数为 i+1-start
    if (k > i - start + 2) {
        return partition(vec, k, i + 2, end);
    }
    if (k < i - start + 2) {
        return partition(vec, k, start, i);
    }
    return vec[i + 1];
}
