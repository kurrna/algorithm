#ifndef ALGORITHM_MATRIXCHAINMULTEST_HPP
#define ALGORITHM_MATRIXCHAINMULTEST_HPP

#include "../TestBase.hpp"
#include "../../algorithms/DP/MatrixChainMul.hpp"

class MatrixChainMulTest : public TestBase {
public:
    void run() override {
        printHeader("测试MatrixMul算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("MatrixMul");

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "MatrixMul";
    }

private:
    static bool testCase1() {
        std::cout << "测试用例1：CLRS 示例" << std::endl;

        // 维度数组 p0..pn，来自 CLRS 示例
        std::vector<int> input = {30, 35, 15, 5, 10, 20, 25};
        std::vector<int> expected = {15125};
        auto actual = MatrixChainMul::solve(input);

        std::cout << "最小标量乘法次数: ";
        TestBase::printVector(actual);
        printParentheses(MatrixChainMul::s, 1, static_cast<int>(input.size()) - 1);
        return assertVectorEquals(actual, expected);
    }

    static void printParentheses(const std::vector<std::vector<int>>& s, int i, int j) {
        if (i == j) {
            std::cout << "A" << i;
        } else {
            std::cout << "(";
            printParentheses(s, i, s[i][j]);
            printParentheses(s, s[i][j] + 1, j);
            std::cout << ")";
        }
    }

};

#endif //ALGORITHM_MATRIXCHAINMULTEST_HPP
