#include <iostream>
#include "BigInteger.hpp"

void testAddition() {
    std::cout << "===== 测试加法运算 =====" << std::endl;
    
    // 测试案例1：两个零相加
    BigInteger a1("0");
    BigInteger b1("0");
    std::cout << "测试1 (0 + 0): " << a1 << " + " << b1 << " = " << (a1 + b1) << std::endl;
    
    // 测试案例2：正数与零相加
    BigInteger a2("123");
    BigInteger b2("0");
    std::cout << "测试2 (正数 + 0): " << a2 << " + " << b2 << " = " << (a2 + b2) << std::endl;
    
    // 测试案例3：两个正数相加
    BigInteger a3("123");
    BigInteger b3("456");
    std::cout << "测试3 (正数 + 正数): " << a3 << " + " << b3 << " = " << (a3 + b3) << std::endl;
    
    // 测试案例4：两个负数相加
    BigInteger a4("-123");
    BigInteger b4("-456");
    std::cout << "测试4 (负数 + 负数): " << a4 << " + " << b4 << " = " << (a4 + b4) << std::endl;
    
    // 测试案例5：正数与负数相加
    BigInteger a5("123");
    BigInteger b5("-456");
    std::cout << "测试5 (正数 + 负数): " << a5 << " + " << b5 << " = " << (a5 + b5) << std::endl;
}

void testSubtraction() {
    std::cout << "\n===== 测试减法运算 =====" << std::endl;
    
    // 测试案例1：0 - 0
    BigInteger a1("0");
    BigInteger b1("0");
    std::cout << "测试1 (0 - 0): " << a1 << " - " << b1 << " = " << (a1 - b1) << std::endl;
    
    // 测试案例2：正数 - 0
    BigInteger a2("123");
    BigInteger b2("0");
    std::cout << "测试2 (正数 - 0): " << a2 << " - " << b2 << " = " << (a2 - b2) << std::endl;
    
    // 测试案例3：正数 - 正数（结果为正）
    BigInteger a3("456");
    BigInteger b3("123");
    std::cout << "测试3 (正数 - 正数，结果为正): " << a3 << " - " << b3 << " = " << (a3 - b3) << std::endl;
    
    // 测试案例4：正数 - 正数（结果为负）
    BigInteger a4("123");
    BigInteger b4("456");
    std::cout << "测试4 (正数 - 正数，结果为负): " << a4 << " - " << b4 << " = " << (a4 - b4) << std::endl;
    
    // 测试案例5：负数 - 负数
    BigInteger a5("-123");
    BigInteger b5("-456");
    std::cout << "测试5 (负数 - 负数): " << a5 << " - " << b5 << " = " << (a5 - b5) << std::endl;
}

int main() {
    testAddition();
    testSubtraction();
    
    return 0;
}