#include<iostream>
#include"list.hpp"

int main(){
    list a;
    int index,score;
    std::cout<<"����������룺"<<std::endl;
    std::cout<<"ָ��1: �������λѧ��(ѧ�ųɼ�)����0������"<<std::endl;
    std::cout<<"ָ��2: ɾ����1λָ��ѧ�ŵ�ѧ����"<<std::endl;
    std::cout<<"ָ��3: ɾ������ָ���ɼ���ѧ����"<<std::endl;
    std::cout<<"ָ��4: ��ʾ��1λָ��ѧ�ŵ�ѧ���ĳɼ���"<<std::endl;
    std::cout<<"ָ��5: ��ʾ����ָ���ɼ���ѧ����ѧ�ţ�"<<std::endl;
    std::cout<<"ָ��6: ��ʾ����ѧ����Ϣ��"<<std::endl;
    std::cout<<"ָ��-1: �˳���"<<std::endl;
    while(1){
        int op;
        std::cin>>op;
        if(op==1){
            while(1){
                std::cin>>index;
                if(index==0) break;
                std::cin>>score;
                a.insert(index, score);
            }
            std::cout<<"�����ɡ�"<<std::endl;
        }
        else if(op==2){
            std::cin>>index;
            a.erase(index);
            std::cout<<"ɾ����ɡ�"<<std::endl;
        }
        else if(op==3){
            std::cin>>score;
            a.erase_all(score);
            std::cout<<"ɾ����ɡ�"<<std::endl;
        }
        else if(op==4){
            std::cin>>index;
            std::cout<<"ѧ��"<<index<<"�ĳɼ�Ϊ��";
            a.find(index);
        }
        else if(op==5){
            std::cin>>score;
            std::cout<<"�ɼ�Ϊ"<<score<<"��ѧ���У�";
            a.find_all(score);
        }
        else if(op==6){
            std::cout<<"����ѧ����Ϣ���£�"<<std::endl;
            a.print();
        }
        else if(op==-1){
            break;
        }
        else{
            std::cout<<"����������������롣"<<std::endl;
        }
    }
    return 0;
}