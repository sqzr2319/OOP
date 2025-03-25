#include "BigInteger.hpp"
#include <algorithm>

// 默认构造函数
BigInteger::BigInteger() : number("0"), isNegative(false) {}

// 字符串构造函数
BigInteger::BigInteger(const std::string& num) {
    if (num.empty()) {
        number = "0";
        isNegative = false;
        return;
    }

    // 处理符号
    if (num[0] == '-') {
        isNegative = true;
        number = num.substr(1);
    } else if (num[0] == '+') {
        isNegative = false;
        number = num.substr(1);
    } else {
        isNegative = false;
        number = num;
    }

    // 移除前导零
    removeLeadingZeros();
    
    // 特殊处理零
    if (number == "0") {
        isNegative = false;
    }
}

// 整数构造函数
BigInteger::BigInteger(long long num) {
    if (num < 0) {
        isNegative = true;
        num = -num;
    } else {
        isNegative = false;
    }

    if (num == 0) {
        number = "0";
    } else {
        number = "";
        while (num > 0) {
            number = static_cast<char>('0' + num % 10) + number;
            num /= 10;
        }
    }
}

// 拷贝构造函数
BigInteger::BigInteger(const BigInteger& other) 
    : number(other.number), isNegative(other.isNegative) {}

// 移除前导零
void BigInteger::removeLeadingZeros() {
    // 找到第一个非零字符
    size_t firstNonZero = 0;
    while (firstNonZero < number.size() && number[firstNonZero] == '0') {
        firstNonZero++;
    }

    // 如果全是零，保留一个零
    if (firstNonZero == number.size()) {
        number = "0";
    } else {
        number = number.substr(firstNonZero);
    }
}

// 比较两个正数字符串的大小
bool BigInteger::isLarger(const std::string& num1, const std::string& num2) {
    if (num1.length() != num2.length()) {
        return num1.length() > num2.length();
    }
    
    return num1 > num2;
}

// 字符串加法（假设都是正数）
std::string BigInteger::addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');
        
        result = static_cast<char>(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    return result;
}

// 字符串减法（假设 num1 >= num2 且都是正数）
std::string BigInteger::subtractStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0) {
        int diff = (num1[i] - '0') - borrow;
        if (j >= 0) diff -= (num2[j] - '0');
        
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = static_cast<char>(diff + '0') + result;
        i--;
        j--;
    }

    // 移除前导零
    size_t firstNonZero = 0;
    while (firstNonZero < result.size() && result[firstNonZero] == '0') {
        firstNonZero++;
    }

    if (firstNonZero == result.size()) {
        return "0";
    }
    
    return result.substr(firstNonZero);
}

// 加法运算符重载
BigInteger BigInteger::operator+(const BigInteger& other) const {
    BigInteger result;
    
    // 如果两数符号相同
    if (isNegative == other.isNegative) {
        result.number = addStrings(number, other.number);
        result.isNegative = isNegative;
    } else {
        // 如果符号不同，转为减法
        if (isLarger(number, other.number)) {
            result.number = subtractStrings(number, other.number);
            result.isNegative = isNegative;
        } else {
            result.number = subtractStrings(other.number, number);
            result.isNegative = other.isNegative;
        }
    }
    
    // 处理结果为零的情况
    if (result.number == "0") {
        result.isNegative = false;
    }
    
    return result;
}

// 减法运算符重载
BigInteger BigInteger::operator-(const BigInteger& other) const {
    // 创建一个other的副本，并改变其符号
    BigInteger negatedOther = other;
    negatedOther.isNegative = !other.isNegative;
    
    // 转为加法
    return *this + negatedOther;
}

// 输出函数
void BigInteger::print() const {
    std::cout << toString() << std::endl;
}

// 转为字符串
std::string BigInteger::toString() const {
    if (isNegative && number != "0") {
        return "-" + number;
    }
    return number;
}

// 重载输出流运算符
std::ostream& operator<<(std::ostream& out, const BigInteger& num) {
    out << num.toString();
    return out;
}