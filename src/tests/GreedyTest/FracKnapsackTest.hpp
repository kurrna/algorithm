#ifndef ALGORITHM_FRACKNAPSACKTEST_HPP
#define ALGORITHM_FRACKNAPSACKTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/Greedy/FracKnapsack.hpp"

class FracKnapsackTest : public TestBase {
public:
    void run() override {
        printHeader("测试FracKnapsack算法");

        TestStats stats;
        stats.recordResult(testCase1());
        stats.recordResult(testCase2());

        stats.printSummary("FracKnapsack");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "FracKnapsack";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：空输入" << std::endl;

        std::vector<double> volumes = {};
        std::vector<double> prices = {};
        double C = 10.0;
        double expected = 0.0;
        double actual = FracKnapsack::solve(volumes, prices, C);

        return assertEquals(actual, expected, "Empty input");
    }

    static bool testCase2() {
        std::cout << "测试用例2：一般情况" << std::endl;

        std::vector<double> volumes = {4.0, 3.0, 2.0};
        std::vector<double> prices = {20.0, 18.0, 14.0};
        double C = 5.0;
        double expected = 32.0; // 取体积2（价值14）和体积3（价值18）
        double actual = FracKnapsack::solve(volumes, prices, C);

        return assertEquals(actual, expected, "General case");
    }

};

#endif //ALGORITHM_FRACKNAPSACKTEST_HPP
