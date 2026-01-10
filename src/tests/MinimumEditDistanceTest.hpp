#ifndef ALGORITHM_MINIMUMEDITDISTANCETEST_HPP
#define ALGORITHM_MINIMUMEDITDISTANCETEST_HPP

#include "TestBase.hpp"
#include "../algorithms/MinimumEditDistance.hpp"

class MinimumEditDistanceTest : public TestBase {
public:
    void run() override {
        printHeader("测试MinimumEditDistance算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("MinimumEditDistance");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MinimumEditDistance";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::string inputA = "ABCBDAB";
        std::string inputB = "BDCABA";
        int expected = 5;
        auto actual = MinimumEditDistance::solve(inputA, inputB);
        printVector(MinimumEditDistance::editOp);

        return assertEquals(actual, expected);
    }

};

#endif //ALGORITHM_MINIMUMEDITDISTANCETEST_HPP
