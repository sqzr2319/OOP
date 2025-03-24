#include "NumberSorter.hpp"
#include <iostream>
#include <algorithm>

void NumberSorter::readFromConsole() {
    int count;
    std::cout << "������Ҫ���������������";
    std::cin >> count;
    
    std::cout << "����������" << count << "��������" << std::endl;
    for (int i = 0; i < count; i++) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
}

void NumberSorter::sortAndPrint() const {
    if (numbers.empty()) {
        std::cout << "û�����ݿ�����" << std::endl;
        return;
    }
    
    // ���������Ա���ԭʼ���ݲ���
    std::vector<int> sorted = numbers;
    
    // ʹ��algorithm���sort��������
    std::sort(sorted.begin(), sorted.end());
    
    std::cout << "ʹ��sort����������(��ȥ��)��" << std::endl;
    for (const auto& num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void NumberSorter::sortUniqueAndPrint() const {
    if (numbers.empty()) {
        std::cout << "û�����ݿ�����" << std::endl;
        return;
    }
    
    // ʹ��set�Զ�����ȥ��
    std::set<int> uniqueSorted(numbers.begin(), numbers.end());
    
    std::cout << "ʹ��set������(ȥ��)��" << std::endl;
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