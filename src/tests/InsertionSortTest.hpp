#ifndef ALGORITHM_INSERTIONSORTTEST_HPP
#define ALGORITHM_INSERTIONSORTTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/InsertionSort.hpp"

class InsertionSortTest : public TestBase {
public:
    void run() override {
        printHeader("测试InsertionSort算法");

        TestStats stats;

        stats.recordResult(testCase1());
        stats.recordResult(testCase2());

        stats.printSummary("InsertionSort");
        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "InsertionSort";
    }

private:
    static bool testCase1() {
        std::cout << "\n测试用例1：" << std::endl;

        std::vector<int> input = {24, 17, 40, 28, 13, 14, 22, 32, 40, 21, 48, 4, 47, 8, 37, 18};
        std::vector<int> expected = {4, 8, 13, 14, 17, 18, 21, 22, 24, 28, 32, 37, 40, 40, 47, 48};

        auto actual = InsertionSort::solve(input);

        return assertVectorEquals(actual, expected);
    }

    static bool testCase2() {
        std::cout << "\n测试用例2：" << std::endl;

        std::vector<int> input = {5, 2, 8, 1, 9};
        std::vector<int> expected = {1, 2, 5, 8, 9};

        auto actual = InsertionSort::solve(input);

        return assertVectorEquals(actual, expected, "小规模排序");
    }
};

#endif //ALGORITHM_INSERTIONSORTTEST_HPP
