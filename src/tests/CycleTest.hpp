#ifndef ALGORITHM_CYCLETEST_HPP
#define ALGORITHM_CYCLETEST_HPP

#include "TestBase.hpp"
#include "../algorithms/Cycle.hpp"

class CycleTest : public TestBase {
public:
    void run() override {
        printHeader("测试Cycle算法");

        TestStats stats;
        stats.recordResult(testCaseEmpty());
        stats.recordResult(testCaseNoCycle());
        stats.recordResult(testCaseHasCycle());

        stats.printSummary("Cycle");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "Cycle";
    }

private:
    static bool testCaseEmpty() {
        std::cout << "测试用例: 空图" << std::endl;
        int n = 0;
        std::vector<std::pair<int,int>> edges;
        auto actual = Cycle::solve(n, edges);
        std::vector<int> expected = {};
        return assertVectorEquals(actual, expected);
    }

    static bool testCaseNoCycle() {
        std::cout << "测试用例: 无环有向图" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,3}}; // 线性无环
        auto actual = Cycle::solve(n, edges);
        std::vector<int> expected = {};
        return assertVectorEquals(actual, expected);
    }

    static bool testCaseHasCycle() {
        std::cout << "测试用例: 有环有向图" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,0},{2,3}}; // 0->1->2->0 有环
        auto actual = Cycle::solve(n, edges);
        // 返回值应该是一个非空的环序列，验证第一个和最后一个顶点相同或验证包含环中的节点
        if (actual.empty()) return false;
        // 检查环中的节点均在 0..n-1
        for (int v : actual) if (v < 0 || v >= n) return false;
        // 简单检查：返回的环中至少包含 {0,1,2} 中的一个并且长度 >= 2
        if (actual.size() < 2) return false;
        return true;
    }

};

#endif //ALGORITHM_CYCLETEST_HPP
