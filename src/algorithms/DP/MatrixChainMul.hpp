//
// Created by Kurna on 2026/1/11.
//

#ifndef ALGORITHM_MATRIXCHAINMUL_HPP
#define ALGORITHM_MATRIXCHAINMUL_HPP

#include <vector>

class MatrixChainMul {
public:
    // 输入 p 为长度 n+1 的维度数组（p0..pn），返回一个 vector<int>，其中第一个元素为最小标量乘法次数
    // 如果输入无效（长度 < 2），返回空向量。
    static std::vector<int> solve(const std::vector<int>& p);

    // 可选：记录分割点，s[i][j] 表示在最优分割中 i..j 的分割点 k
    static std::vector<std::vector<int>> s;

private:

};


#endif //ALGORITHM_MATRIXCHAINMUL_HPP
