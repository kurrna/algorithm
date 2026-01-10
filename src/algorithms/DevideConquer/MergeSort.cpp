//
// Created by Kurna on 2026/1/5.
//

/**
 * 归并排序算法
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */

#include "MergeSort.hpp"

void MergeSort::solve(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    mergeSort(vec, 0, static_cast<int>(vec.size()) - 1);
}

void MergeSort::mergeSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

void MergeSort::merge(std::vector<int>& vec, int left, int mid, int right) {
    // 创建临时数组
    std::vector<int> temp(right - left + 1);

    int i = left;      // 左半部分起始索引
    int j = mid + 1;   // 右半部分起始索引
    int k = 0;         // 临时数组索引

    // 合并两个有序数组
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    // 复制剩余元素
    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= right) {
        temp[k++] = vec[j++];
    }

    // 将临时数组复制回原数组
    for (size_t p = 0; p < temp.size(); p++) {
        vec[left + p] = temp[p];
    }
}

