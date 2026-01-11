#ifndef ALGORITHM_LONGESTCOMMONSUBSTRINGTEST_HPP
#define ALGORITHM_LONGESTCOMMONSUBSTRINGTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DP/LongestCommonSubstring.hpp"

class LongestCommonSubstringTest : public TestBase {
public:
    void run() override {
        printHeader("测试LongestCommonSubstring算法");

        TestStats stats;
        stats.recordResult(testCase1());
        stats.recordResult(testCase2());

        stats.printSummary("LongestCommonSubstring");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "LongestCommonSubstring";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：空序列" << std::endl;

        std::vector<int> a = {};
        std::vector<int> b = {};
        std::vector<int> expected = {};
        auto actual = LongestCommonSubstring::solve(a, b);
        return assertVectorEquals(actual, expected, "empty");
    }

    static bool testCase2() {
        std::cout << "测试用例2：一般序列" << std::endl;
        // a 中的子串 {4,5,6} 在 b 中也连续出现
        std::vector<int> a = {1,2,3,4,5,6,7};
        std::vector<int> b = {9,4,5,6,8};
        std::vector<int> expected = {4,5,6};
        auto actual = LongestCommonSubstring::solve(a, b);

        std::cout << "LCS (substring): ";
        TestBase::printVector(actual);
        return assertVectorEquals(actual, expected, "general");
    }

};

#endif //ALGORITHM_LONGESTCOMMONSUBSTRINGTEST_HPP
