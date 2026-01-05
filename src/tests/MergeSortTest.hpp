#ifndef ALGORITHM_MERGESORTTEST_HPP
#define ALGORITHM_MERGESORTTEST_HPP

#include "SortTest.hpp"
#include "../algorithms/MergeSort.hpp"

/**
 * 归并排序测试
 * 继承 SortTest，自动获得 6 个标准排序测试用例
 */
class MergeSortTest : public SortTest {
protected:
    void sort(std::vector<int>& vec) override {
        MergeSort::solve(vec);
    }

    [[nodiscard]] std::string getAlgorithmName() const override {
        return "MergeSort";
    }
};

#endif //ALGORITHM_MERGESORTTEST_HPP
