#ifndef ALGORITHM_KRUSKALTEST_HPP
#define ALGORITHM_KRUSKALTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/Kruskal.hpp"

class KruskalTest : public TestBase {
public:
    void run() override {
        printHeader("测试Kruskal算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("Kruskal");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "Kruskal";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：简单连通无向图" << std::endl;

        // 与 PrimTest 中相同的图
        int n = 5;
        std::vector<Kruskal::Edge> edges;
        edges.emplace_back(0,1,2);
        edges.emplace_back(0,3,6);
        edges.emplace_back(1,2,3);
        edges.emplace_back(1,3,8);
        edges.emplace_back(1,4,5);
        edges.emplace_back(2,4,7);
        edges.emplace_back(3,4,9);

        std::vector<int> expected = {-1, 0, 1, 0, 1};
        auto actual = Kruskal::solve(n, edges);

        std::cout << "Parent 数组: ";
        TestBase::printVector(actual);

        return assertVectorEquals(actual, expected, "Kruskal MST 父节点");
    }

};

#endif //ALGORITHM_KRUSKALTEST_HPP
