#include<iostream>
#include"date.hpp"

void date::julian(long long x,bool negative){
    long long flag=0,f=0;
        if(x%1461==0) x=x-1,f=1;
        year=x/1461*4-4713;
        x=x%1461;
        if(f==1) x++;
        if(x<=366) year+=0,x=x,flag=1;
        else if(x<=731) year+=1,x-=366;
        else if(x<=1096) year+=2,x-=731;
        else year+=3,x-=1096;
        for(int i=1;i<=12;i++){
            long long temp=m[i];
            if(i==2&&flag==1) temp++;
            if(x<=temp){
                month=i;
                break;
            }
            x-=temp;
        }
        day=x;
    if(negative==true) year-=40000000;
    if(year>=0) year++;

    if(year<0) std::cout<<"公元前"<<-year<<"年"<<month<<"月"<<day<<"日"<<std::endl;
    else std::cout<<year<<"年"<<month<<"月"<<day<<"日"<<std::endl;
    return ;
}

void date::gregorian(long long x){
    long long f=0,flag=0,g=0;
    if(x<=365) year=1582;
    else if(x<=730) year=1583,x=x-365;
    else if(x<=6574){
        x=x-730;
        if(x%1461==0) x=x-1,f=1;
        year=x/1461*4+1584;
        x=x%1461;
        if(f==1) x++;
        if(x<=366) year+=0,x=x,flag=1;
        else if(x<=731) year+=1,x-=366;
        else if(x<=1096) year+=2,x-=731;
        else year+=3,x-=1096;
    }
    else{
        x=x-6574;
        if(x%146097==0) x=x-1,g=1;
        year=x/146097*400+1600;
        x=x%146097;
        if(g==1) x++;
        if(x<=36525){
            if(x%1461==0) x=x-1,f=1;
            year=year+x/1461*4;
            x=x%1461;
            if(f==1) x++;
            if(x<=366) year+=0,x=x,flag=1;
            else if(x<=731) year+=1,x-=366;
            else if(x<=1096) year+=2,x-=731;
            else year+=3,x-=1096;
        }
        else if(x<=73049){
            x-=36525;
            year+=100;
            if(x<=365) year+=0;
            else{
                x=x+1;
                if(x%1461==0) x=x-1,f=1;
                year=year+x/1461*4;
                x=x%1461;
                if(f==1) x++;
                if(x<=366) year+=0,x=x,flag=1;
                else if(x<=731) year+=1,x-=366;
                else if(x<=1096) year+=2,x-=731;
                else year+=3,x-=1096;
            }
        }
        else if(x<=109573){
            x-=73049;
            year+=200;
            if(x<=365) year+=0;
            else{
                x=x+1;
                if(x%1461==0) x=x-1,f=1;
                year=year+x/1461*4;
                x=x%1461;
                if(f==1) x++;
                if(x<=366) year+=0,x=x,flag=1;
                else if(x<=731) year+=1,x-=366;
                else if(x<=1096) year+=2,x-=731;
                else year+=3,x-=1096;
            }
        }
        else{
            x-=109573;
            year+=300;
            if(x<=365) year+=0;
            else{
                x=x+1;
                if(x%1461==0) x=x-1,f=1;
                year=year+x/1461*4;
                x=x%1461;
                if(f==1) x++;
                if(x<=366) year+=0,x=x,flag=1;
                else if(x<=731) year+=1,x-=366;
                else if(x<=1096) year+=2,x-=731;
                else year+=3,x-=1096;
            }
        }
    }
    for(int i=1;i<=12;i++){
            long long temp=m[i];
            if(i==2&&flag==1) temp++;
            if(x<=temp){
                month=i;
                break;
            }
            x-=temp;
        }
    day=x;
    std::cout<<year<<"年"<<month<<"月"<<day<<"日"<<std::endl;
    return ;
}