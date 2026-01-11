#ifndef ALGORITHM_LONGESTCOMMONSEQUENCETEST_HPP
#define ALGORITHM_LONGESTCOMMONSEQUENCETEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DP/LongestCommonSequence.hpp"

class LongestCommonSequenceTest : public TestBase {
public:
    void run() override {
        printHeader("测试LongestCommonSequence算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("LongestCommonSequence");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "LongestCommonSequence";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> a = {1, 3, 4, 1};
        std::vector<int> b = {3, 4, 1, 2, 1};
        std::vector<int> expected = {3, 4, 1};
        auto actual = LongestCommonSequence::solve(a, b);

        std::cout << "LCS: ";
        TestBase::printVector(actual);

        return assertVectorEquals(actual, expected);
    }

};

#endif //ALGORITHM_LONGESTCOMMONSEQUENCETEST_HPP
