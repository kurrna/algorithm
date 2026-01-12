#ifndef ALGORITHM_PRIMTEST_HPP
#define ALGORITHM_PRIMTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/Graph/Prim.hpp"

class PrimTest : public TestBase {
public:
    void run() override {
        printHeader("测试Prim算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("Prim");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "Prim";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：简单连通无向图" << std::endl;

        // 构造图（无向图，5个顶点）
        // 边集合（无向）：
        // 0-1 (2), 0-3 (6), 1-2 (3), 1-3 (8), 1-4 (5), 2-4 (7), 3-4 (9)
        int n = 5;
        Prim::Graph graph(n);
        auto addUndirected = [&](int u, int v, int w){
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        };

        addUndirected(0,1,2);
        addUndirected(0,3,6);
        addUndirected(1,2,3);
        addUndirected(1,3,8);
        addUndirected(1,4,5);
        addUndirected(2,4,7);
        addUndirected(3,4,9);

        std::vector<int> expected = {-1, 0, 1, 0, 1};
        auto actual = Prim::solve(graph, 0);

        std::cout << "Parent 数组: ";
        TestBase::printVector(actual);

        return assertVectorEquals(actual, expected, "Prim MST 父节点");
    }

};

#endif //ALGORITHM_PRIMTEST_HPP
