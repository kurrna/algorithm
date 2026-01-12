#ifndef ALGORITHM_BFSTEST_HPP
#define ALGORITHM_BFSTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/Graph/BFS.hpp"

class BFSTest : public TestBase {
public:
    void run() override {
        printHeader("测试BFS算法");

        TestStats stats;
        stats.recordResult(testCaseEmpty());
        stats.recordResult(testCaseSimple());

        stats.printSummary("BFS");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "BFS";
    }

private:
    // 保持原来的空输入测试（n=0）
    static bool testCaseEmpty() {
        std::cout << "测试用例: 空图" << std::endl;

        int n = 0;
        std::vector<std::pair<int,int>> edges = {};
        auto res = BFS::bfs(n, edges, 0);
        std::vector<int> expectedOrder = {};
        return assertVectorEquals(res.order, expectedOrder);
    }

    // 简单图测试：
    // 0 - 1 - 2
    // |   |
    // 3   4
    static bool testCaseSimple() {
        std::cout << "测试用例: 简单图" << std::endl;
        int n = 5;
        std::vector<std::pair<int,int>> edges = {{0,1},{1,2},{0,3},{1,4}};
        auto res = BFS::solve(n, edges, 0, true);
        // BFS 从 0 出发，一种可能的访问顺序为 0,1,3,2,4 或 0,1,3,4,2，具体取决于邻接顺序
        // 我们检查：首个访问节点为 0，距离向量的正确性
        if (res.order.empty() || res.order[0] != 0) return false;
        std::vector<int> expectedDist = {0,1,2,1,2};
        return assertVectorEquals(res.dist, expectedDist);
    }

};

#endif //ALGORITHM_BFSTEST_HPP
