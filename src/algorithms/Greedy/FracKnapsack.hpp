//
// Created by Kurna on 2026/1/12.
//

#ifndef ALGORITHM_FRACKNAPSACK_HPP
#define ALGORITHM_FRACKNAPSACK_HPP

#include <vector>

class FracKnapsack {
public:
    // 部分背包问题：返回在容量 C 下可取得的最大总价值（可以取小数）
    // volumes 和 prices 长度相同，C 为容量
    static double solve(const std::vector<double>& volumes, const std::vector<double>& prices, double C);

private:

};


#endif //ALGORITHM_FRACKNAPSACK_HPP
