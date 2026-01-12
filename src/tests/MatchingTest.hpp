#ifndef ALGORITHM_MATCHINGTEST_HPP
#define ALGORITHM_MATCHINGTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/Matching.hpp"

class MatchingTest : public TestBase {
public:
    void run() override {
        printHeader("测试Matching算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("Matching");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "Matching";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：简单二分图示例" << std::endl;

        int nL = 4, nR = 4;
        std::vector<std::pair<int,int>> edges = {
            {0,0}, {0,1}, {1,1}, {2,2}, {3,2}, {3,3}
        };

        auto res = Matching::solve(nL, nR, edges);

        std::vector<int> expectedMatchL = {0,1,2,3};
        std::vector<int> expectedMatchR = {0,1,2,3};
        int expectedSize = 4;

        std::cout << "matchL: "; TestBase::printVector(res.matchL);
        std::cout << "matchR: "; TestBase::printVector(res.matchR);
        std::cout << "size: " << res.size << std::endl;

        bool ok = true;
        ok &= assertVectorEquals(res.matchL, expectedMatchL, "matchL");
        ok &= assertVectorEquals(res.matchR, expectedMatchR, "matchR");
        ok &= assertEquals(res.size, expectedSize, "匹配大小");

        return ok;
    }

};

#endif //ALGORITHM_MATCHINGTEST_HPP
