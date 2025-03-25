#include <iostream>
#include "DoubleAnalyzer.hpp"
#include <limits>
#include <iomanip>

void testAndPrintResults(double value, const std::string& testName) {
    DoubleAnalyzer analyzer(value);
    
    std::cout << "===== ��������: " << testName << " =====" << std::endl;
    std::cout << "ֵ: " << std::setprecision(17) << value << std::endl;
    std::cout << "�����Ʊ�ʾ: " << analyzer.getBinaryRepresentation() << std::endl;
    std::cout << analyzer.getIEEERepresentation() << std::endl;
    std::cout << "�Ƿ�ΪNaN: " << (analyzer.isNaN() ? "��" : "��") << std::endl;
    std::cout << std::endl;
}

int main() {
    // ���Ը��ֳ���������ֵ
    
    // 1. ������
    testAndPrintResults(0.0, "����");
    testAndPrintResults(-0.0, "����");
    
    // 2. ���Գ�����
    testAndPrintResults(1.0, "1.0");
    testAndPrintResults(-1.0, "-1.0");
    testAndPrintResults(3.14159, "Բ���ʦ�");
    
    // 3. ���Լ�С��
    testAndPrintResults(std::numeric_limits<double>::min(), "��С���ֵ");
    testAndPrintResults(std::numeric_limits<double>::denorm_min(), "��С�ǹ��ֵ");
    
    // 4. ���Լ�����
    testAndPrintResults(std::numeric_limits<double>::max(), "���ֵ");
    
    // 5. ���������
    testAndPrintResults(std::numeric_limits<double>::infinity(), "������");
    testAndPrintResults(-std::numeric_limits<double>::infinity(), "������");
    
    // 6. ����NaN
    testAndPrintResults(std::numeric_limits<double>::quiet_NaN(), "ϵͳNaN");
    
    // ʹ�����ǵķ�������NaN
    DoubleAnalyzer nanAnalyzer;
    nanAnalyzer.setNaN();
    std::cout << "===== ��������: �Զ���NaN =====" << std::endl;
    std::cout << "ֵ: " << std::setprecision(17) << nanAnalyzer.getValue() << std::endl;
    std::cout << "�����Ʊ�ʾ: " << nanAnalyzer.getBinaryRepresentation() << std::endl;
    std::cout << nanAnalyzer.getIEEERepresentation() << std::endl;
    std::cout << "�Ƿ�ΪNaN: " << (nanAnalyzer.isNaN() ? "��" : "��") << std::endl;
    std::cout << std::endl;
    
    // 7. ������Ȥ�Ĳ���
    testAndPrintResults(0.1, "0.1���۲����룩");
    testAndPrintResults(123456789.123456789, "�����ȵĴ���");
    
    return 0;
}