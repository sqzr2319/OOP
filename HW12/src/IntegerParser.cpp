#include "IntegerParser.hpp"
#include "ParseExceptions.hpp"
#include <limits>
#include <cstdlib>
#include <stdexcept>

int IntegerParser::parse(const std::string& str) {
    // 检查空字符串
    if (str.empty()) {
        throw EmptyStringException();
    }
    
    // 检查是否只有符号
    if (str == "+" || str == "-") {
        throw OnlySignException();
    }
    
    // 检查符号位置和多个符号情况
    bool hasSignAtBeginning = (str[0] == '+' || str[0] == '-');
    
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] == '+' || str[i] == '-') {
            throw InvalidSignPositionException();
        }
    }
    
    // 检查非法字符
    for (size_t i = 0; i < str.length(); ++i) {
        if (i == 0 && hasSignAtBeginning) {
            continue; // 首位可以是符号
        }
        if (!isDigit(str[i])) {
            throw InvalidCharacterException(str[i]);
        }
    }
    
    // 尝试转换为整数，处理溢出
    try {
        long long value = std::stoll(str);
        
        // 检查是否超出int范围
        if (value > std::numeric_limits<int>::max() || 
            value < std::numeric_limits<int>::min()) {
            throw OverflowException();
        }
        
        return static_cast<int>(value);
    } catch (const std::out_of_range&) {
        throw OverflowException();
    } catch (const std::invalid_argument&) {
        // 由于我们已经做了前面的检查，不应该到这里
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