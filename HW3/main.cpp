#include"calculate.hpp"
#include<iostream>
#include<cmath>

int main(){
    int op;
    int cnt=0;
    double a;
    double sumc=0,sums=0;
    std::cout<<"�����������������ͼ�ε��ܳ��������"<<std::endl;
    std::cout<<"1. ��������"<<std::endl;
    std::cout<<"2. ������"<<std::endl;
    std::cout<<"3. �������"<<std::endl;
    std::cout<<"4. ��������"<<std::endl;
    std::cout<<"5. Բ��"<<std::endl;
    std::cout<<"0. �˳�"<<std::endl;
    while(1){
        std::cout<<"���������"<<std::endl;
        std::cin>>op;
        switch(op){
            case 1:
                std::cout<<"������߳���"<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"��Ч���������������룺"<<std::endl;
                    continue;
                }
                triangle t;
                std::cout<<"�ܳ���"<<t.c(a)<<std::endl;
                std::cout<<"�����"<<t.s(a)<<std::endl;
                sumc+=t.c(a);
                sums+=t.s(a);
                cnt++;
                break;
            case 2:
                std::cout<<"������߳���"<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"��Ч���������������룺"<<std::endl;
                    continue;
                }
                square s;
                std::cout<<"�ܳ���"<<s.c(a)<<std::endl;
                std::cout<<"�����"<<s.s(a)<<std::endl;
                sumc+=s.c(a);
                sums+=s.s(a);
                cnt++;
                break;
            case 3:
                std::cout<<"������߳���"<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"��Ч���������������룺"<<std::endl;
                    continue;
                }
                pentagon p;
                std::cout<<"�ܳ���"<<p.c(a)<<std::endl;
                std::cout<<"�����"<<p.s(a)<<std::endl;
                sumc+=p.c(a);
                sums+=p.s(a);
                cnt++;
                break;
            case 4:
                std::cout<<"������߳���"<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"��Ч���������������룺"<<std::endl;
                    continue;
                }
                hexagon h;
                std::cout<<"�ܳ���"<<h.c(a)<<std::endl;
                std::cout<<"�����"<<h.s(a)<<std::endl;
                sumc+=h.c(a);
                sums+=h.s(a);
                cnt++;
                break;
            case 5:
                std::cout<<"������뾶��"<<std::endl;
                std::cin>>a;
                if(a<=0){
                    std::cout<<"��Ч���������������룺"<<std::endl;
                    continue;
                }
                circle c;
                std::cout<<"�ܳ���"<<c.c(a)<<std::endl;
                std::cout<<"�����"<<c.s(a)<<std::endl;
                sumc+=c.c(a);
                sums+=c.s(a);
                cnt++;
                break;
            case 0:
                if(cnt>0){
                    std::cout<<"ͼ�θ�����"<<cnt<<std::endl;
                    std::cout<<"���ܳ���"<<sumc<<std::endl;
                    std::cout<<"�������"<<sums<<std::endl;
                }
                return 0;
            default:
                std::cout<<"��Ч������������룺"<<std::endl;
        }
    }
    return 0;
}