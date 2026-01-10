//
// Created by Kurna on 2026/1/10.
//

#ifndef ALGORITHM_QUICKSORT_HPP
#define ALGORITHM_QUICKSORT_HPP

#include <vector>

class QuickSort {
public:
    static void solve(std::vector<int> &vec);
private:
    static void partition(std::vector<int> &vec, int start, int end);
};


#endif //ALGORITHM_QUICKSORT_HPP
