//
// Created by Kurna on 2026/1/8.
//

#ifndef ALGORITHM_COUNTINGINVERSION_HPP
#define ALGORITHM_COUNTINGINVERSION_HPP

#include <vector>

class CountingInversion{
public:
    static int solve(std::vector<int> vec);
private:
    static std::vector<int> temp;

    static int mergeSortAndCount(std::vector<int> &vec, int l, int r);

    static int mergeAndCount(std::vector<int> &vec, int l, int mid, int r);
};


#endif //ALGORITHM_COUNTINGINVERSION_HPP
