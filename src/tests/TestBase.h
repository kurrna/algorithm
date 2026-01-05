#ifndef ALGORITHM_TESTBASE_H
#define ALGORITHM_TESTBASE_H

#include <iostream>
#include <string>

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
};

#endif //ALGORITHM_TESTBASE_H

