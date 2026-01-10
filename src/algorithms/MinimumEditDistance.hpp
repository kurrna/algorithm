//
// Created by Kurna on 2026/1/11.
//

#ifndef ALGORITHM_MINIMUMEDITDISTANCE_HPP
#define ALGORITHM_MINIMUMEDITDISTANCE_HPP

#include <string>
#include <vector>

class MinimumEditDistance {
public:
    // 记录回溯得到的操作序列（中文描述）
    static std::vector<std::string> editOp;

    // 求解最小编辑距离，仍然保留原签名
    static int solve(std::string &s, std::string &t);
private:
    
};


#endif //ALGORITHM_MINIMUMEDITDISTANCE_HPP
