#include "NumberSorter.hpp"
#include <iostream>

// ���Ժ���
void testNumberSorter() {
    // ��������1���������룬���ظ�����
    {
        NumberSorter sorter;
        // �ֶ���Ӳ������� {5, 3, 9, 1, 5, 8, 3}
        sorter.addNumber(5);
        sorter.addNumber(3);
        sorter.addNumber(9);
        sorter.addNumber(1);
        sorter.addNumber(5);
        sorter.addNumber(8);
        sorter.addNumber(3);
        
        std::cout << "��������1�����" << std::endl;
        sorter.sortAndPrint();      // Ӧ�����1 3 3 5 5 8 9
        sorter.sortUniqueAndPrint(); // Ӧ�����1 3 5 8 9
        std::cout << std::endl;
    }
    
    // ��������2��������
    {
        NumberSorter sorter;
        std::cout << "��������2����������룩��" << std::endl;
        sorter.sortAndPrint();
        sorter.sortUniqueAndPrint();
        std::cout << std::endl;
    }
    
    // ��������3��ֻ��һ������
    {
        NumberSorter sorter;
        sorter.addNumber(42);
        std::cout << "��������3������������֣���" << std::endl;
        sorter.sortAndPrint();      // Ӧ�����42
        sorter.sortUniqueAndPrint(); // Ӧ�����42
        std::cout << std::endl;
    }
}

int main() {
    // ���в���
    std::cout << "=== ���в������� ===" << std::endl;
    testNumberSorter();
    
    // ʵ�ʳ���
    std::cout << "=== ��ʼʵ�ʳ��� ===" << std::endl;
    NumberSorter sorter;
    sorter.readFromConsole();
    sorter.sortAndPrint();
    sorter.sortUniqueAndPrint();
    
    return 0;
}