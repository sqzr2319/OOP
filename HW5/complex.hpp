#ifndef COMPLEX
#define COMPLEX

//请编写复数类，实现复数的加法、减法、乘法、除法、前置“++”、后置“++”、前置“--”、后置“--”等运算符重载。
class Complex
{
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);
    void print();

private:
    double real;
    double imag;
};

#endif