#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
算法类和测试文件生成脚本
用于快速创建新的算法实现和测试文件
"""

import os
import sys
from datetime import datetime


def get_current_date():
    """获取当前日期，格式：2026/1/5"""
    return datetime.now().strftime("%Y/%-m/%-d") if os.name != 'nt' else datetime.now().strftime("%Y/%#m/%#d")


def create_hpp_template(algorithm_name):
    """创建 .hpp 文件模板"""
    date_str = get_current_date()
    upper_name = algorithm_name.upper()
    
    return f"""//
// Created by Kurna on {date_str}.
//

#ifndef ALGORITHM_{upper_name}_HPP
#define ALGORITHM_{upper_name}_HPP

#include <vector>

class {algorithm_name} {{
public:
    
private:
    
}};


#endif //ALGORITHM_{upper_name}_HPP
"""


def create_cpp_template(algorithm_name):
    """创建 .cpp 文件模板"""
    date_str = get_current_date()
    
    return f"""//
// Created by Kurna on {date_str}.
//

#include "{algorithm_name}.hpp"
"""


def create_test_template(algorithm_name):
    """创建测试文件模板"""
    upper_name = algorithm_name.upper()
    
    return f"""#ifndef ALGORITHM_{upper_name}TEST_HPP
#define ALGORITHM_{upper_name}TEST_HPP

#include "TestBase.hpp"
#include "../algorithms/{algorithm_name}.hpp"

class {algorithm_name}Test : public TestBase {{
public:
    void run() override {{
        printHeader("测试{algorithm_name}算法");

        TestStats stats;
        stats.recordResult(testCase1());
        
        stats.printSummary("{algorithm_name}");

        printSeparator();
    }}

    [[nodiscard]] std::string getName() const override {{
        return "{algorithm_name}";
    }}

private:
    static bool testCase1() {{
        std::cout << "测试用例1：" << std::endl;

        std::vector<int> input = {{}};
        std::vector<int> expect = {{}};
        auto actual = {algorithm_name}::solve(input);
        
        return assertVectorEquals(actual, expected);
    }}

}};

#endif //ALGORITHM_{upper_name}TEST_HPP
"""


def validate_algorithm_name(name):
    """验证算法名称是否合法（必须是有效的C++类名）"""
    if not name:
        return False, "算法名称不能为空"
    
    if not name[0].isalpha() and name[0] != '_':
        return False, "算法名称必须以字母或下划线开头"
    
    if not all(c.isalnum() or c == '_' for c in name):
        return False, "算法名称只能包含字母、数字和下划线"
    
    return True, ""


def check_file_exists(algorithm_name, base_path):
    """检查文件是否已存在"""
    algorithms_path = os.path.join(base_path, "src", "algorithms")
    tests_path = os.path.join(base_path, "src", "tests")
    
    hpp_file = os.path.join(algorithms_path, f"{algorithm_name}.hpp")
    cpp_file = os.path.join(algorithms_path, f"{algorithm_name}.cpp")
    test_file = os.path.join(tests_path, f"{algorithm_name}Test.hpp")
    
    existing_files = []
    if os.path.exists(hpp_file):
        existing_files.append(f"{algorithm_name}.hpp")
    if os.path.exists(cpp_file):
        existing_files.append(f"{algorithm_name}.cpp")
    if os.path.exists(test_file):
        existing_files.append(f"{algorithm_name}Test.hpp")
    
    return existing_files


def create_algorithm_files(algorithm_name, base_path=".", force=False):
    """
    创建算法文件
    
    Args:
        algorithm_name: 算法名称
        base_path: 项目根路径
        force: 是否强制覆盖已存在的文件
    """
    # 验证算法名称
    valid, error_msg = validate_algorithm_name(algorithm_name)
    if not valid:
        print(f"错误：{error_msg}")
        return False
    
    # 检查文件是否已存在
    existing_files = check_file_exists(algorithm_name, base_path)
    if existing_files and not force:
        print(f"警告：以下文件已存在：")
        for file in existing_files:
            print(f"  - {file}")
        response = input("是否覆盖这些文件？(y/N): ")
        if response.lower() != 'y':
            print("操作已取消")
            return False
    
    # 确定文件路径
    algorithms_path = os.path.join(base_path, "src", "algorithms")
    tests_path = os.path.join(base_path, "src", "tests")
    
    # 确保目录存在
    os.makedirs(algorithms_path, exist_ok=True)
    os.makedirs(tests_path, exist_ok=True)
    
    # 创建文件
    files_created = []
    
    try:
        # 创建 .hpp 文件
        hpp_file = os.path.join(algorithms_path, f"{algorithm_name}.hpp")
        with open(hpp_file, 'w', encoding='utf-8') as f:
            f.write(create_hpp_template(algorithm_name))
        files_created.append(hpp_file)
        print(f"✓ 已创建: {algorithm_name}.hpp")
        
        # 创建 .cpp 文件
        cpp_file = os.path.join(algorithms_path, f"{algorithm_name}.cpp")
        with open(cpp_file, 'w', encoding='utf-8') as f:
            f.write(create_cpp_template(algorithm_name))
        files_created.append(cpp_file)
        print(f"✓ 已创建: {algorithm_name}.cpp")
        
        # 创建测试文件
        test_file = os.path.join(tests_path, f"{algorithm_name}Test.hpp")
        with open(test_file, 'w', encoding='utf-8') as f:
            f.write(create_test_template(algorithm_name))
        files_created.append(test_file)
        print(f"✓ 已创建: {algorithm_name}Test.hpp")
        
        print(f"\n成功创建 {algorithm_name} 的所有文件！")
        print("\n提示：")
        print(f"1. 在 {algorithm_name}.hpp 和 {algorithm_name}.cpp 中实现你的算法")
        print(f"2. 在 {algorithm_name}Test.hpp 中添加测试用例")
        print("3. 记得在 CMakeLists.txt 中添加新的源文件（如果需要）")
        
        return True
        
    except Exception as e:
        print(f"错误：创建文件时出错 - {e}")
        # 清理已创建的文件
        for file in files_created:
            try:
                if os.path.exists(file):
                    os.remove(file)
            except:
                pass
        return False


def main():
    """主函数"""
    print("=" * 60)
    print("算法文件生成工具")
    print("=" * 60)
    
    # 获取脚本所在目录作为项目根目录
    base_path = os.path.dirname(os.path.abspath(__file__))
    
    # 从命令行参数或用户输入获取算法名称
    if len(sys.argv) > 1:
        algorithm_name = sys.argv[1]
        force = '--force' in sys.argv or '-f' in sys.argv
    else:
        algorithm_name = input("请输入算法名称（例如：QuickSort）: ").strip()
        force = False
    
    if not algorithm_name:
        print("错误：未提供算法名称")
        return 1
    
    # 创建文件
    success = create_algorithm_files(algorithm_name, base_path, force)
    
    return 0 if success else 1


if __name__ == "__main__":
    sys.exit(main())
