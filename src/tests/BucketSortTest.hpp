#ifndef ALGORITHM_BUCKETSORTTEST_HPP
#define ALGORITHM_BUCKETSORTTEST_HPP

#include "SortTest.hpp"
#include "TestBase.hpp"
#include "../algorithms/BucketSort.hpp"

class BucketSortTest : public SortTest {
protected:
    void sort(std::vector<int>& vec) override {
        BucketSort::solve(vec);
    }

    [[nodiscard]] std::string getName() const override {
        return "BucketSort";
    }

};

#endif //ALGORITHM_BUCKETSORTTEST_HPP
