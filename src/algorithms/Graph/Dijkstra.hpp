#ifndef ALGORITHM_DIJKSTRA_HPP
#define ALGORITHM_DIJKSTRA_HPP

#include <vector>
#include <queue>
#include <limits>
#include <iostream>

class Dijkstra {
public:
    // 定义边结构
    struct Edge {
        int to;      // 目标节点
        int weight;  // 边权重
        Edge(const int t, const int w) : to(t), weight(w) {}
    };

    // 定义图结构
    using Graph = std::vector<std::vector<Edge>>;

    // 执行Dijkstra算法
    static std::vector<int> findShortestPath(const Graph& graph, int start);

    // 打印最短路径结果
    static void printResult(const std::vector<int>& dist, int start);

private:
    // 优先队列中的节点
    struct Node {
        int vertex;
        int distance;
        Node(const int v, const int d) : vertex(v), distance(d) {}
        bool operator>(const Node& other) const {
            return distance > other.distance;
        }
    };
};

#endif //ALGORITHM_DIJKSTRA_HPP

