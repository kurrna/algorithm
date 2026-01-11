//
// Created by Kurna on 2026/1/10.
//

#include "QuickSort.hpp"
#include <cstdlib>

void QuickSort::solve(std::vector<int> &vec) {
    if (vec.size() <= 1) {
        return;
    }
    partition(vec, 0, vec.size() - 1);
}

void QuickSort::partition(std::vector<int> &vec, int start, int end) {
    if (end - start <= 0) {
        return;
    }
    int pivotIndex = start + rand() % (end - start + 1);
    int pivotValue = vec[pivotIndex];
    std::swap(vec[pivotIndex], vec[end]);
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (vec[j] < pivotValue) {
            std::swap(vec[i+1], vec[j]);
            i++;
        }
    }
    std::swap(vec[i+1], vec[end]);
    partition(vec, start, i);
    partition(vec, i + 2, end);
}