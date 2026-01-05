#ifndef ALGORITHM_MERGESORTTEST_HPP
#define ALGORITHM_MERGESORTTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/MergeSort.hpp"

class MergeSortTest : public TestBase {
public:
    void run() override {
        printHeader("测试MergeSort算法");

        TestStats stats;

        // 在这里添加你的测试用例
        stats.recordResult(testCase1());
        stats.recordResult(testCase2());
        stats.recordResult(testCase3());

        stats.printSummary("MergeSort");
        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MergeSort";
    }

private:
    // 测试用例1：基本排序
    static bool testCase1() {
        std::cout << "\n测试用例1：" << std::endl;

        std::vector<int> input = {40, 21, 4, 48, 17, 32, 37, 28, 18, 8, 24, 47, 40, 14, 22, 13};
        std::vector<int> expected = {4, 8, 13, 14, 17, 18, 21, 22, 24, 28, 32, 37, 40, 40, 47, 48};

        std::vector<int> actual = input;  // 复制输入
        MergeSort::solve(actual);

        return assertVectorEquals(actual, expected);
    }

    // 测试用例2：已排序数组
    static bool testCase2() {
        std::cout << "\n测试用例2：已排序数组" << std::endl;

        std::vector<int> input = {1, 2, 3, 4, 5};
        std::vector<int> expected = {1, 2, 3, 4, 5};

        std::vector<int> actual = input;
        MergeSort::solve(actual);

        return assertVectorEquals(actual, expected, "已排序数组");
    }

    // 测试用例3：逆序数组
    static bool testCase3() {
        std::cout << "\n测试用例3：逆序数组" << std::endl;

        std::vector<int> input = {5, 4, 3, 2, 1};
        std::vector<int> expected = {1, 2, 3, 4, 5};

        std::vector<int> actual = input;
        MergeSort::solve(actual);

        return assertVectorEquals(actual, expected, "逆序数组");
    }

    // 可以添加更多测试用例...
};

#endif //ALGORITHM_MERGESORTTEST_HPP
