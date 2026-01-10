#ifndef ALGORITHM_COUNTINGSORTTEST_HPP
#define ALGORITHM_COUNTINGSORTTEST_HPP

#include "SortTest.hpp"
#include "TestBase.hpp"
#include "../algorithms/CountingSort.hpp"

class CountingSortTest : public SortTest {
public:
    void sort(std::vector<int> &vec) override {
        CountingSort::solve(vec);
    }

    [[nodiscard]] std::string getName() const override {
        return "CountingSort";
    }
};

#endif //ALGORITHM_COUNTINGSORTTEST_HPP
