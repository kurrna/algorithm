#ifndef ALGORITHM_MAXIMUMCONTIGUOUSSUBARRAYTEST_HPP
#define ALGORITHM_MAXIMUMCONTIGUOUSSUBARRAYTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/MaximumContiguousSubarray.hpp"

class MaximumContiguousSubarrayTest : public TestBase {
public:
    void run() override {
        printHeader("测试MaximumContiguousSubarray算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("MaximumContiguousSubarray");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MaximumContiguousSubarray";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {1, -2, 4, 5, -2, 8, 3, -2, 6, 3, 7, -1};
        int expect = 32;
        auto actual = MaximumContiguousSubarray::solve(input);
        std::cout << "实际结果：" << actual << std::endl;
        
        return assertEquals(actual, expect);
    }

};

#endif //ALGORITHM_MAXIMUMCONTIGUOUSSUBARRAYTEST_HPP
