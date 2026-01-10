//
// Created by Kurna on 2026/1/10.
//

#ifndef ALGORITHM_HEAPSORT_HPP
#define ALGORITHM_HEAPSORT_HPP

#include <vector>

class Heap {
    std::vector<int> data;
    static void insert(std::vector<int> &heap, int value);
    static int extractMin(std::vector<int> &heap);
};

class HeapSort {
public:
    static void solve(std::vector<int> &vec);
private:
    static void minHeapify(std::vector<int> &heap, int n, int i);
};


#endif //ALGORITHM_HEAPSORT_HPP
