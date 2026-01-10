#ifndef ALGORITHM_QUICKSORTTEST_HPP
#define ALGORITHM_QUICKSORTTEST_HPP

#include "SortTest.hpp"
#include "TestBase.hpp"
#include "../algorithms/QuickSort.hpp"

class QuickSortTest : public SortTest {
public:
    void sort(std::vector<int>& vec) override {
        QuickSort::solve(vec);
    }

    [[nodiscard]] std::string getAlgorithmName() const override {
        return "QuickSort";
    }

};

#endif //ALGORITHM_QUICKSORTTEST_HPP
