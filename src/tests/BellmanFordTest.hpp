#ifndef ALGORITHM_BELLMANFORDTEST_HPP
#define ALGORITHM_BELLMANFORDTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/BellmanFord.hpp"

class BellmanFordTest : public TestBase {
public:
    void run() override {
        printHeader("测试BellmanFord算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("BellmanFord");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "BellmanFord";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：CLRS 示例（含负权边，无负环）" << std::endl;

        // 顶点 0..4
        int n = 5;
        std::vector<BellmanFord::Edge> edges;
        edges.emplace_back(0,1,-1);
        edges.emplace_back(0,2,4);
        edges.emplace_back(1,2,3);
        edges.emplace_back(1,3,2);
        edges.emplace_back(1,4,2);
        edges.emplace_back(3,2,5);
        edges.emplace_back(3,1,1);
        edges.emplace_back(4,3,-3);

        auto res = BellmanFord::solve(n, edges, 0);

        std::vector<long long> expectedDist = {0, -1, 2, -2, 1};
        std::vector<int> expectedParent = {-1, 0, 1, 4, 1};

        std::cout << "Distances: "; TestBase::printVector(res.dist);
        std::cout << "Parent: "; TestBase::printVector(res.parent);

        bool ok = true;
        ok &= assertVectorEquals(res.dist, expectedDist, "最短距离");
        ok &= assertVectorEquals(res.parent, expectedParent, "前驱数组");
        ok &= assertEquals(res.hasNegativeCycle, false, "是否存在负权回路");

        return ok;
    }

};

#endif //ALGORITHM_BELLMANFORDTEST_HPP
