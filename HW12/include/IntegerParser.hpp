#ifndef INTEGER_PARSER_HPP
#define INTEGER_PARSER_HPP

#include <string>

class IntegerParser {
public:
    // 解析字符串为整数
    static int parse(const std::string& str);
    
    // 检查字符串是否为合法整数
    static bool isValidInteger(const std::string& str);

private:
    // 检查字符是否为数字
    static bool isDigit(char c);
};

#endif // INTEGER_PARSER_HPP