#ifndef ALGORITHM_DFSTEST_HPP
#define ALGORITHM_DFSTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/DFS.hpp"

class DFSTest : public TestBase {
public:
    void run() override {
        printHeader("测试DFS算法");

        TestStats stats;
        stats.recordResult(testCaseEmpty());
        stats.recordResult(testCaseSimpleUndirected());
        stats.recordResult(testCaseDirectedCycle());

        stats.printSummary("DFS");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "DFS";
    }

private:
    // 空图测试：传入 0 个节点，应返回空的访问序列
    static bool testCaseEmpty() {
        std::cout << "测试用例: 空图" << std::endl;
        int n = 0;
        std::vector<std::pair<int,int>> edges; // 空边表
        auto res = DFS::solve(n, edges, 0);
        std::vector<int> expected = {};
        return assertVectorEquals(res.order, expected);
    }

    // 无向简单图测试：构造边表（双向语义，传入 undirected=true），检查 DFS 可以访问所有节点且首节点为起点
    static bool testCaseSimpleUndirected() {
        std::cout << "测试用例: 简单无向图" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges;
        edges.emplace_back(0,1);
        edges.emplace_back(1,2);
        edges.emplace_back(0,3);

        auto res = DFS::solve(n, edges, 0, true);
        if (res.order.empty()) return false;
        if (res.order[0] != 0) return false;
        std::vector<int> present(n, 0);
        for (int v : res.order) if (v >= 0 && v < n) present[v] = 1;
        for (int i = 0; i < n; ++i) if (!present[i]) return false;
        return true;
    }

    // 有向图带环测试：构造有向边表，检查能访问所有从起点可达的节点且不死循环
    static bool testCaseDirectedCycle() {
        std::cout << "测试用例: 有向图带环" << std::endl;
        int n = 4;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{2,0},{2,3}};

        auto res = DFS::solve(n, edges, 0, false); // 有向图
        if (res.order.empty()) return false;
        if (res.order[0] != 0) return false;
        std::vector<int> present(n, 0);
        for (const int v : res.order) if (v >= 0 && v < n) present[v] = 1;
        for (int i = 0; i < n; ++i) if (!present[i]) return false;
        return true;
    }

};

#endif //ALGORITHM_DFSTEST_HPP
