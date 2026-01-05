#ifndef ALGORITHM_MERGESORTTEST_HPP
#define ALGORITHM_MERGESORTTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/MergeSort.hpp"

class MergeSortTest : public TestBase {
public:
    void run() override {
        printHeader("测试MergeSort算法");

        // 在这里添加你的测试用例
        testCase1();
        testCase2();

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MergeSort";
    }

private:
    // 测试用例1
    static void testCase1() {
        std::cout << "测试用例1：" << std::endl;

        // 你的测试代码
        // 例如：
        // std::vector<int> input = {1, 2, 3, 4, 5};
        // auto result = MergeSort::solve(input);
        // std::cout << "结果: " << result << std::endl;

        std::cout << std::endl;
    }

    // 测试用例2
    static void testCase2() {
        std::cout << "测试用例2：" << std::endl;

        // 你的测试代码

        std::cout << std::endl;
    }

    // 可以添加更多测试用例...
};

#endif //ALGORITHM_MERGESORTTEST_HPP
