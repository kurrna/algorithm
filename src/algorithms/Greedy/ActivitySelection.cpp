//
// Created by Kurna on 2026/1/12.
//

#include "ActivitySelection.hpp"
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

struct Activity {
    int s;
    int f;
    int w;
    int idx;
};

std::vector<int> ActivitySelection::solve(const std::vector<int>& times) {
    std::vector<int> res;
    if (times.empty()) return res;
    if (times.size() % 2 != 0) return res; // 非法输入，返回空

    int n = static_cast<int>(times.size() / 2);
    std::vector<Activity> acts;
    acts.reserve(n);
    for (int i = 0; i < n; ++i) {
        int s = times[2*i];
        int f = times[2*i + 1];
        acts.push_back({s, f, 0, i});
    }

    // 按结束时间递增排序（若结束时间相同，可按开始时间或索引）
    std::sort(acts.begin(), acts.end(), [](const Activity &a, const Activity &b) {
        if (a.f != b.f) return a.f < b.f;
        if (a.s != b.s) return a.s < b.s;
        return a.idx < b.idx;
    });

    // 选择活动
    int last_finish = std::numeric_limits<int>::min();
    for (const auto &act : acts) {
        if (act.s >= last_finish) {
            res.push_back(act.idx);
            last_finish = act.f;
        }
    }

    return res;
}

// 帮助函数：对排序后的 activities，找到对每个 j (0-based) 的 p[j]，即最多不冲突的前一个活动索引
static std::vector<int> computePrevious(const std::vector<Activity>& acts) {
    int n = static_cast<int>(acts.size());
    std::vector<int> finishTimes(n);
    for (int i = 0; i < n; ++i) finishTimes[i] = acts[i].f;

    std::vector<int> p(n, -1);
    for (int j = 0; j < n; ++j) {
        int sj = acts[j].s;
        // 在 finishTimes 中找到最大的 i < j 使得 finishTimes[i] <= sj
        int l = 0, r = j - 1, ans = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (finishTimes[mid] <= sj) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        p[j] = ans;
    }
    return p;
}

std::vector<int> ActivitySelection::solveWeighted(const std::vector<int>& starts,
                                                  const std::vector<int>& finishes,
                                                  const std::vector<int>& weights) {
    size_t n = starts.size();
    if (n == 0) return {};
    if (finishes.size() != n || weights.size() != n) throw std::invalid_argument("starts, finishes, weights must have same length");

    std::vector<Activity> acts;
    acts.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        acts.push_back({starts[i], finishes[i], weights[i], static_cast<int>(i)});
    }

    // 按结束时间排序
    std::sort(acts.begin(), acts.end(), [](const Activity &a, const Activity &b) {
        if (a.f != b.f) return a.f < b.f;
        if (a.s != b.s) return a.s < b.s;
        return a.idx < b.idx;
    });

    // 计算 p[j]
    auto p = computePrevious(acts);
    int m = static_cast<int>(acts.size());

    // DP: dp[j] 表示前 j 个活动（acts[0..j-1]）的最优权重
    // 使用 1-based indexing for dp for simplicity: dp[0]=0, dp[j]=max(w[j-1]+dp[p[j-1]+1], dp[j-1])
    std::vector<long long> dp(m+1, 0);
    std::vector<int> rec(m+1, 0); // 1 表示选择第 j-1，0 表示不选择

    for (int j = 1; j <= m; ++j) {
        long long incl = acts[j-1].w + ( (p[j-1] == -1) ? 0 : dp[p[j-1]+1] );
        long long excl = dp[j-1];
        if (incl > excl) {
            dp[j] = incl;
            rec[j] = 1;
        } else {
            dp[j] = excl;
            rec[j] = 0;
        }
    }

    // 重构选中的活动索引（按时间倒序），然后反转为按选择顺序
    std::vector<int> chosen;
    int j = m;
    while (j > 0) {
        if (rec[j] == 1) {
            // 选择 activities[j-1]
            chosen.push_back(acts[j-1].idx);
            j = (p[j-1] == -1) ? 0 : (p[j-1] + 1);
        } else {
            j = j - 1;
        }
    }
    std::reverse(chosen.begin(), chosen.end());
    return chosen;
}
