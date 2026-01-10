#ifndef ALGORITHM_POLYNOMIALMULTIPLICATIONTEST_HPP
#define ALGORITHM_POLYNOMIALMULTIPLICATIONTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DevideConquer/PolynomialMultiplication.hpp"

class PolynomialMultiplicationTest : public TestBase {
public:
    void run() override {
        printHeader("测试PolynomialMultiplication算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("PolynomialMultiplication");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "PolynomialMultiplication";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> inputA = {2, 5, 3, 1, -1};
        std::vector<int> inputB = {1, 2, 2, 3, 6};
        std::vector<int> expected = {2, 9, 17, 23, 34, 39, 19, 3, -6};
        auto actual = PolynomialMultiplication::solve(inputA, inputB);
        
        return assertVectorEquals(actual, expected);
    }

};

#endif //ALGORITHM_POLYNOMIALMULTIPLICATIONTEST_HPP
