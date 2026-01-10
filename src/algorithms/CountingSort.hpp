//
// Created by Kurna on 2026/1/10.
//

#ifndef ALGORITHM_COUNTINGSORT_HPP
#define ALGORITHM_COUNTINGSORT_HPP

#include <vector>

class CountingSort {
public:
    // 计数排序：对整数向量进行就地升序排序。
    // 支持任意整数（会根据最小/最大值分配计数数组并做偏移）。
    static void solve(std::vector<int> &vec);
private:

};


#endif //ALGORITHM_COUNTINGSORT_HPP
