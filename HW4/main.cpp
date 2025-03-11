#include<iostream>
#include"date.hpp"
int main(){
    int n;
    while(1){
        long long interval;
        std::cout<<"请输入一个整数n，正数代表n天后，负数代表n天前，0代表退出："<<std::endl;
        std::cin>>interval;
        if(interval==0) return 0;
        else if(interval>0)
            std::cout<<interval<<"天后的日期是："<<std::endl;
        else
            std::cout<<-interval<<"天前的日期是："<<std::endl;
        long long std_date=2460746+1+interval; //将初始日期设置为今天(2025.3.11)
        date d;
        if(std_date<=0){
            std_date+=14610000000;
            d.julian(std_date,true);
        }
        else if(std_date<=2299161)
            d.julian(std_date,false);
        else{
            std_date=std_date+10-2298884;
            d.gregorian(std_date);
        }
    }
}