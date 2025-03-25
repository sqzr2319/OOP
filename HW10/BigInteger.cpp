#include "BigInteger.hpp"
#include <algorithm>

// Ĭ�Ϲ��캯��
BigInteger::BigInteger() : number("0"), isNegative(false) {}

// �ַ������캯��
BigInteger::BigInteger(const std::string& num) {
    if (num.empty()) {
        number = "0";
        isNegative = false;
        return;
    }

    // �������
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

    // �Ƴ�ǰ����
    removeLeadingZeros();
    
    // ���⴦����
    if (number == "0") {
        isNegative = false;
    }
}

// �������캯��
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

// �������캯��
BigInteger::BigInteger(const BigInteger& other) 
    : number(other.number), isNegative(other.isNegative) {}

// �Ƴ�ǰ����
void BigInteger::removeLeadingZeros() {
    // �ҵ���һ�������ַ�
    size_t firstNonZero = 0;
    while (firstNonZero < number.size() && number[firstNonZero] == '0') {
        firstNonZero++;
    }

    // ���ȫ���㣬����һ����
    if (firstNonZero == number.size()) {
        number = "0";
    } else {
        number = number.substr(firstNonZero);
    }
}

// �Ƚ����������ַ����Ĵ�С
bool BigInteger::isLarger(const std::string& num1, const std::string& num2) {
    if (num1.length() != num2.length()) {
        return num1.length() > num2.length();
    }
    
    return num1 > num2;
}

// �ַ����ӷ������趼��������
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

// �ַ������������� num1 >= num2 �Ҷ���������
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

    // �Ƴ�ǰ����
    size_t firstNonZero = 0;
    while (firstNonZero < result.size() && result[firstNonZero] == '0') {
        firstNonZero++;
    }

    if (firstNonZero == result.size()) {
        return "0";
    }
    
    return result.substr(firstNonZero);
}

// �ӷ����������
BigInteger BigInteger::operator+(const BigInteger& other) const {
    BigInteger result;
    
    // �������������ͬ
    if (isNegative == other.isNegative) {
        result.number = addStrings(number, other.number);
        result.isNegative = isNegative;
    } else {
        // ������Ų�ͬ��תΪ����
        if (isLarger(number, other.number)) {
            result.number = subtractStrings(number, other.number);
            result.isNegative = isNegative;
        } else {
            result.number = subtractStrings(other.number, number);
            result.isNegative = other.isNegative;
        }
    }
    
    // ������Ϊ������
    if (result.number == "0") {
        result.isNegative = false;
    }
    
    return result;
}

// �������������
BigInteger BigInteger::operator-(const BigInteger& other) const {
    // ����һ��other�ĸ��������ı������
    BigInteger negatedOther = other;
    negatedOther.isNegative = !other.isNegative;
    
    // תΪ�ӷ�
    return *this + negatedOther;
}

// �������
void BigInteger::print() const {
    std::cout << toString() << std::endl;
}

// תΪ�ַ���
std::string BigInteger::toString() const {
    if (isNegative && number != "0") {
        return "-" + number;
    }
    return number;
}

// ��������������
std::ostream& operator<<(std::ostream& out, const BigInteger& num) {
    out << num.toString();
    return out;
}