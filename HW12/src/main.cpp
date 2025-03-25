#include "IntegerParser.hpp"
#include "ParseExceptions.hpp"
#include <iostream>
#include <string>
#include <vector>

void testParser() {
    // 测试用例
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"123", "有效整数"},
        {"-456", "有效负整数"},
        {"+789", "有效带正号整数"},
        {"", "空字符串"},
        {"abc", "包含非法字符"},
        {"123a", "数字后有非法字符"},
        {"+", "只有符号"},
        {"-", "只有符号"},
        {"++123", "多个符号"},
        {"-+123", "多个符号"},
        {"123+", "符号位置不正确"},
        {"1234567890123456789", "整数溢出"}
    };
    
    std::cout << "=== 测试用例 ===" << std::endl;
    for (const auto& test : testCases) {
        std::cout << "测试: \"" << test.first << "\" (" << test.second << ") --> ";
        try {
            int result = IntegerParser::parse(test.first);
            std::cout << "有效整数: " << result << std::endl;
        } catch (const IntegerParseException& e) {
            std::cout << "异常: " << e.what() << std::endl;
        }
    }
}

int main() {
    // 运行预定义测试
    testParser();
    
    // 交互式测试
    std::cout << "\n=== 交互式测试 ===" << std::endl;
    std::string input;
    std::cout << "请输入要解析的字符串（输入'exit'退出）: ";
    
    while (std::getline(std::cin, input) && input != "exit") {
        try {
            int result = IntegerParser::parse(input);
            std::cout << "有效整数: " << result << std::endl;
        } catch (const IntegerParseException& e) {
            std::cout << "异常: " << e.what() << std::endl;
        }
        std::cout << "请输入要解析的字符串（输入'exit'退出）: ";
    }
    
    return 0;
}