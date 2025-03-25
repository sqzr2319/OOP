#include "GradeManager.hpp"
#include <iostream>
#include <string>

void showMenu() {
    std::cout << "\n==== 学生成绩管理系统 ====\n";
    std::cout << "1: 从文件加载成绩\n";
    std::cout << "2: 添加学生成绩\n";
    std::cout << "3: 删除学生成绩\n";
    std::cout << "4: 清空所有成绩\n";
    std::cout << "5: 更新学生成绩\n";
    std::cout << "6: 查询学生成绩\n";
    std::cout << "7: 显示所有成绩\n";
    std::cout << "8: 保存成绩到文件\n";
    std::cout << "-1: 退出系统\n";
    std::cout << "请输入指令: ";
}

void runTests() {
    // 测试案例执行函数
    GradeManager testManager;
    
    std::cout << "=== 测试案例1: 基本操作测试 ===\n";
    // 添加成绩
    testManager.addGrade(1001, 95);
    testManager.addGrade(1002, 87);
    testManager.addGrade(1003, 76);
    
    // 显示所有成绩
    std::cout << "添加三名学生后的成绩表:\n";
    testManager.displayAll();
    
    // 更新成绩
    testManager.updateGrade(1002, 92);
    std::cout << "更新学号1002的成绩后:\n";
    testManager.displayAll();
    
    // 查询成绩
    int grade;
    if (testManager.findGrade(1003, grade)) {
        std::cout << "学号1003的成绩为: " << grade << std::endl;
    }
    
    // 删除成绩
    testManager.removeGrade(1001);
    std::cout << "删除学号1001后的成绩表:\n";
    testManager.displayAll();
    
    // 保存到文件
    std::cout << "保存成绩到test_grades.txt\n";
    testManager.saveToFile("test_grades.txt");
    
    // 清空成绩表
    testManager.clearAll();
    std::cout << "清空后的成绩表:\n";
    testManager.displayAll();
    
    // 从文件加载
    std::cout << "从test_grades.txt加载成绩:\n";
    testManager.loadFromFile("test_grades.txt");
    testManager.displayAll();
    
    std::cout << "=== 测试完成 ===\n\n";
}

int main() {
    // 运行测试案例
    runTests();
    
    // 主程序
    GradeManager manager;
    int command;
    
    do {
        showMenu();
        std::cin >> command;
        
        switch (command) {
            case 1: {  // 从文件加载
                std::string filename;
                std::cout << "请输入文件名: ";
                std::cin >> filename;
                if (manager.loadFromFile(filename)) {
                    std::cout << "成功从文件加载成绩" << std::endl;
                } else {
                    std::cout << "加载文件失败" << std::endl;
                }
                break;
            }
            case 2: {  // 添加成绩
                int studentId, grade;
                std::cout << "请输入学号: ";
                std::cin >> studentId;
                std::cout << "请输入成绩: ";
                std::cin >> grade;
                manager.addGrade(studentId, grade);
                std::cout << "添加成功" << std::endl;
                break;
            }
            case 3: {  // 删除成绩
                int studentId;
                std::cout << "请输入要删除的学号: ";
                std::cin >> studentId;
                if (manager.removeGrade(studentId)) {
                    std::cout << "删除成功" << std::endl;
                } else {
                    std::cout << "未找到该学号" << std::endl;
                }
                break;
            }
            case 4: {  // 清空所有
                char confirm;
                std::cout << "确定要清空所有记录吗? (y/n): ";
                std::cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    manager.clearAll();
                    std::cout << "已清空所有记录" << std::endl;
                }
                break;
            }
            case 5: {  // 更新成绩
                int studentId, newGrade;
                std::cout << "请输入学号: ";
                std::cin >> studentId;
                std::cout << "请输入新成绩: ";
                std::cin >> newGrade;
                if (manager.updateGrade(studentId, newGrade)) {
                    std::cout << "更新成功" << std::endl;
                } else {
                    std::cout << "未找到该学号" << std::endl;
                }
                break;
            }
            case 6: {  // 查询成绩
                int studentId, grade;
                std::cout << "请输入要查询的学号: ";
                std::cin >> studentId;
                if (manager.findGrade(studentId, grade)) {
                    std::cout << "学号 " << studentId << " 的成绩为: " << grade << std::endl;
                } else {
                    std::cout << "未找到该学号" << std::endl;
                }
                break;
            }
            case 7: {  // 显示所有
                manager.displayAll();
                break;
            }
            case 8: {  // 保存到文件
                std::string filename;
                std::cout << "请输入文件名: ";
                std::cin >> filename;
                if (manager.saveToFile(filename)) {
                    std::cout << "成功保存到文件" << std::endl;
                } else {
                    std::cout << "保存文件失败" << std::endl;
                }
                break;
            }
            case -1:  // 退出
                std::cout << "感谢使用，再见！" << std::endl;
                break;
            default:
                std::cout << "无效的指令，请重试" << std::endl;
        }
    } while (command != -1);
    
    return 0;
}