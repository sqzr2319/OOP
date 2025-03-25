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
            uint64_t fraction : 52;  // β����С�����֣�
            uint64_t exponent : 11;  // ָ��
            uint64_t sign : 1;       // ����λ
        } parts;
    };
    
    DoubleUnion data;

public:
    // ���캯��
    DoubleAnalyzer();
    DoubleAnalyzer(double value);
    
    // ����ֵ
    void setValue(double value);
    
    // ��ȡ��ǰֵ
    double getValue() const;
    
    // ��ȡ�����Ʊ�ʾ
    std::string getBinaryRepresentation() const;
    
    // ��ȡIEEE 754�ֽ��ʾ
    std::string getIEEERepresentation() const;
    
    // ����Ƿ�ΪNaN
    bool isNaN() const;
    
    // ����ΪNaN
    void setNaN();
    
    // ��ȡ������
    bool getSign() const;            // ��ȡ����λ
    uint64_t getExponent() const;    // ��ȡָ��
    uint64_t getFraction() const;    // ��ȡβ��
};

#endif // DOUBLE_ANALYZER_HPP