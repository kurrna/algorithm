#ifndef ALGORITHM_TOPOSORTTEST_HPP
#define ALGORITHM_TOPOSORTTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/TopoSort.hpp"

class TopoSortTest : public TestBase {
public:
    void run() override {
        printHeader("测试TopoSort算法");

        TestStats stats;
        stats.recordResult(testCaseLinear());
        stats.recordResult(testCaseHasCycle());
        stats.recordResult(testCaseValidTopo());

        stats.printSummary("TopoSort");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "TopoSort";
    }

private:
    static bool testCaseLinear() {
        std::cout << "测试用例: 线性 DAG" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,3}};
        std::vector<int> expected = {0,1,2,3};
        auto actual = TopoSort::solve_BFS(n, edges);
        return assertVectorEquals(actual, expected);
    }

    static bool testCaseHasCycle() {
        std::cout << "测试用例: 有环图" << std::endl;
        int n = 3;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,0}};
        auto actual = TopoSort::solve_DFS(n, edges);
        printVector(actual);
        std::vector<int> expected = {};
        return assertVectorEquals(actual, expected);
    }

    // 通用合法性验证：只检查返回的序列是否是合法的拓扑序（若为空则表示有环）
    static bool testCaseValidTopo() {
        std::cout << "测试用例: 合法性验证" << std::endl;
        int n = 6;
        std::vector<std::pair<int,int>> edges = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};
        auto actual = TopoSort::solve_DFS(n, edges);
        printVector(actual);
        if (actual.empty()) return false; // 不应该有环
        // 验证每条边 u->v 在序列中 u 出现在 v 之前
        std::vector<int> pos(n, -1);
        for (int i = 0; i < (int)actual.size(); ++i) pos[actual[i]] = i;
        for (const auto &e : edges) {
            int u = e.first, v = e.second;
            if (pos[u] == -1 || pos[v] == -1) return false;
            if (pos[u] >= pos[v]) return false;
        }
        return true;
    }

};

#endif //ALGORITHM_TOPOSORTTEST_HPP
