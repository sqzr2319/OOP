#include <iostream>
#include "NodeFactory.hpp"
#include "StudentList.hpp"

int main() {
    NodeFactory factory;
    StudentList studentList(factory);
    
    int command;
    
    while (true) {
        std::cout << "\n请输入指令号：" << std::endl;
        std::cout << "1: 添加若干位学生(学号 成绩)，以0结束" << std::endl;
        std::cout << "2: 删除第1位指定学号的学生" << std::endl;
        std::cout << "3: 删除所有指定成绩的学生" << std::endl;
        std::cout << "4: 显示第1位指定学号的学生的成绩" << std::endl;
        std::cout << "5: 显示所有指定成绩的学生的学号" << std::endl;
        std::cout << "6: 显示所有学生信息" << std::endl;
        std::cout << "-1: 退出" << std::endl;
        
        std::cin >> command;
        
        if (command == -1) {
            std::cout << "程序退出，释放所有节点" << std::endl;
            break;  // 退出程序
        }
        
        switch (command) {
            case 1: {  // 添加学生
                int studentId, grade;
                while (true) {
                    std::cout << "请输入学号和成绩，学号为0结束输入:" << std::endl;
                    std::cin >> studentId;
                    if (studentId == 0) break;
                    
                    std::cin >> grade;
                    if (studentId > 0 && grade >= 0) {
                        studentList.insert(studentId, grade);
                    } else {
                        std::cout << "无效输入：学号必须为正整数，成绩必须为非负整数" << std::endl;
                    }
                }
                break;
            }
            case 2: {  // 删除指定学号的学生
                int studentId;
                std::cout << "请输入要删除的学号:" << std::endl;
                std::cin >> studentId;
                
                if (studentList.removeById(studentId)) {
                    std::cout << "成功删除学号为 " << studentId << " 的学生" << std::endl;
                    std::cout << "工厂类备用节点数量: " << factory.getUnusedCount() << std::endl;
                } else {
                    std::cout << "未找到学号为 " << studentId << " 的学生" << std::endl;
                }
                break;
            }
            case 3: {  // 删除指定成绩的学生
                int grade;
                std::cout << "请输入要删除的成绩:" << std::endl;
                std::cin >> grade;
                
                int count = studentList.removeByGrade(grade);
                std::cout << "成功删除 " << count << " 名成绩为 " << grade << " 的学生" << std::endl;
                std::cout << "工厂类备用节点数量: " << factory.getUnusedCount() << std::endl;
                break;
            }
            case 4: {  // 显示指定学号的学生成绩
                int studentId, grade;
                std::cout << "请输入要查询的学号:" << std::endl;
                std::cin >> studentId;
                
                if (studentList.findById(studentId, grade)) {
                    std::cout << grade << std::endl;
                } else {
                    std::cout << "未找到学号为 " << studentId << " 的学生" << std::endl;
                }
                break;
            }
            case 5: {  // 显示指定成绩的学生学号
                int grade;
                std::cout << "请输入要查询的成绩:" << std::endl;
                std::cin >> grade;
                
                studentList.findByGrade(grade);
                break;
            }
            case 6: {  // 显示所有学生信息
                studentList.printAll();
                break;
            }
            default: {
                std::cout << "无效的指令，请重新输入" << std::endl;
            }
        }
    }
    
    return 0;
}