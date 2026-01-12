#ifndef ALGORITHM_SCCTEST_HPP
#define ALGORITHM_SCCTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/SCC.hpp"

class SCCTest : public TestBase {
public:
    void run() override {
        printHeader("测试SCC算法");

        TestStats stats;
        stats.recordResult(testCaseEmpty());
        stats.recordResult(testCaseNoCycle());
        stats.recordResult(testCaseMultipleSCC());

        stats.printSummary("SCC");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "SCC";
    }

private:
    static bool testCaseEmpty() {
        std::cout << "测试用例: 空图" << std::endl;
        int n = 0;
        std::vector<std::pair<int,int>> edges;
        auto actual = SCC::solve(n, edges);
        std::vector<int> expected = {};
        return assertVectorEquals(actual, expected);
    }

    // 无环有向图，每个节点应是单独的 SCC（编号任意，但互不相同）
    static bool testCaseNoCycle() {
        std::cout << "测试用例: 无环图" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,3}};
        auto comp = SCC::solve(n, edges);
        if ((int)comp.size() != n) return false;
        // 检查所有 comp 值两两不同
        for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) if (comp[i] == comp[j]) return false;
        return true;
    }

    // 构造一个图包含多个 SCC：
    // SCC1: 0<->1 (0->1,1->0)
    // SCC2: 2<->3<->4 (2->3,3->4,4->2)
    // 5 -> 2 (单向进入)
    static bool testCaseMultipleSCC() {
        std::cout << "测试用例: 多个 SCC" << std::endl;
        int n = 6;
        std::vector<std::pair<int,int>> edges = {
            {0,1},{1,0}, // SCC {0,1}
            {2,3},{3,4},{4,2}, // SCC {2,3,4}
            {5,2} // 5 指向 SCC2
        };
        auto comp = SCC::solve(n, edges);
        if ((int)comp.size() != n) return false;
        // 检查 0 和 1 在同一个 SCC
        if (comp[0] != comp[1]) return false;
        // 检查 2,3,4 在同一个 SCC
        if (!(comp[2] == comp[3] && comp[3] == comp[4])) return false;
        // 检查 5 不在 2 的 SCC 中
        if (comp[5] == comp[2]) return false;
        return true;
    }

};

#endif //ALGORITHM_SCCTEST_HPP
