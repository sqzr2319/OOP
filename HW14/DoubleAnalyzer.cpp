#include "DoubleAnalyzer.hpp"
#include <cmath>
#include <bitset>
#include <sstream>
#include <iomanip>

// 默认构造函数
DoubleAnalyzer::DoubleAnalyzer() {
    data.value = 0.0;
}

// 带参数的构造函数
DoubleAnalyzer::DoubleAnalyzer(double value) {
    data.value = value;
}

// 设置值
void DoubleAnalyzer::setValue(double value) {
    data.value = value;
}

// 获取当前值
double DoubleAnalyzer::getValue() const {
    return data.value;
}

// 获取二进制表示
std::string DoubleAnalyzer::getBinaryRepresentation() const {
    std::bitset<64> bits(data.bits);
    return bits.to_string();
}

// 获取IEEE 754分解表示
std::string DoubleAnalyzer::getIEEERepresentation() const {
    std::stringstream ss;
    
    // 符号位
    ss << "符号位: " << data.parts.sign << "\n";
    
    // 指数
    ss << "指数: " << std::bitset<11>(data.parts.exponent) 
       << " (十进制: " << data.parts.exponent << ")\n";
       
    // 尾数
    ss << "尾数: " << std::bitset<52>(data.parts.fraction) 
       << " (十进制: " << data.parts.fraction << ")\n";
       
    return ss.str();
}

// 检查是否为NaN
bool DoubleAnalyzer::isNaN() const {
    return std::isnan(data.value);
}

// 设置为NaN
void DoubleAnalyzer::setNaN() {
    // 创建一个NaN: 设置所有指数位为1，并设置至少一个尾数位为1
    data.parts.sign = 0;        // 符号位不影响NaN
    data.parts.exponent = 0x7FF; // 所有指数位为1
    data.parts.fraction = 0x1;   // 设置一个尾数位为1
}

// 获取符号位
bool DoubleAnalyzer::getSign() const {
    return data.parts.sign;
}

// 获取指数部分
uint64_t DoubleAnalyzer::getExponent() const {
    return data.parts.exponent;
}

// 获取尾数部分
uint64_t DoubleAnalyzer::getFraction() const {
    return data.parts.fraction;
}