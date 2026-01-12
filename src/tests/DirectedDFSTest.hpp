#ifndef ALGORITHM_DIRECTEDDFSTEST_HPP
#define ALGORITHM_DIRECTEDDFSTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/DirectedDFS.hpp"

class DirectedDFSTest : public TestBase {
public:
    void run() override {
        printHeader("测试DirectedDFS算法");

        TestStats stats;
        stats.recordResult(testCaseEmpty());
        stats.recordResult(testCaseSimpleDirected());

        stats.printSummary("DirectedDFS");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "DirectedDFS";
    }

private:
    // 空输入测试
    static bool testCaseEmpty() {
        std::cout << "测试用例: 空输入" << std::endl;
        int n = 0;
        std::vector<std::pair<int,int>> edges;
        auto res = DirectedDFS::solve(n, edges, 0);
        std::vector<int> expected = {};
        return assertVectorEquals(res.order, expected);
    }

    // 简单有向图测试：0->1->2, 2->3
    static bool testCaseSimpleDirected() {
        std::cout << "测试用例: 简单有向图" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,3}};
        auto res = DirectedDFS::solve(n, edges, 0);
        if (res.order.empty()) return false;
        if (res.order[0] != 0) return false;
        // 检查是否能到达所有节点
        std::vector<int> present(n, 0);
        for (int v : res.order) if (v >= 0 && v < n) present[v] = 1;
        for (int i = 0; i < n; ++i) if (!present[i]) return false;
        return true;
    }

};

#endif //ALGORITHM_DIRECTEDDFSTEST_HPP
