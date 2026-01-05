#ifndef ALGORITHM_YOURALGORITHMTEST_HPP
#define ALGORITHM_YOURALGORITHMTEST_HPP

#include "TestBase.hpp"
// #include "../algorithms/YourAlgorithm.hpp"

class YourAlgorithmTest : public TestBase {
public:
    void run() override {
        printHeader("测试YourAlgorithm算法");

        TestStats stats;

        // 在这里添加你的测试用例
        stats.recordResult(testCase1());
        stats.recordResult(testCase2());

        stats.printSummary("YourAlgorithm");
        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "YourAlgorithm";
    }

private:
    // 测试用例1
    static bool testCase1() {
        std::cout << "\n测试用例1：描述" << std::endl;

        // 示例：对于排序算法
        // std::vector<int> input = {5, 2, 8, 1, 9};
        // std::vector<int> expected = {1, 2, 5, 8, 9};

        // YourAlgorithm algo;
        // std::vector<int> actual = input;
        // algo.sort(actual);  // 或者其他方法名

        // return assertVectorEquals(actual, expected, "测试用例1");

        // 示例：对于返回单个值的算法
        // int input = 5;
        // int expected = 120;  // 例如阶乘

        // YourAlgorithm algo;
        // int actual = algo.calculate(input);

        // return assertEquals(actual, expected, "测试用例1");

        return true;  // 临时返回，替换为实际测试
    }

    // 测试用例2
    static bool testCase2() {
        std::cout << "\n测试用例2：描述" << std::endl;

        // 你的测试代码

        return true;  // 临时返回，替换为实际测试
    }

    // 可以添加更多测试用例...
};

#endif //ALGORITHM_YOURALGORITHMTEST_HPP

