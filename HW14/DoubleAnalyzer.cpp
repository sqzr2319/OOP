#include "DoubleAnalyzer.hpp"
#include <cmath>
#include <bitset>
#include <sstream>
#include <iomanip>

// Ĭ�Ϲ��캯��
DoubleAnalyzer::DoubleAnalyzer() {
    data.value = 0.0;
}

// �������Ĺ��캯��
DoubleAnalyzer::DoubleAnalyzer(double value) {
    data.value = value;
}

// ����ֵ
void DoubleAnalyzer::setValue(double value) {
    data.value = value;
}

// ��ȡ��ǰֵ
double DoubleAnalyzer::getValue() const {
    return data.value;
}

// ��ȡ�����Ʊ�ʾ
std::string DoubleAnalyzer::getBinaryRepresentation() const {
    std::bitset<64> bits(data.bits);
    return bits.to_string();
}

// ��ȡIEEE 754�ֽ��ʾ
std::string DoubleAnalyzer::getIEEERepresentation() const {
    std::stringstream ss;
    
    // ����λ
    ss << "����λ: " << data.parts.sign << "\n";
    
    // ָ��
    ss << "ָ��: " << std::bitset<11>(data.parts.exponent) 
       << " (ʮ����: " << data.parts.exponent << ")\n";
       
    // β��
    ss << "β��: " << std::bitset<52>(data.parts.fraction) 
       << " (ʮ����: " << data.parts.fraction << ")\n";
       
    return ss.str();
}

// ����Ƿ�ΪNaN
bool DoubleAnalyzer::isNaN() const {
    return std::isnan(data.value);
}

// ����ΪNaN
void DoubleAnalyzer::setNaN() {
    // ����һ��NaN: ��������ָ��λΪ1������������һ��β��λΪ1
    data.parts.sign = 0;        // ����λ��Ӱ��NaN
    data.parts.exponent = 0x7FF; // ����ָ��λΪ1
    data.parts.fraction = 0x1;   // ����һ��β��λΪ1
}

// ��ȡ����λ
bool DoubleAnalyzer::getSign() const {
    return data.parts.sign;
}

// ��ȡָ������
uint64_t DoubleAnalyzer::getExponent() const {
    return data.parts.exponent;
}

// ��ȡβ������
uint64_t DoubleAnalyzer::getFraction() const {
    return data.parts.fraction;
}