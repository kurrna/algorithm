#ifndef ALGORITHM_ZEROONEKNAPSACKTEST_HPP
#define ALGORITHM_ZEROONEKNAPSACKTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/ZeroOneKnapsack.hpp"

class ZeroOneKnapsackTest : public TestBase {
public:
    void run() override {
        printHeader("测试ZeroOneKnapsack算法");

        TestStats stats;
        stats.recordResult(testCase1());
        stats.recordResult(testCase2());

        stats.printSummary("ZeroOneKnapsack");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "ZeroOneKnapsack";
    }

private:
    // 用例1：空输入，应返回0
    static bool testCase1() {
        std::cout << "测试用例1：空输入" << std::endl;

        std::vector<int> volumes = {};
        std::vector<int> prices = {};
        int C = 10;
        int expected = 0;
        int actual = ZeroOneKnapsack::solve(volumes, prices, C);

        return assertEquals(actual, expected, "Empty input");
    }

    // 用例2：示例用例
    // 物品 (vol, price): (3,2), (4,3), (6,1), (5,4)，背包容量 C = 10
    // 最优选择是体积4和5，总价值为7
    static bool testCase2() {
        std::cout << "测试用例2：示例用例" << std::endl;

        std::vector<int> volumes = {3, 4, 6, 5};
        std::vector<int> prices = {2, 3, 1, 4};
        int C = 10;
        int expected = 7;
        int actual = ZeroOneKnapsack::solve(volumes, prices, C);

        return assertEquals(actual, expected, "Example case");
    }

};

#endif //ALGORITHM_ZEROONEKNAPSACKTEST_HPP
