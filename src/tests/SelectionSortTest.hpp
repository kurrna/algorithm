#ifndef ALGORITHM_SELECTIONSORTTEST_HPP
#define ALGORITHM_SELECTIONSORTTEST_HPP

#include "SortTest.hpp"
#include "../algorithms/SelectionSort.hpp"

/**
 * 选择排序测试
 * 继承 SortTest，自动获得 6 个标准排序测试用例
 */
class SelectionSortTest : public SortTest {
protected:
    void sort(std::vector<int>& vec) override {
        SelectionSort::solve(vec);
    }

    [[nodiscard]] std::string getName() const override {
        return "SelectionSort";
    }

};

#endif //ALGORITHM_SELECTIONSORTTEST_HPP
