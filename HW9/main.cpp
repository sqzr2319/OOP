#include "NumberSorter.hpp"
#include <iostream>

// 测试函数
void testNumberSorter() {
    // 测试用例1：正常输入，有重复数字
    {
        NumberSorter sorter;
        // 手动添加测试数据 {5, 3, 9, 1, 5, 8, 3}
        sorter.addNumber(5);
        sorter.addNumber(3);
        sorter.addNumber(9);
        sorter.addNumber(1);
        sorter.addNumber(5);
        sorter.addNumber(8);
        sorter.addNumber(3);
        
        std::cout << "测试用例1结果：" << std::endl;
        sorter.sortAndPrint();      // 应输出：1 3 3 5 5 8 9
        sorter.sortUniqueAndPrint(); // 应输出：1 3 5 8 9
        std::cout << std::endl;
    }
    
    // 测试用例2：空输入
    {
        NumberSorter sorter;
        std::cout << "测试用例2结果（空输入）：" << std::endl;
        sorter.sortAndPrint();
        sorter.sortUniqueAndPrint();
        std::cout << std::endl;
    }
    
    // 测试用例3：只有一个数字
    {
        NumberSorter sorter;
        sorter.addNumber(42);
        std::cout << "测试用例3结果（单个数字）：" << std::endl;
        sorter.sortAndPrint();      // 应输出：42
        sorter.sortUniqueAndPrint(); // 应输出：42
        std::cout << std::endl;
    }
}

int main() {
    // 运行测试
    std::cout << "=== 运行测试用例 ===" << std::endl;
    testNumberSorter();
    
    // 实际程序
    std::cout << "=== 开始实际程序 ===" << std::endl;
    NumberSorter sorter;
    sorter.readFromConsole();
    sorter.sortAndPrint();
    sorter.sortUniqueAndPrint();
    
    return 0;
}