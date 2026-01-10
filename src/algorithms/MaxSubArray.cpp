//
// Created by Kurna on 2026/1/11.
//

#include "MaxSubArray.hpp"

int MaxSubArray::solve(const std::vector<int> &vec) {
    Rec.clear();
    if (vec.empty()) return 0;

    int n = static_cast<int>(vec.size());
    int maxEndingHere = vec[0];
    int maxSoFar = vec[0];
    int start = 0, end = 0, s = 0;

    for (int i = 1; i < n; ++i) {
        if (maxEndingHere + vec[i] < vec[i]) {
            maxEndingHere = vec[i];
            s = i; // potential start
        } else {
            maxEndingHere += vec[i];
        }

        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
    }

    // 填充 Rec
    for (int i = start; i <= end; ++i) {
        Rec.push_back(vec[i]);
    }

    return maxSoFar;
}