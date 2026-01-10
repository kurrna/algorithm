//
// Created by Kurna on 2026/1/10.
//

#ifndef ALGORITHM_SELECTIONPROBLEM_HPP
#define ALGORITHM_SELECTIONPROBLEM_HPP

#include <vector>

class SelectionProblem {
public:
    static int solve(std::vector<int> &vec, int k);
private:
    static int partition(std::vector<int> &vec, int k, int start, int end);
};


#endif //ALGORITHM_SELECTIONPROBLEM_HPP
