#include "IntegerParser.hpp"
#include "ParseExceptions.hpp"
#include <limits>
#include <cstdlib>
#include <stdexcept>

int IntegerParser::parse(const std::string& str) {
    // �����ַ���
    if (str.empty()) {
        throw EmptyStringException();
    }
    
    // ����Ƿ�ֻ�з���
    if (str == "+" || str == "-") {
        throw OnlySignException();
    }
    
    // ������λ�úͶ���������
    bool hasSignAtBeginning = (str[0] == '+' || str[0] == '-');
    
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] == '+' || str[i] == '-') {
            throw InvalidSignPositionException();
        }
    }
    
    // ���Ƿ��ַ�
    for (size_t i = 0; i < str.length(); ++i) {
        if (i == 0 && hasSignAtBeginning) {
            continue; // ��λ�����Ƿ���
        }
        if (!isDigit(str[i])) {
            throw InvalidCharacterException(str[i]);
        }
    }
    
    // ����ת��Ϊ�������������
    try {
        long long value = std::stoll(str);
        
        // ����Ƿ񳬳�int��Χ
        if (value > std::numeric_limits<int>::max() || 
            value < std::numeric_limits<int>::min()) {
            throw OverflowException();
        }
        
        return static_cast<int>(value);
    } catch (const std::out_of_range&) {
        throw OverflowException();
    } catch (const std::invalid_argument&) {
        // ���������Ѿ�����ǰ��ļ�飬��Ӧ�õ�����
        throw InvalidCharacterException('?');
    }
}

bool IntegerParser::isValidInteger(const std::string& str) {
    try {
        parse(str);
        return true;
    } catch (const IntegerParseException&) {
        return false;
    }
}

bool IntegerParser::isDigit(char c) {
    return (c >= '0' && c <= '9');
}