//
// Created by Kurna on 2026/1/5.
//

/**
 * 插入排序
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 * 算法原理：
 * 1. 从第二个元素开始遍历
 * 2. 对于每个元素，将其与前面已排序的元素进行比较
 * 3. 找到正确的位置后插入（通过移动元素）
 * 4. 继续处理下一个元素
 */

#include "InsertionSort.hpp"

void InsertionSort::solve(std::vector<int> &vec) {
    // 从第二个元素开始（索引为 1）
    for (size_t i = 1; i < vec.size(); ++i) {
        // 获取待插入的元素
        int key = vec[i];

        // 与前面已排序的元素比较，找到合适的位置
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && vec[j] > key) {
            // 将较大的元素向后移动
            vec[j + 1] = vec[j];
            --j;
        }

        // 在正确位置插入元素
        vec[j + 1] = key;
    }
}
