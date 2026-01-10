//
// Created by Kurna on 2026/1/10.
//

#include "HeapSort.hpp"
#include <algorithm>

void HeapSort::solve(std::vector<int> &vec) {
    int n = static_cast<int>(vec.size());
    // 构建最小堆
    for (int i = n / 2 - 1; i >= 0; --i) {
        minHeapify(vec, n, i);
    }

    for (int i = 0; i < n; ++i) {
        // 将堆顶元素（最小值）放到最后位置
        std::swap(vec[0], vec[n - 1 - i]);
        // 重新调整堆
        minHeapify(vec, n - 1 - i, 0);
    }
    std::reverse(vec.begin(), vec.end());
}

void HeapSort::minHeapify(std::vector<int> &heap, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void Heap::insert(std::vector<int> &heap, int value) {
    heap.push_back(value);
    int i = static_cast<int>(heap.size()) - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        std::swap(heap[p], heap[i]);
        i = p;
    }
}

int Heap::extractMin(std::vector<int> &heap) {
    if (heap.empty()) return 0;
    int ret = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int n = static_cast<int>(heap.size());
    int i = 0;
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        // 与较小的孩子节点进行交换
        if (l < n && heap[l] < heap[smallest]) smallest = l;
        if (r < n && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        std::swap(heap[i], heap[smallest]);
        i = smallest;
    }
    return ret;
}

