//
// Created by Kurna on 2026/1/28.
//

#ifndef ALGORITHM_BUCKETSORT_HPP
#define ALGORITHM_BUCKETSORT_HPP

#include <vector>

class BucketSort {
public:
    static void solve(std::vector<int> &vec);

private:
    static void quickSort(std::vector<int> &vec, int left, int right);
};


#endif //ALGORITHM_BUCKETSORT_HPP
