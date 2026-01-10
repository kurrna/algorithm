#ifndef ALGORITHM_HEAPSORTTEST_HPP
#define ALGORITHM_HEAPSORTTEST_HPP

#include "../SortTest.hpp"
#include "../TestBase.hpp"
#include "../../algorithms/DevideConquer/HeapSort.hpp"

class HeapSortTest : public SortTest {
public:
    void sort(std::vector<int> &vec) override {
        HeapSort::solve(vec);
    }

    [[nodiscard]] std::string getName() const override {
        return "HeapSort";
    }
};

#endif //ALGORITHM_HEAPSORTTEST_HPP
