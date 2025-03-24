#include "NumberSorter.hpp"
#include <iostream>
#include <algorithm>

void NumberSorter::readFromConsole() {
    int count;
    std::cout << "请输入要处理的整数个数：";
    std::cin >> count;
    
    std::cout << "请依次输入" << count << "个整数：" << std::endl;
    for (int i = 0; i < count; i++) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
}

void NumberSorter::sortAndPrint() const {
    if (numbers.empty()) {
        std::cout << "没有数据可排序！" << std::endl;
        return;
    }
    
    // 复制数据以保持原始数据不变
    std::vector<int> sorted = numbers;
    
    // 使用algorithm库的sort函数排序
    std::sort(sorted.begin(), sorted.end());
    
    std::cout << "使用sort函数排序结果(不去重)：" << std::endl;
    for (const auto& num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void NumberSorter::sortUniqueAndPrint() const {
    if (numbers.empty()) {
        std::cout << "没有数据可排序！" << std::endl;
        return;
    }
    
    // 使用set自动排序并去重
    std::set<int> uniqueSorted(numbers.begin(), numbers.end());
    
    std::cout << "使用set排序结果(去重)：" << std::endl;
    for (const auto& num : uniqueSorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

const std::vector<int>& NumberSorter::getNumbers() const {
    return numbers;
}

void NumberSorter::addNumber(int num) {
    numbers.push_back(num);
}