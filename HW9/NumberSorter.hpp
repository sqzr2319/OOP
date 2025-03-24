#ifndef NUMBER_SORTER_H
#define NUMBER_SORTER_H

#include <vector>
#include <set>

class NumberSorter {
private:
    std::vector<int> numbers; // 存储输入的整数序列

public:
    // 从控制台读取整数
    void readFromConsole();
    
    // 使用sort函数排序并输出(不去重)
    void sortAndPrint() const;
    
    // 使用set排序并输出(去重)
    void sortUniqueAndPrint() const;
    
    // 获取数据，用于测试
    const std::vector<int>& getNumbers() const;
    
    // 添加数字，用于测试
    void addNumber(int num);
};

#endif // NUMBER_SORTER_H