#include "GradeManager.hpp"
#include <iostream>
#include <string>

void showMenu() {
    std::cout << "\n==== ѧ���ɼ�����ϵͳ ====\n";
    std::cout << "1: ���ļ����سɼ�\n";
    std::cout << "2: ���ѧ���ɼ�\n";
    std::cout << "3: ɾ��ѧ���ɼ�\n";
    std::cout << "4: ������гɼ�\n";
    std::cout << "5: ����ѧ���ɼ�\n";
    std::cout << "6: ��ѯѧ���ɼ�\n";
    std::cout << "7: ��ʾ���гɼ�\n";
    std::cout << "8: ����ɼ����ļ�\n";
    std::cout << "-1: �˳�ϵͳ\n";
    std::cout << "������ָ��: ";
}

void runTests() {
    // ���԰���ִ�к���
    GradeManager testManager;
    
    std::cout << "=== ���԰���1: ������������ ===\n";
    // ��ӳɼ�
    testManager.addGrade(1001, 95);
    testManager.addGrade(1002, 87);
    testManager.addGrade(1003, 76);
    
    // ��ʾ���гɼ�
    std::cout << "�������ѧ����ĳɼ���:\n";
    testManager.displayAll();
    
    // ���³ɼ�
    testManager.updateGrade(1002, 92);
    std::cout << "����ѧ��1002�ĳɼ���:\n";
    testManager.displayAll();
    
    // ��ѯ�ɼ�
    int grade;
    if (testManager.findGrade(1003, grade)) {
        std::cout << "ѧ��1003�ĳɼ�Ϊ: " << grade << std::endl;
    }
    
    // ɾ���ɼ�
    testManager.removeGrade(1001);
    std::cout << "ɾ��ѧ��1001��ĳɼ���:\n";
    testManager.displayAll();
    
    // ���浽�ļ�
    std::cout << "����ɼ���test_grades.txt\n";
    testManager.saveToFile("test_grades.txt");
    
    // ��ճɼ���
    testManager.clearAll();
    std::cout << "��պ�ĳɼ���:\n";
    testManager.displayAll();
    
    // ���ļ�����
    std::cout << "��test_grades.txt���سɼ�:\n";
    testManager.loadFromFile("test_grades.txt");
    testManager.displayAll();
    
    std::cout << "=== ������� ===\n\n";
}

int main() {
    // ���в��԰���
    runTests();
    
    // ������
    GradeManager manager;
    int command;
    
    do {
        showMenu();
        std::cin >> command;
        
        switch (command) {
            case 1: {  // ���ļ�����
                std::string filename;
                std::cout << "�������ļ���: ";
                std::cin >> filename;
                if (manager.loadFromFile(filename)) {
                    std::cout << "�ɹ����ļ����سɼ�" << std::endl;
                } else {
                    std::cout << "�����ļ�ʧ��" << std::endl;
                }
                break;
            }
            case 2: {  // ��ӳɼ�
                int studentId, grade;
                std::cout << "������ѧ��: ";
                std::cin >> studentId;
                std::cout << "������ɼ�: ";
                std::cin >> grade;
                manager.addGrade(studentId, grade);
                std::cout << "��ӳɹ�" << std::endl;
                break;
            }
            case 3: {  // ɾ���ɼ�
                int studentId;
                std::cout << "������Ҫɾ����ѧ��: ";
                std::cin >> studentId;
                if (manager.removeGrade(studentId)) {
                    std::cout << "ɾ���ɹ�" << std::endl;
                } else {
                    std::cout << "δ�ҵ���ѧ��" << std::endl;
                }
                break;
            }
            case 4: {  // �������
                char confirm;
                std::cout << "ȷ��Ҫ������м�¼��? (y/n): ";
                std::cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    manager.clearAll();
                    std::cout << "��������м�¼" << std::endl;
                }
                break;
            }
            case 5: {  // ���³ɼ�
                int studentId, newGrade;
                std::cout << "������ѧ��: ";
                std::cin >> studentId;
                std::cout << "�������³ɼ�: ";
                std::cin >> newGrade;
                if (manager.updateGrade(studentId, newGrade)) {
                    std::cout << "���³ɹ�" << std::endl;
                } else {
                    std::cout << "δ�ҵ���ѧ��" << std::endl;
                }
                break;
            }
            case 6: {  // ��ѯ�ɼ�
                int studentId, grade;
                std::cout << "������Ҫ��ѯ��ѧ��: ";
                std::cin >> studentId;
                if (manager.findGrade(studentId, grade)) {
                    std::cout << "ѧ�� " << studentId << " �ĳɼ�Ϊ: " << grade << std::endl;
                } else {
                    std::cout << "δ�ҵ���ѧ��" << std::endl;
                }
                break;
            }
            case 7: {  // ��ʾ����
                manager.displayAll();
                break;
            }
            case 8: {  // ���浽�ļ�
                std::string filename;
                std::cout << "�������ļ���: ";
                std::cin >> filename;
                if (manager.saveToFile(filename)) {
                    std::cout << "�ɹ����浽�ļ�" << std::endl;
                } else {
                    std::cout << "�����ļ�ʧ��" << std::endl;
                }
                break;
            }
            case -1:  // �˳�
                std::cout << "��лʹ�ã��ټ���" << std::endl;
                break;
            default:
                std::cout << "��Ч��ָ�������" << std::endl;
        }
    } while (command != -1);
    
    return 0;
}