#ifndef ALGORITHM_ACTIVITYSELECTIONTEST_HPP
#define ALGORITHM_ACTIVITYSELECTIONTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/ActivitySelection.hpp"

class ActivitySelectionTest : public TestBase {
public:
    void run() override {
        printHeader("测试ActivitySelection算法");

        TestStats stats;
        stats.recordResult(testCase1());
        stats.recordResult(testCase2());

        stats.printSummary("ActivitySelection");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "ActivitySelection";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {};
        std::vector<int> expected = {};
        auto actual = ActivitySelection::solve(input);
        
        return assertVectorEquals(actual, expected);
    }

    // 带权重测试：验证最大权重不冲突子集
    static bool testCase2() {
        std::cout << "测试用例2：带权重的活动选择" << std::endl;
        // 活动： idx: s,f,w
        // 0: 1,3,5
        // 1: 2,5,6
        // 2: 4,6,5
        // 3: 6,7,4
        std::vector<int> starts = {1,2,4,6};
        std::vector<int> finishes = {3,5,6,7};
        std::vector<int> weights = {5,6,5,4};

        // 最优选择为活动 0,2,3，总权重 14
        std::vector<int> expected = {0,2,3};
        auto actual = ActivitySelection::solveWeighted(starts, finishes, weights);

        return assertVectorEquals(actual, expected, "Weighted selection");
    }

};

#endif //ALGORITHM_ACTIVITYSELECTIONTEST_HPP
