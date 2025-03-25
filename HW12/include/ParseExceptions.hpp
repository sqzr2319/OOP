#ifndef PARSE_EXCEPTIONS_HPP
#define PARSE_EXCEPTIONS_HPP

#include <exception>
#include <string>

// �����쳣��
class IntegerParseException : public std::exception {
protected:
    std::string message;
public:
    IntegerParseException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// 1. ���ַ����쳣
class EmptyStringException : public IntegerParseException {
public:
    EmptyStringException() : IntegerParseException("���ַ�������ת��Ϊ����") {}
};

// 2. �Ƿ��ַ��쳣
class InvalidCharacterException : public IntegerParseException {
public:
    InvalidCharacterException(char c) : 
        IntegerParseException(std::string("�ַ����а����Ƿ��ַ�: ") + c) {}
};

// 3. ֻ�з����쳣
class OnlySignException : public IntegerParseException {
public:
    OnlySignException() : IntegerParseException("�ַ���ֻ�������ţ�û������") {}
};

// 4. ��������쳣
class MultipleSignsException : public IntegerParseException {
public:
    MultipleSignsException() : IntegerParseException("�ַ����а����������") {}
};

// 5. ����쳣
class OverflowException : public IntegerParseException {
public:
    OverflowException() : IntegerParseException("����ֵ������ʾ��Χ") {}
};

// 6. ����λ�ò���ȷ�쳣
class InvalidSignPositionException : public IntegerParseException {
public:
    InvalidSignPositionException() : IntegerParseException("����λ�ò���ȷ") {}
};

#endif // PARSE_EXCEPTIONS_HPP