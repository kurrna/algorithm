#include "./tests/TestManager.hpp"

// 在这里包含更多测试类
#include "tests/FloydTest.hpp"

int main() {
    // 获取测试管理器实例
    TestManager& manager = TestManager::getInstance();

    // 注册所有测试
    // 注册更多测试（添加新算法时，只需在这里添加一行）
    manager.registerTest(std::make_shared<FloydTest>());

    // 运行所有测试
    manager.runAll();

    return 0;
}
