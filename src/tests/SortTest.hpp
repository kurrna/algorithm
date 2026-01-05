#ifndef ALGORITHM_SORTTEST_HPP
#define ALGORITHM_SORTTEST_HPP

#include "TestBase.hpp"
#include <vector>

/**
 * 排序算法的通用测试基类
 * 所有排序算法测试都应该继承此类，只需实现 sort() 方法
 *
 * 使用方法：
 * class YourSortTest : public SortTest {
 * protected:
 *     void sort(std::vector<int>& vec) override {
 *         YourSort::solve(vec);  // 或者其他排序方法
 *     }
 *
 *     std::string getAlgorithmName() const override {
 *         return "YourSort";
 *     }
 * };
 */
class SortTest : public TestBase {
public:
    void run() override {
        std::string algorithmName = getAlgorithmName();
        printHeader("测试" + algorithmName + "算法");

        TestStats stats;

        // 运行所有标准测试用例
        stats.recordResult(testBasicSort());
        stats.recordResult(testSortedArray());
        stats.recordResult(testReversedArray());
        stats.recordResult(testSingleElement());
        stats.recordResult(testEmptyArray());
        stats.recordResult(testDuplicateElements());

        stats.printSummary(algorithmName);
        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return getAlgorithmName();
    }

protected:
    /**
     * 子类必须实现的排序方法
     * @param vec 待排序的向量，将被原地排序
     */
    virtual void sort(std::vector<int>& vec) = 0;

    /**
     * 子类必须实现的算法名称获取方法
     */
    [[nodiscard]] virtual std::string getAlgorithmName() const = 0;

private:
    // 测试用例1：基本排序（用户提供的样例）
    [[nodiscard]] bool testBasicSort() {
        std::cout << "\n测试用例1：基本排序" << std::endl;

        std::vector<int> input = {40, 21, 4, 48, 17, 32, 37, 28, 18, 8, 24, 47, 40, 14, 22, 13};
        std::vector<int> expected = {4, 8, 13, 14, 17, 18, 21, 22, 24, 28, 32, 37, 40, 40, 47, 48};

        std::vector<int> actual = input;
        sort(actual);

        return assertVectorEquals(actual, expected, "基本排序");
    }

    // 测试用例2：已排序数组
    [[nodiscard]] bool testSortedArray() {
        std::cout << "\n测试用例2：已排序数组" << std::endl;

        std::vector<int> input = {1, 2, 3, 4, 5};
        std::vector<int> expected = {1, 2, 3, 4, 5};

        std::vector<int> actual = input;
        sort(actual);

        return assertVectorEquals(actual, expected, "已排序数组");
    }

    // 测试用例3：逆序数组
    [[nodiscard]] bool testReversedArray() {
        std::cout << "\n测试用例3：逆序数组" << std::endl;

        std::vector<int> input = {5, 4, 3, 2, 1};
        std::vector<int> expected = {1, 2, 3, 4, 5};

        std::vector<int> actual = input;
        sort(actual);

        return assertVectorEquals(actual, expected, "逆序数组");
    }

    // 测试用例4：单个元素
    [[nodiscard]] bool testSingleElement() {
        std::cout << "\n测试用例4：单个元素" << std::endl;

        std::vector<int> input = {42};
        std::vector<int> expected = {42};

        std::vector<int> actual = input;
        sort(actual);

        return assertVectorEquals(actual, expected, "单个元素");
    }

    // 测试用例5：空数组
    [[nodiscard]] bool testEmptyArray() {
        std::cout << "\n测试用例5：空数组" << std::endl;

        std::vector<int> input = {};
        std::vector<int> expected = {};

        std::vector<int> actual = input;
        sort(actual);

        return assertVectorEquals(actual, expected, "空数组");
    }

    // 测试用例6：重复元素
    [[nodiscard]] bool testDuplicateElements() {
        std::cout << "\n测试用例6：重复元素" << std::endl;

        std::vector<int> input = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        std::vector<int> expected = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};

        std::vector<int> actual = input;
        sort(actual);

        return assertVectorEquals(actual, expected, "重复元素");
    }
};

#endif //ALGORITHM_SORTTEST_HPP

