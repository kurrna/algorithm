//
// Created by Kurna on 2026/1/8.
//

#ifndef ALGORITHM_POLYNOMIALMULTIPLICATION_HPP
#define ALGORITHM_POLYNOMIALMULTIPLICATION_HPP

#include <vector>

class PolynomialMultiplication {
public:
    static std::vector<int> solve(std::vector<int> &vec_1, std::vector<int> &vec_2);
private:
    static int len_1, len_2;
    static std::vector<int> polyMult(std::vector<int> &vec_1, std::vector<int> &vec_2, int l_1, int r_1, int l_2, int r_2);
};


#endif //ALGORITHM_POLYNOMIALMULTIPLICATION_HPP
