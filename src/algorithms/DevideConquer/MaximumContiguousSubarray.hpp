//
// Created by Kurna on 2026/1/7.
//

#ifndef ALGORITHM_MAXIMUMCONTIGUOUSSUBARRAY_HPP
#define ALGORITHM_MAXIMUMCONTIGUOUSSUBARRAY_HPP

#include <vector>

class MaximumContiguousSubarray {
public:
    static int solve(const std::vector<int> &vec);
private:
    static int maxSubArray(const std::vector<int> &vec, int l, int r);

    static int crossingSubArray(const std::vector<int> &vec, int l, int mid, int r);
};


#endif //ALGORITHM_MAXIMUMCONTIGUOUSSUBARRAY_HPP
