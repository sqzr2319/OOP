#ifndef INTEGER_PARSER_HPP
#define INTEGER_PARSER_HPP

#include <string>

class IntegerParser {
public:
    // �����ַ���Ϊ����
    static int parse(const std::string& str);
    
    // ����ַ����Ƿ�Ϊ�Ϸ�����
    static bool isValidInteger(const std::string& str);

private:
    // ����ַ��Ƿ�Ϊ����
    static bool isDigit(char c);
};

#endif // INTEGER_PARSER_HPP