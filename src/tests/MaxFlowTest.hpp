#ifndef ALGORITHM_MAXFLOWTEST_HPP
#define ALGORITHM_MAXFLOWTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/MaxFlow.hpp"

class MaxFlowTest : public TestBase {
public:
    void run() override {
        printHeader("测试MaxFlow算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("MaxFlow");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MaxFlow";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：CLRS 示例网络" << std::endl;

        int n = 6; // 节点 0..5, 源 s=0, 汇 t=5
        int s = 0, t = 5;
        std::vector<MaxFlow::Edge> edges;
        edges.emplace_back(0,1,16);
        edges.emplace_back(0,2,13);
        edges.emplace_back(1,2,10);
        edges.emplace_back(2,1,4);
        edges.emplace_back(1,3,12);
        edges.emplace_back(2,4,14);
        edges.emplace_back(3,2,9);
        edges.emplace_back(4,3,7);
        edges.emplace_back(3,5,20);
        edges.emplace_back(4,5,4);

        long long expected = 23;
        long long actual = MaxFlow::solve(n, edges, s, t);

        std::cout << "最大流: " << actual << std::endl;
        return assertEquals(actual, expected, "MaxFlow 值");
    }

};

#endif //ALGORITHM_MAXFLOWTEST_HPP
