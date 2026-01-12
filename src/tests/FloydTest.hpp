#ifndef ALGORITHM_FLOYDTEST_HPP
#define ALGORITHM_FLOYDTEST_HPP

#include "TestBase.hpp"
#include "../algorithms/Floyd.hpp"

class FloydTest : public TestBase {
public:
    void run() override {
        printHeader("测试Floyd算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("Floyd");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "Floyd";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：4 节点示例" << std::endl;

        const long long INF = Floyd::INF;
        // 邻接矩阵表示（权重或 INF）
        std::vector<std::vector<long long>> adj = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
        };

        auto actual = Floyd::solve(adj);

        std::vector<std::vector<long long>> expected = {
            {0, 5, 8, 9},
            {INF, 0, 3, 4},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
        };

        // 打印矩阵函数
        auto printMatrix = [](const std::vector<std::vector<long long>>& m){
            for (const auto &row : m) {
                std::cout << "[";
                for (size_t i=0;i<row.size();++i) {
                    if (row[i] >= Floyd::INF/2) std::cout << "INF";
                    else std::cout << row[i];
                    if (i+1<row.size()) std::cout << ", ";
                }
                std::cout << "]" << std::endl;
            }
        };

        std::cout << "期望最短路径矩阵:" << std::endl;
        printMatrix(expected);
        std::cout << "实际最短路径矩阵:" << std::endl;
        printMatrix(actual);

        // 对拍：逐元素比较
        if (actual.size() != expected.size()) return false;
        bool ok = true;
        for (size_t i = 0; i < expected.size(); ++i) {
            if (actual[i].size() != expected[i].size()) { ok = false; break; }
            for (size_t j = 0; j < expected[i].size(); ++j) {
                long long a = actual[i][j];
                long long b = expected[i][j];
                if ( (a>=Floyd::INF/2 && b>=Floyd::INF/2) ) continue;
                if (a != b) { ok = false; break; }
            }
            if (!ok) break;
        }

        std::cout << (ok ? "测试通过" : "测试失败") << std::endl;
        return ok;
    }

};

#endif //ALGORITHM_FLOYDTEST_HPP
