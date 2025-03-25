#ifndef DOUBLE_ANALYZER_HPP
#define DOUBLE_ANALYZER_HPP

#include <string>
#include <cstdint>

class DoubleAnalyzer {
private:
    union DoubleUnion {
        double value;
        uint64_t bits;
        struct {
            uint64_t fraction : 52;  // 尾数（小数部分）
            uint64_t exponent : 11;  // 指数
            uint64_t sign : 1;       // 符号位
        } parts;
    };
    
    DoubleUnion data;

public:
    // 构造函数
    DoubleAnalyzer();
    DoubleAnalyzer(double value);
    
    // 设置值
    void setValue(double value);
    
    // 获取当前值
    double getValue() const;
    
    // 获取二进制表示
    std::string getBinaryRepresentation() const;
    
    // 获取IEEE 754分解表示
    std::string getIEEERepresentation() const;
    
    // 检查是否为NaN
    bool isNaN() const;
    
    // 设置为NaN
    void setNaN();
    
    // 获取各部分
    bool getSign() const;            // 获取符号位
    uint64_t getExponent() const;    // 获取指数
    uint64_t getFraction() const;    // 获取尾数
};

#endif // DOUBLE_ANALYZER_HPP