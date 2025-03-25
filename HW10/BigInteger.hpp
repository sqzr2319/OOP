#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP

#include <string>
#include <iostream>

class BigInteger {
private:
    std::string number; // 存储整数的字符串表示
    bool isNegative;    // 符号标志，true表示负数

    // 辅助函数
    void removeLeadingZeros();
    static std::string addStrings(const std::string& num1, const std::string& num2);
    static std::string subtractStrings(const std::string& num1, const std::string& num2);
    static bool isLarger(const std::string& num1, const std::string& num2);

public:
    // 构造函数
    BigInteger();                           // 默认构造函数
    BigInteger(const std::string& num);     // 字符串构造函数
    BigInteger(long long num);              // 整数构造函数
    BigInteger(const BigInteger& other);    // 拷贝构造函数

    // 运算符重载
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
    
    // 输出函数
    void print() const;
    std::string toString() const;
    
    // 友元函数，用于输出
    friend std::ostream& operator<<(std::ostream& out, const BigInteger& num);
};

#endif // BIGINTEGER_HPP