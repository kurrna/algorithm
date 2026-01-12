#ifndef ALGORITHM_HUFFMANCODETEST_HPP
#define ALGORITHM_HUFFMANCODETEST_HPP

#include "TestBase.hpp"
#include "../algorithms/HuffmanCode.hpp"

class HuffmanCodeTest : public TestBase {
public:
    void run() override {
        printHeader("测试HuffmanCode算法");

        TestStats stats;
        stats.recordResult(testCase1());

        stats.printSummary("HuffmanCode");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "HuffmanCode";
    }

private:
    // 经典示例：频率 {5,9,12,13,16,45} 的最小编码代价为 224
    static bool testCase1() {
        std::cout << "测试用例2：经典示例" << std::endl;

        std::vector<int> freqs = {5, 9, 12, 13, 16, 45};
        auto lengths = HuffmanCode::solve(freqs);
        // 计算总代价
        long long cost = 0;
        for (size_t i = 0; i < freqs.size(); ++i) {
            cost += static_cast<long long>(freqs[i]) * lengths[i];
        }
        long long expectedCost = 224;
        return assertEquals(cost, expectedCost, "Total cost");
    }

};

#endif //ALGORITHM_HUFFMANCODETEST_HPP
