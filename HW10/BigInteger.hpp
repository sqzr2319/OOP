#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP

#include <string>
#include <iostream>

class BigInteger {
private:
    std::string number; // �洢�������ַ�����ʾ
    bool isNegative;    // ���ű�־��true��ʾ����

    // ��������
    void removeLeadingZeros();
    static std::string addStrings(const std::string& num1, const std::string& num2);
    static std::string subtractStrings(const std::string& num1, const std::string& num2);
    static bool isLarger(const std::string& num1, const std::string& num2);

public:
    // ���캯��
    BigInteger();                           // Ĭ�Ϲ��캯��
    BigInteger(const std::string& num);     // �ַ������캯��
    BigInteger(long long num);              // �������캯��
    BigInteger(const BigInteger& other);    // �������캯��

    // ���������
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
    
    // �������
    void print() const;
    std::string toString() const;
    
    // ��Ԫ�������������
    friend std::ostream& operator<<(std::ostream& out, const BigInteger& num);
};

#endif // BIGINTEGER_HPP