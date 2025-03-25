#include "IntegerParser.hpp"
#include "ParseExceptions.hpp"
#include <iostream>
#include <string>
#include <vector>

void testParser() {
    // ��������
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"123", "��Ч����"},
        {"-456", "��Ч������"},
        {"+789", "��Ч����������"},
        {"", "���ַ���"},
        {"abc", "�����Ƿ��ַ�"},
        {"123a", "���ֺ��зǷ��ַ�"},
        {"+", "ֻ�з���"},
        {"-", "ֻ�з���"},
        {"++123", "�������"},
        {"-+123", "�������"},
        {"123+", "����λ�ò���ȷ"},
        {"1234567890123456789", "�������"}
    };
    
    std::cout << "=== �������� ===" << std::endl;
    for (const auto& test : testCases) {
        std::cout << "����: \"" << test.first << "\" (" << test.second << ") --> ";
        try {
            int result = IntegerParser::parse(test.first);
            std::cout << "��Ч����: " << result << std::endl;
        } catch (const IntegerParseException& e) {
            std::cout << "�쳣: " << e.what() << std::endl;
        }
    }
}

int main() {
    // ����Ԥ�������
    testParser();
    
    // ����ʽ����
    std::cout << "\n=== ����ʽ���� ===" << std::endl;
    std::string input;
    std::cout << "������Ҫ�������ַ���������'exit'�˳���: ";
    
    while (std::getline(std::cin, input) && input != "exit") {
        try {
            int result = IntegerParser::parse(input);
            std::cout << "��Ч����: " << result << std::endl;
        } catch (const IntegerParseException& e) {
            std::cout << "�쳣: " << e.what() << std::endl;
        }
        std::cout << "������Ҫ�������ַ���������'exit'�˳���: ";
    }
    
    return 0;
}