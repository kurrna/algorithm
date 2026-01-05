#ifndef ALGORITHM_INSERTIONSORTTEST_HPP
#define ALGORITHM_INSERTIONSORTTEST_HPP

#include "SortTest.hpp"
#include "../algorithms/InsertionSort.hpp"

/**
 * 插入排序测试
 * 继承 SortTest，自动获得 6 个标准排序测试用例
 */
class InsertionSortTest : public SortTest {
protected:
    void sort(std::vector<int>& vec) override {
        InsertionSort::solve(vec);
    }

    [[nodiscard]] std::string getAlgorithmName() const override {
        return "InsertionSort";
    }
};

#endif //ALGORITHM_INSERTIONSORTTEST_HPP
