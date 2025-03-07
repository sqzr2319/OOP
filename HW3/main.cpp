#include"calculate.hpp"
#include<iostream>
#include<cmath>

int main(){
    int op;
    int cnt=0;
    double a;
    double sumc=0,sums=0;
    std::cout<<"请输入命令计算下列图形的周长和面积："<<std::endl;
    std::cout<<"1. 正三角形"<<std::endl;
    std::cout<<"2. 正方形"<<std::endl;
    std::cout<<"3. 正五边形"<<std::endl;
    std::cout<<"4. 正六边形"<<std::endl;
    std::cout<<"5. 圆形"<<std::endl;
    std::cout<<"0. 退出"<<std::endl;
    while(1){
        std::cout<<"请输入命令："<<std::endl;
        std::cin>>op;
        switch(op){
            case 1:
                std::cout<<"请输入边长："<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"无效参数，请重新输入："<<std::endl;
                    continue;
                }
                triangle t;
                std::cout<<"周长："<<t.c(a)<<std::endl;
                std::cout<<"面积："<<t.s(a)<<std::endl;
                sumc+=t.c(a);
                sums+=t.s(a);
                cnt++;
                break;
            case 2:
                std::cout<<"请输入边长："<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"无效参数，请重新输入："<<std::endl;
                    continue;
                }
                square s;
                std::cout<<"周长："<<s.c(a)<<std::endl;
                std::cout<<"面积："<<s.s(a)<<std::endl;
                sumc+=s.c(a);
                sums+=s.s(a);
                cnt++;
                break;
            case 3:
                std::cout<<"请输入边长："<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"无效参数，请重新输入："<<std::endl;
                    continue;
                }
                pentagon p;
                std::cout<<"周长："<<p.c(a)<<std::endl;
                std::cout<<"面积："<<p.s(a)<<std::endl;
                sumc+=p.c(a);
                sums+=p.s(a);
                cnt++;
                break;
            case 4:
                std::cout<<"请输入边长："<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"无效参数，请重新输入："<<std::endl;
                    continue;
                }
                hexagon h;
                std::cout<<"周长："<<h.c(a)<<std::endl;
                std::cout<<"面积："<<h.s(a)<<std::endl;
                sumc+=h.c(a);
                sums+=h.s(a);
                cnt++;
                break;
            case 5:
                std::cout<<"请输入半径："<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"无效参数，请重新输入："<<std::endl;
                    continue;
                }
                circle c;
                std::cout<<"周长："<<c.c(a)<<std::endl;
                std::cout<<"面积："<<c.s(a)<<std::endl;
                sumc+=c.c(a);
                sums+=c.s(a);
                cnt++;
                break;
            case 0:
                if(cnt>0){
                    std::cout<<"图形个数："<<cnt<<std::endl;
                    std::cout<<"总周长："<<sumc<<std::endl;
                    std::cout<<"总面积："<<sums<<std::endl;
                }
                return 0;
            default:
                std::cout<<"无效命令，请重新输入："<<std::endl;
        }
    }
    return 0;
}