//
// Created by Kurna on 2026/1/8.
//

#include "PolynomialMultiplication.hpp"
#include <algorithm>
#include <cmath>

/**
 * 改进过的分治多项式乘法，时间复杂度为O(n^log(3))
 */

// 静态成员变量初始化（类外必须初始化）
int PolynomialMultiplication::len_1 = 0;
int PolynomialMultiplication::len_2 = 0;

std::vector<int> PolynomialMultiplication::solve(std::vector<int> &vec_1, std::vector<int> &vec_2) {
    len_1 = vec_1.size() - 1;
    len_2 = vec_2.size() - 1;
    return polyMult(vec_1, vec_2, 0, len_1 - 1, 0, len_2 - 1);
}

std::vector<int> PolynomialMultiplication::polyMult(std::vector<int> &vec_1, std::vector<int> &vec_2, int l_1, int r_1, int l_2, int r_2) {
    // 未实现
    return {};
}
