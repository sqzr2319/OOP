#ifndef NUMBER_SORTER_H
#define NUMBER_SORTER_H

#include <vector>
#include <set>

class NumberSorter {
private:
    std::vector<int> numbers; // �洢�������������

public:
    // �ӿ���̨��ȡ����
    void readFromConsole();
    
    // ʹ��sort�����������(��ȥ��)
    void sortAndPrint() const;
    
    // ʹ��set�������(ȥ��)
    void sortUniqueAndPrint() const;
    
    // ��ȡ���ݣ����ڲ���
    const std::vector<int>& getNumbers() const;
    
    // ������֣����ڲ���
    void addNumber(int num);
};

#endif // NUMBER_SORTER_H