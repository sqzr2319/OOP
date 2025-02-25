#include<iostream>
#include "GCD.hpp"

int main(){
    long long a,b;
    std::cout<<"Enter two positive numbers (Lesser than 10^9):";
    std::cin>>a>>b;
    if(a<=0 || b<=0 || a>=1000000000 || b>=1000000000){
        std::cout<<"Invalid input"<<std::endl;
        return 0;
    }
    GCD gcd;
    std::cout<<"gcd="<<gcd.calculate(a,b)<<std::endl;
    std::cout<<"lcm="<<a*b/gcd.calculate(a,b)<<std::endl;
    return 0;
}