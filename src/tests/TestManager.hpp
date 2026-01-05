#ifndef ALGORITHM_TESTMANAGER_HPP
#define ALGORITHM_TESTMANAGER_HPP

#include <vector>
#include <memory>
#include "TestBase.hpp"

/**
 * 测试管理器
 * 负责管理和运行所有测试
 */
class TestManager {
public:
    // 获取单例实例
    static TestManager& getInstance() {
        static TestManager instance;
        return instance;
    }

    // 注册测试
    void registerTest(const std::shared_ptr<TestBase>& test) {
        tests.push_back(test);
    }

    // 运行所有测试
    void runAll() const {
        printWelcome();

        for (const auto& test : tests) {
            test->run();
        }

        printComplete();
    }

    // 运行指定测试
    void runTest(const std::string& name) const {
        for (const auto& test : tests) {
            if (test->getName() == name) {
                test->run();
                return;
            }
        }
        std::cout << "测试 '" << name << "' 未找到！" << std::endl;
    }

    // 列出所有测试
    void listTests() const {
        std::cout << "可用的测试：" << std::endl;
        for (size_t i = 0; i < tests.size(); i++) {
            std::cout << "  " << (i + 1) << ". " << tests[i]->getName() << std::endl;
        }
    }

private:
    TestManager() = default;
    std::vector<std::shared_ptr<TestBase>> tests;

    static void printWelcome() {
        std::cout << "============================================" << std::endl;
        std::cout << "            Kurna 的算法实现测试！             " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
    }

    static void printComplete() {
        std::cout << "============================================" << std::endl;
        std::cout << "                 测试完成！                   " << std::endl;
        std::cout << "============================================" << std::endl;
    }
};

#endif //ALGORITHM_TESTMANAGER_HPP

