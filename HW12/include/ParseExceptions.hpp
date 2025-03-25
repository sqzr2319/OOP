#ifndef PARSE_EXCEPTIONS_HPP
#define PARSE_EXCEPTIONS_HPP

#include <exception>
#include <string>

// 基础异常类
class IntegerParseException : public std::exception {
protected:
    std::string message;
public:
    IntegerParseException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// 1. 空字符串异常
class EmptyStringException : public IntegerParseException {
public:
    EmptyStringException() : IntegerParseException("空字符串不能转换为整数") {}
};

// 2. 非法字符异常
class InvalidCharacterException : public IntegerParseException {
public:
    InvalidCharacterException(char c) : 
        IntegerParseException(std::string("字符串中包含非法字符: ") + c) {}
};

// 3. 只有符号异常
class OnlySignException : public IntegerParseException {
public:
    OnlySignException() : IntegerParseException("字符串只包含符号，没有数字") {}
};

// 4. 多个符号异常
class MultipleSignsException : public IntegerParseException {
public:
    MultipleSignsException() : IntegerParseException("字符串中包含多个符号") {}
};

// 5. 溢出异常
class OverflowException : public IntegerParseException {
public:
    OverflowException() : IntegerParseException("整数值超出表示范围") {}
};

// 6. 符号位置不正确异常
class InvalidSignPositionException : public IntegerParseException {
public:
    InvalidSignPositionException() : IntegerParseException("符号位置不正确") {}
};

#endif // PARSE_EXCEPTIONS_HPP