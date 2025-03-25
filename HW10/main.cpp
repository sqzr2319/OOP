#include <iostream>
#include "BigInteger.hpp"

void testAddition() {
    std::cout << "===== ���Լӷ����� =====" << std::endl;
    
    // ���԰���1�����������
    BigInteger a1("0");
    BigInteger b1("0");
    std::cout << "����1 (0 + 0): " << a1 << " + " << b1 << " = " << (a1 + b1) << std::endl;
    
    // ���԰���2�������������
    BigInteger a2("123");
    BigInteger b2("0");
    std::cout << "����2 (���� + 0): " << a2 << " + " << b2 << " = " << (a2 + b2) << std::endl;
    
    // ���԰���3�������������
    BigInteger a3("123");
    BigInteger b3("456");
    std::cout << "����3 (���� + ����): " << a3 << " + " << b3 << " = " << (a3 + b3) << std::endl;
    
    // ���԰���4�������������
    BigInteger a4("-123");
    BigInteger b4("-456");
    std::cout << "����4 (���� + ����): " << a4 << " + " << b4 << " = " << (a4 + b4) << std::endl;
    
    // ���԰���5�������븺�����
    BigInteger a5("123");
    BigInteger b5("-456");
    std::cout << "����5 (���� + ����): " << a5 << " + " << b5 << " = " << (a5 + b5) << std::endl;
}

void testSubtraction() {
    std::cout << "\n===== ���Լ������� =====" << std::endl;
    
    // ���԰���1��0 - 0
    BigInteger a1("0");
    BigInteger b1("0");
    std::cout << "����1 (0 - 0): " << a1 << " - " << b1 << " = " << (a1 - b1) << std::endl;
    
    // ���԰���2������ - 0
    BigInteger a2("123");
    BigInteger b2("0");
    std::cout << "����2 (���� - 0): " << a2 << " - " << b2 << " = " << (a2 - b2) << std::endl;
    
    // ���԰���3������ - ���������Ϊ����
    BigInteger a3("456");
    BigInteger b3("123");
    std::cout << "����3 (���� - ���������Ϊ��): " << a3 << " - " << b3 << " = " << (a3 - b3) << std::endl;
    
    // ���԰���4������ - ���������Ϊ����
    BigInteger a4("123");
    BigInteger b4("456");
    std::cout << "����4 (���� - ���������Ϊ��): " << a4 << " - " << b4 << " = " << (a4 - b4) << std::endl;
    
    // ���԰���5������ - ����
    BigInteger a5("-123");
    BigInteger b5("-456");
    std::cout << "����5 (���� - ����): " << a5 << " - " << b5 << " = " << (a5 - b5) << std::endl;
}

int main() {
    testAddition();
    testSubtraction();
    
    return 0;
}