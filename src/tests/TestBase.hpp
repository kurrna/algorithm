#ifndef ALGORITHM_TESTBASE_HPP
#define ALGORITHM_TESTBASE_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * 测试基类
 * 所有算法测试类都应该继承此类
 */
class TestBase {
public:
    virtual ~TestBase() = default;

    // 纯虚函数：运行测试
    virtual void run() = 0;

    // 获取测试名称
    [[nodiscard]] virtual std::string getName() const = 0;

protected:
    // 辅助函数：打印测试标题
    static void printHeader(const std::string& title) {
        std::cout << "========== " << title << " ==========" << std::endl;
    }

    // 辅助函数：打印分隔线
    static void printSeparator() {
        std::cout << std::endl;
    }

    // 对拍功能：验证向量结果
    template<typename T>
    static bool assertVectorEquals(const std::vector<T>& actual, const std::vector<T>& expected,
                                   const std::string& testName = "测试") {
        const bool passed = (actual == expected);

        std::cout << testName << ": ";
        if (passed) {
            std::cout << "✓ 通过" << std::endl;
        } else {
            std::cout << "✗ 失败" << std::endl;
            std::cout << "  期望输出: ";
            printVector(expected);
            std::cout << "  实际输出: ";
            printVector(actual);
        }

        return passed;
    }

    // 对拍功能：验证单个值
    template<typename T>
    static bool assertEquals(const T& actual, const T& expected,
                            const std::string& testName = "测试") {
        const bool passed = (actual == expected);

        std::cout << testName << ": ";
        if (passed) {
            std::cout << "✓ 通过" << std::endl;
        } else {
            std::cout << "✗ 失败" << std::endl;
            std::cout << "  期望输出: " << expected << std::endl;
            std::cout << "  实际输出: " << actual << std::endl;
        }

        return passed;
    }

    // 打印向量内容
    template<typename T>
    static void printVector(const std::vector<T>& vec) {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    // 统计测试通过情况
    struct TestStats {
        int passed = 0;
        int failed = 0;

        void recordResult(bool result) {
            if (result) passed++;
            else failed++;
        }

        void printSummary(const std::string& algorithmName = "") const {
            int total = passed + failed;
            std::cout << "\n" << (algorithmName.empty() ? "" : algorithmName + " ")
                      << "测试统计: " << passed << "/" << total << " 通过";
            if (failed > 0) {
                std::cout << " (" << failed << " 失败)";
            }
            std::cout << std::endl;
        }
    };
};

#endif //ALGORITHM_TESTBASE_HPP

