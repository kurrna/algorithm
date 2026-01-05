#ifndef ALGORITHM_TESTTEMPLATE_HPP
#define ALGORITHM_TESTTEMPLATE_HPP

#include "TestBase.hpp"
// #include "../algorithms/YourAlgorithm.hpp"  // 包含你的算法头文件

/**
 * 算法测试模板类
 *
 * 使用步骤：
 * 1. 复制此文件并重命名为 YourAlgorithmTest.hpp
 * 2. 将所有 TestTemplate 替换为 YourAlgorithmTest
 * 3. 实现 run() 方法中的测试逻辑
 * 4. 更新 getName() 返回的名称
 * 5. 在 main.cpp 中注册你的测试类
 */
class TestTemplate : public TestBase {
public:
    void run() override {
        printHeader("测试你的算法");

        // 在这里添加你的测试用例
        testCase1();
        testCase2();

        printSeparator();
    }

    [[nodiscard]] std::string getName() const override {
        return "YourAlgorithm";  // 修改为你的算法名称
    }

private:
    // 测试用例1
    static void testCase1() {
        std::cout << "测试用例1：" << std::endl;

        // 你的测试代码
        // 例如：
        // std::vector<int> input = {1, 2, 3, 4, 5};
        // auto result = YourAlgorithm::solve(input);
        // std::cout << "结果: " << result << std::endl;

        std::cout << std::endl;
    }

    // 测试用例2
    static void testCase2() {
        std::cout << "测试用例2：" << std::endl;

        // 你的测试代码

        std::cout << std::endl;
    }

    // 可以添加更多测试用例...
};

#endif //ALGORITHM_TESTTEMPLATE_HPP

