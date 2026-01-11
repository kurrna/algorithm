#ifndef ALGORITHM_MAXSUBARRAYTEST_HPP
#define ALGORITHM_MAXSUBARRAYTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DP/MaxSubArray.hpp"

class MaxSubArrayTest : public TestBase {
public:
    void run() override {
        printHeader("测试MaxSubArray算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("MaxSubArray");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MaxSubArray";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {-1, -3, 3, 5, -4, 3, 2, -2, 3, 6};
        int expected = 16;
        MaxSubArray solver;
        int actual = solver.solve(input);

        // 打印 Rec 以便测试输出中查看最优子数组
        std::cout << "最优子数组 Rec: ";
        TestBase::printVector(solver.Rec);

        return assertEquals(actual, expected);
    }

};

#endif //ALGORITHM_MAXSUBARRAYTEST_HPP
