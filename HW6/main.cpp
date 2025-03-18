#include<iostream>
#include"list.hpp"

int main(){
    list a;
    int index,score;
    std::cout<<"请输入操作码："<<std::endl;
    std::cout<<"指令1: 添加若干位学生(学号成绩)，以0结束；"<<std::endl;
    std::cout<<"指令2: 删除第1位指定学号的学生；"<<std::endl;
    std::cout<<"指令3: 删除所有指定成绩的学生；"<<std::endl;
    std::cout<<"指令4: 显示第1位指定学号的学生的成绩；"<<std::endl;
    std::cout<<"指令5: 显示所有指定成绩的学生的学号；"<<std::endl;
    std::cout<<"指令6: 显示所有学生信息；"<<std::endl;
    std::cout<<"指令-1: 退出。"<<std::endl;
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
            std::cout<<"添加完成。"<<std::endl;
        }
        else if(op==2){
            std::cin>>index;
            a.erase(index);
            std::cout<<"删除完成。"<<std::endl;
        }
        else if(op==3){
            std::cin>>score;
            a.erase_all(score);
            std::cout<<"删除完成。"<<std::endl;
        }
        else if(op==4){
            std::cin>>index;
            std::cout<<"学号"<<index<<"的成绩为：";
            a.find(index);
        }
        else if(op==5){
            std::cin>>score;
            std::cout<<"成绩为"<<score<<"的学号有：";
            a.find_all(score);
        }
        else if(op==6){
            std::cout<<"所有学生信息如下："<<std::endl;
            a.print();
        }
        else if(op==-1){
            break;
        }
        else{
            std::cout<<"输入错误，请重新输入。"<<std::endl;
        }
    }
    return 0;
}