//
// Created by Kurna on 2026/1/28.
//

#include "BucketSort.hpp"

#include <random>

void BucketSort::solve(std::vector<int> &vec) {
    if (vec.empty()) return;
    int min_val = vec[0];
    int max_val = vec[0];
    for (int num: vec) {
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }
    int bucket_count = 1 + (max_val - min_val) / static_cast<int>(vec.size());
    std::vector<std::vector<int> > buckets(bucket_count);
    for (int &num: vec) {
        if (max_val == min_val) {
            buckets[0].push_back(num);
            continue;
        }
        const int index = (num - min_val) / (max_val - min_val) * (bucket_count - 1);
        buckets[index].push_back(num);
    }
    vec.clear();
    for (auto &bucket: buckets) {
        quickSort(bucket, 0, bucket.size() - 1);
        vec.insert(vec.end(), bucket.begin(), bucket.end());
    }
}

void BucketSort::quickSort(std::vector<int> &vec, int left, int right) {
    if (right <= left) return;
    int pivot_idx = rand() % (right - left + 1) + left;
    int pivot_val = vec[pivot_idx];
    std::swap(vec[pivot_idx], vec[right]);
    int i = left - 1, j = left;
    for (; j <= right; ++j) {
        if (vec[j] < pivot_val) {
            std::swap(vec[i + 1], vec[j]);
            i++;
        }
    }
    std::swap(vec[i+1], vec[right]);
    quickSort(vec, left, i);
    quickSort(vec, i + 2, right);
}
