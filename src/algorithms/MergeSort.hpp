//
// Created by Kurna on 2026/1/5.
//

#ifndef ALGORITHM_MERGESORT_HPP
#define ALGORITHM_MERGESORT_HPP

#include <vector>

class MergeSort {
public:
    static void solve(std::vector<int>& vec);

private:
    static void merge(std::vector<int>& vec, int left, int mid, int right);

    static void mergeSort(std::vector<int>& vec, int left, int right);
};


#endif //ALGORITHM_MERGESORT_HPP
