#ifndef ALGORITHM_DIJKSTRATEST_H
#define ALGORITHM_DIJKSTRATEST_H

#include "TestBase.h"
#include "../algorithms/Dijkstra.h"
#include <vector>

/**
 * Dijkstra算法测试类
 */
class DijkstraTest : public TestBase {
public:
    void run() override {
        printHeader("测试Dijkstra算法");

        testSimpleGraph();

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "Dijkstra";
    }

private:
    static void testSimpleGraph() {
        std::cout << "测试简单图的最短路径：" << std::endl;

        // 创建图 (5个节点)
        // 图的结构:
        //     0 --(4)-- 1
        //     |    /    |
        //    (2) (1)   (5)
        //     | /       |
        //     2 --(8)-- 3
        //     |         |
        //    (10)      (2)
        //     |         |
        //     4 --------+

        int n = 5;  // 节点数
        Dijkstra::Graph graph(n);

        // 添加边 (无向图，需要添加双向边)
        graph[0].emplace_back(1, 4);
        graph[0].emplace_back(2, 2);

        graph[1].emplace_back(0, 4);
        graph[1].emplace_back(2, 1);
        graph[1].emplace_back(3, 5);

        graph[2].emplace_back(0, 2);
        graph[2].emplace_back(1, 1);
        graph[2].emplace_back(3, 8);
        graph[2].emplace_back(4, 10);

        graph[3].emplace_back(1, 5);
        graph[3].emplace_back(2, 8);
        graph[3].emplace_back(4, 2);

        graph[4].emplace_back(2, 10);
        graph[4].emplace_back(3, 2);

        // 从节点0开始
        int start = 0;
        std::vector<int> dist = Dijkstra::findShortestPath(graph, start);
        Dijkstra::printResult(dist, start);
    }
};

#endif //ALGORITHM_DIJKSTRATEST_H

