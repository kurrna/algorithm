#include "Dijkstra.hpp"

std::vector<int> Dijkstra::findShortestPath(const Graph& graph, int start) {
    const size_t n = graph.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    dist[start] = 0;
    pq.emplace(start, 0);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        int d = current.distance;

        // 如果已经找到更短的路径，跳过
        if (d > dist[u]) continue;

        // 遍历所有邻接边
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // 松弛操作
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(v, dist[v]);
            }
        }
    }

    return dist;
}

void Dijkstra::printResult(const std::vector<int>& dist, int start) {
    std::cout << "从节点 " << start << " 到各节点的最短距离:" << std::endl;
    for (size_t i = 0; i < dist.size(); i++) {
        std::cout << "  到节点 " << i << ": ";
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << "不可达" << std::endl;
        } else {
            std::cout << dist[i] << std::endl;
        }
    }
}

