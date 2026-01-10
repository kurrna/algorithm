#ifndef ALGORITHM_COUNTINGINVERSIONTEST_HPP
#define ALGORITHM_COUNTINGINVERSIONTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DevideConquer/CountingInversion.hpp"

class CountingInversionTest : public TestBase {
public:
    void run() override {
        printHeader("测试CountingInversion算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("CountingInversion");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "CountingInversion";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {13, 8, 10, 5, 15, 18, 12, 20, 9, 14, 17, 19};
        int expected = 20;
        auto actual = CountingInversion::solve(input);
        
        return assertEquals(actual, expected);
    }

};

#endif //ALGORITHM_COUNTINGINVERSIONTEST_HPP
