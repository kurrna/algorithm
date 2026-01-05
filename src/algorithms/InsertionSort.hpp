//
// Created by Kurna on 2026/1/5.
//

#ifndef ALGORITHM_INSERTIONSORT_HPP
#define ALGORITHM_INSERTIONSORT_HPP

#include <vector>

class InsertionSort {
public:
    static std::vector<int> solve(const std::vector<int> &vec);
private:
    static void insertToSorted(std::vector<int> &vec, int num);
};


#endif //ALGORITHM_INSERTIONSORT_HPP
