#include<iostream>
#include"complex.hpp"

Complex Complex::operator+(const Complex &c)
{
    return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex &c)
{
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex &c)
{
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator/(const Complex &c)
{
    if(c.real==0&&c.imag==0)
    {
        std::cout<<"Error: divided by zero!"<<std::endl;
        return Complex(1e9,1e9);
    }
    return Complex((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag), (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
}

Complex Complex::operator++()
{
    real++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex temp = *this;
    real++;
    return temp;
}

Complex Complex::operator--()
{
    real--;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex temp = *this;
    real--;
    return temp;
}

void Complex::print()
{
    if(real>=1e8&&imag>=1e8)
    {
        return;
    }
    if(imag==0)
        std::cout<<real<<std::endl;
    else if(real==0)
        std::cout<<imag<<"i"<<std::endl;
    else if(imag>0)
        std::cout<<real<<"+"<<imag<<"i"<<std::endl;
    else
        std::cout<<real<<imag<<"i"<<std::endl;
}