#include <iostream>
#include "DoubleAnalyzer.hpp"
#include <limits>
#include <iomanip>

void testAndPrintResults(double value, const std::string& testName) {
    DoubleAnalyzer analyzer(value);
    
    std::cout << "===== 测试用例: " << testName << " =====" << std::endl;
    std::cout << "值: " << std::setprecision(17) << value << std::endl;
    std::cout << "二进制表示: " << analyzer.getBinaryRepresentation() << std::endl;
    std::cout << analyzer.getIEEERepresentation() << std::endl;
    std::cout << "是否为NaN: " << (analyzer.isNaN() ? "是" : "否") << std::endl;
    std::cout << std::endl;
}

int main() {
    // 测试各种常见和特殊值
    
    // 1. 测试零
    testAndPrintResults(0.0, "正零");
    testAndPrintResults(-0.0, "负零");
    
    // 2. 测试常规数
    testAndPrintResults(1.0, "1.0");
    testAndPrintResults(-1.0, "-1.0");
    testAndPrintResults(3.14159, "圆周率π");
    
    // 3. 测试极小数
    testAndPrintResults(std::numeric_limits<double>::min(), "最小规格化值");
    testAndPrintResults(std::numeric_limits<double>::denorm_min(), "最小非规格化值");
    
    // 4. 测试极大数
    testAndPrintResults(std::numeric_limits<double>::max(), "最大值");
    
    // 5. 测试无穷大
    testAndPrintResults(std::numeric_limits<double>::infinity(), "正无穷");
    testAndPrintResults(-std::numeric_limits<double>::infinity(), "负无穷");
    
    // 6. 测试NaN
    testAndPrintResults(std::numeric_limits<double>::quiet_NaN(), "系统NaN");
    
    // 使用我们的方法创建NaN
    DoubleAnalyzer nanAnalyzer;
    nanAnalyzer.setNaN();
    std::cout << "===== 测试用例: 自定义NaN =====" << std::endl;
    std::cout << "值: " << std::setprecision(17) << nanAnalyzer.getValue() << std::endl;
    std::cout << "二进制表示: " << nanAnalyzer.getBinaryRepresentation() << std::endl;
    std::cout << nanAnalyzer.getIEEERepresentation() << std::endl;
    std::cout << "是否为NaN: " << (nanAnalyzer.isNaN() ? "是" : "否") << std::endl;
    std::cout << std::endl;
    
    // 7. 其他有趣的测试
    testAndPrintResults(0.1, "0.1（观察舍入）");
    testAndPrintResults(123456789.123456789, "带精度的大数");
    
    return 0;
}