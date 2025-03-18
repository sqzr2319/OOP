#include<iostream>
#include"complex.hpp"

int main(){
    Complex c1(0,0),c2(1,0),c3(0,1),c4(1,1),c5(1.14,5.14),add(10,10),result;

    //测试加法
    result=c1+add;
    result.print();
    result=c2+add;
    result.print();
    result=c3+add;
    result.print();
    result=c4+add;
    result.print();
    result=c5+add;
    result.print();
    std::cout<<std::endl;

    //测试减法
    result=c1-add;
    result.print();
    result=c2-add;
    result.print();
    result=c3-add;
    result.print();
    result=c4-add;
    result.print();
    result=c5-add;
    result.print();
    std::cout<<std::endl;

    //测试乘法
    result=c1*c1;
    result.print();
    result=c2*c2;
    result.print();
    result=c3*c3;
    result.print();
    result=c4*c4;
    result.print();
    result=c5*c5;
    result.print();
    std::cout<<std::endl;

    //测试除法
    result=c1/c1;
    result.print();
    result=c2/c2;
    result.print();
    result=c3/c3;
    result.print();
    result=c4/c4;
    result.print();
    result=c5/c5;
    result.print();
    std::cout<<std::endl;


    //测试前置++
    result=++c1;
    result.print();
    result=++c2;
    result.print();
    result=++c3;
    result.print();
    result=++c4;
    result.print();
    result=++c5;
    result.print();
    std::cout<<std::endl;

    //测试后置++
    result=c1++;
    result.print();
    result=c2++;
    result.print();
    result=c3++;
    result.print();
    result=c4++;
    result.print();
    result=c5++;
    result.print();
    std::cout<<std::endl;

    //测试前置--
    result=--c1;
    result.print();
    result=--c2;
    result.print();
    result=--c3;
    result.print();
    result=--c4;
    result.print();
    result=--c5;
    result.print();
    std::cout<<std::endl;

    //测试后置--
    result=c1--;
    result.print();
    result=c2--;
    result.print();
    result=c3--;
    result.print();
    result=c4--;
    result.print();
    result=c5--;
    result.print();
    std::cout<<std::endl;

    return 0;
}