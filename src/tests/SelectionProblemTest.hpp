#ifndef ALGORITHM_SELECTIONPROBLEMTEST_HPP
#define ALGORITHM_SELECTIONPROBLEMTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/SelectionProblem.hpp"

class SelectionProblemTest : public TestBase {
public:
    void run() override {
        printHeader("测试SelectionProblem算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("SelectionProblem");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "SelectionProblem";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {21, 17, 37, 28, 13, 14, 22, 52, 40, 24, 48, 4, 47, 8, 42, 18};
        int expected = 22;
        auto actual = SelectionProblem::solve(input, 8);
        
        return assertEquals(actual, expected);
    }

};

#endif //ALGORITHM_SELECTIONPROBLEMTEST_HPP
