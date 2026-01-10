//
// Created by Kurna on 2026/1/7.
//

#include "MaximumContiguousSubarray.hpp"

int MaximumContiguousSubarray::solve(const std::vector<int> &vec) {
    return maxSubArray(vec, 0, static_cast<int>(vec.size()) - 1);
}

int MaximumContiguousSubarray::maxSubArray(const std::vector<int> &vec, int l, int r) {
    if (r == l) {
        return vec[l];
    }
    int mid = l + (r - l) / 2; // 不会溢出的向下取整
    int tempMax = std::max(maxSubArray(vec, l, mid),
        maxSubArray(vec, mid + 1, r));
    return std::max(tempMax, crossingSubArray(vec, l, mid, r));
}

int MaximumContiguousSubarray::crossingSubArray(const std::vector<int> &vec, int l, int mid, int r) {
    if (l == r) {
        return 0;
    }
    int tempSum = 0;
    int leftSum = 0;
    for (int i = mid; i >= l; --i) {
        tempSum += vec[i];
        if (tempSum >= leftSum) {
            leftSum = tempSum;
        }
    }
    tempSum = 0;
    int rightSum = 0;
    for (int j = mid + 1; j <= r; ++j) {
        tempSum += vec[j];
        if (tempSum >= rightSum) {
            rightSum = tempSum;
        }
    }
    return leftSum + rightSum;
}