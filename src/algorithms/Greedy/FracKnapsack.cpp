//
// Created by Kurna on 2026/1/12.
//

#include "FracKnapsack.hpp"
#include <algorithm>
#include <stdexcept>

struct Item {
    double vol;
    double val;
    double ratio;
};

double FracKnapsack::solve(const std::vector<double>& volumes, const std::vector<double>& prices, double C) {
    if (C <= 0) return 0.0;
    if (volumes.size() != prices.size()) {
        throw std::invalid_argument("volumes and prices must have the same length");
    }
    size_t n = volumes.size();
    if (n == 0) return 0.0;

    std::vector<Item> items;
    items.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        if (volumes[i] <= 0) continue; // 忽略非正体积
        items.push_back({volumes[i], prices[i], prices[i] / volumes[i]});
    }

    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio; // 降序
    });

    double remaining = C;
    double totalValue = 0.0;
    for (const auto& it : items) {
        if (remaining <= 0) break;
        if (it.vol <= remaining) {
            totalValue += it.val;
            remaining -= it.vol;
        } else {
            // 取部分
            totalValue += it.ratio * remaining;
            remaining = 0;
        }
    }

    return totalValue;
}
