#ifndef ALGORITHM_RODCUTTINGTEST_HPP
#define ALGORITHM_RODCUTTINGTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DP/RodCutting.hpp"

class RodCuttingTest : public TestBase {
public:
    void run() override {
        printHeader("测试RodCutting算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("RodCutting");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "RodCutting";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 24};
        int expected = 27;
        auto actual = RodCutting::solve(input);
        printRec(RodCutting::rec);

        return assertEquals(actual, expected);
    }

    static void printRec(const std::vector<int>& rec) {
        std::cout << "最佳切割方案（每段长度）: ";
        int n = static_cast<int>(rec.size()) - 1;
        while (n > 0) {
            std::cout << rec[n] << " ";
            n -= rec[n];
        }
        std::cout << std::endl;
    }
};

#endif //ALGORITHM_RODCUTTINGTEST_HPP
