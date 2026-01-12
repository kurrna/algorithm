//
// Created by Kurna on 2026/1/12.
//

#include "HuffmanCode.hpp"
#include <queue>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


struct HuffmanNode {
    int freq;         // 频率
    HuffmanNode* left;  // 左子节点
    HuffmanNode* right; // 右子节点
    int orig_index;    // 原始符号的索引（叶子节点有效），内部节点为-1

    // 叶子节点构造
    HuffmanNode(int f, int idx) : freq(f), left(nullptr), right(nullptr), orig_index(idx) {}
    // 中间节点构造
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) : freq(f), left(l), right(r), orig_index(-1) {}
};

// 比较器：按节点频率比较（用于最小堆）
struct PtrCompare {
    bool operator()(const HuffmanNode* a, const HuffmanNode* b) const {
        return a->freq > b->freq; // 频率小的优先
    }
};

// 构建霍夫曼树（返回根指针）。当输入为空时返回 nullptr。
HuffmanNode* buildHuffmanTree(const std::vector<int>& F) {
    int n = static_cast<int>(F.size());
    if (n == 0) {
        return nullptr;
    }

    // 初始化最小堆，按频率比较
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, PtrCompare> minHeap;
    for (int i = 0; i < n; ++i) {
        minHeap.push(new HuffmanNode(F[i], i)); // 保留原始索引
    }

    // 合并节点直到只剩1个根节点
    while (minHeap.size() > 1) {
        HuffmanNode* x = minHeap.top(); minHeap.pop();
        HuffmanNode* y = minHeap.top(); minHeap.pop();
        auto* z = new HuffmanNode(x->freq + y->freq, x, y);
        minHeap.push(z);
    }

    return minHeap.top();
}

void printHuffmanTree(HuffmanNode* root, const std::string& code = "") {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        std::cout << "叶子节点：频率=" << root->freq << "，编码=" << code << std::endl;
        return;
    }
    printHuffmanTree(root->left, code + "0");
    printHuffmanTree(root->right, code + "1");
}

// 递归释放树节点
void freeHuffmanTree(HuffmanNode* root) {
    if (!root) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    delete root;
}

// DFS 填充 lengths：直接使用 orig_index
void dfs(HuffmanNode *root, std::vector<int> &lengths, int depth) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        // 叶子节点，记录编码长度到对应原始索引
        if (root->orig_index >= 0 && root->orig_index < static_cast<int>(lengths.size())) {
            lengths[root->orig_index] = depth;
        }
    } else {
        dfs(root->left, lengths, depth + 1);
        dfs(root->right, lengths, depth + 1);
    }
}

std::vector<int> HuffmanCode::solve(std::vector<int> freqs) {
    if (freqs.empty()) return {};

    auto root = buildHuffmanTree(freqs);
    if (!root) return {};

    size_t n = freqs.size();
    std::vector<int> res(n, 0);

    // 单个符号时定义编码长度为1
    if (root->left == nullptr && root->right == nullptr) {
        if (root->orig_index >= 0 && root->orig_index < static_cast<int>(n))
            res[root->orig_index] = 1;
        freeHuffmanTree(root);
        return res;
    }

    // 可选打印树（调试）
    printHuffmanTree(root);

    dfs(root, res, 0);

    freeHuffmanTree(root);
    return res;
}
