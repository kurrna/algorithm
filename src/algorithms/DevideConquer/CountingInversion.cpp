//
// Created by Kurna on 2026/1/8.
//

#include "../CountingInversion.hpp"

std::vector<int> CountingInversion::temp;

int CountingInversion::solve(std::vector<int> vec) {
    temp.resize(vec.size());
    return mergeSortAndCount(vec, 0, static_cast<int>(vec.size()) - 1);
}

int CountingInversion::mergeSortAndCount(std::vector<int> &vec, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int mid = l + (r - l) / 2;
    int count = 0;
    count += mergeSortAndCount(vec, l, mid);
    count += mergeSortAndCount(vec, mid + 1, r);
    count += mergeAndCount(vec, l, mid, r);
    return count;
}

int CountingInversion::mergeAndCount(std::vector<int> &vec, int l, int mid, int r) {
    for (int idx = l; idx <= r; ++idx)
        temp[idx] = vec[idx];

    int i = l, j = mid + 1, k = l;
    int count = 0;

    while (i <= mid && j <= r) {
        if (temp[i] <= temp[j]) {
            vec[k++] = temp[i++];
        } else {
            vec[k++] = temp[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid) {
        vec[k++] = temp[i++];
    }

    while (j <= r) {
        vec[k++] = temp[j++];
    }

    return count;
}
