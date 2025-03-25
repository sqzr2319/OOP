#include <iostream>
#include "NodeFactory.hpp"
#include "StudentList.hpp"

int main() {
    NodeFactory factory;
    StudentList studentList(factory);
    
    int command;
    
    while (true) {
        std::cout << "\n������ָ��ţ�" << std::endl;
        std::cout << "1: �������λѧ��(ѧ�� �ɼ�)����0����" << std::endl;
        std::cout << "2: ɾ����1λָ��ѧ�ŵ�ѧ��" << std::endl;
        std::cout << "3: ɾ������ָ���ɼ���ѧ��" << std::endl;
        std::cout << "4: ��ʾ��1λָ��ѧ�ŵ�ѧ���ĳɼ�" << std::endl;
        std::cout << "5: ��ʾ����ָ���ɼ���ѧ����ѧ��" << std::endl;
        std::cout << "6: ��ʾ����ѧ����Ϣ" << std::endl;
        std::cout << "-1: �˳�" << std::endl;
        
        std::cin >> command;
        
        if (command == -1) {
            std::cout << "�����˳����ͷ����нڵ�" << std::endl;
            break;  // �˳�����
        }
        
        switch (command) {
            case 1: {  // ���ѧ��
                int studentId, grade;
                while (true) {
                    std::cout << "������ѧ�źͳɼ���ѧ��Ϊ0��������:" << std::endl;
                    std::cin >> studentId;
                    if (studentId == 0) break;
                    
                    std::cin >> grade;
                    if (studentId > 0 && grade >= 0) {
                        studentList.insert(studentId, grade);
                    } else {
                        std::cout << "��Ч���룺ѧ�ű���Ϊ���������ɼ�����Ϊ�Ǹ�����" << std::endl;
                    }
                }
                break;
            }
            case 2: {  // ɾ��ָ��ѧ�ŵ�ѧ��
                int studentId;
                std::cout << "������Ҫɾ����ѧ��:" << std::endl;
                std::cin >> studentId;
                
                if (studentList.removeById(studentId)) {
                    std::cout << "�ɹ�ɾ��ѧ��Ϊ " << studentId << " ��ѧ��" << std::endl;
                    std::cout << "�����౸�ýڵ�����: " << factory.getUnusedCount() << std::endl;
                } else {
                    std::cout << "δ�ҵ�ѧ��Ϊ " << studentId << " ��ѧ��" << std::endl;
                }
                break;
            }
            case 3: {  // ɾ��ָ���ɼ���ѧ��
                int grade;
                std::cout << "������Ҫɾ���ĳɼ�:" << std::endl;
                std::cin >> grade;
                
                int count = studentList.removeByGrade(grade);
                std::cout << "�ɹ�ɾ�� " << count << " ���ɼ�Ϊ " << grade << " ��ѧ��" << std::endl;
                std::cout << "�����౸�ýڵ�����: " << factory.getUnusedCount() << std::endl;
                break;
            }
            case 4: {  // ��ʾָ��ѧ�ŵ�ѧ���ɼ�
                int studentId, grade;
                std::cout << "������Ҫ��ѯ��ѧ��:" << std::endl;
                std::cin >> studentId;
                
                if (studentList.findById(studentId, grade)) {
                    std::cout << grade << std::endl;
                } else {
                    std::cout << "δ�ҵ�ѧ��Ϊ " << studentId << " ��ѧ��" << std::endl;
                }
                break;
            }
            case 5: {  // ��ʾָ���ɼ���ѧ��ѧ��
                int grade;
                std::cout << "������Ҫ��ѯ�ĳɼ�:" << std::endl;
                std::cin >> grade;
                
                studentList.findByGrade(grade);
                break;
            }
            case 6: {  // ��ʾ����ѧ����Ϣ
                studentList.printAll();
                break;
            }
            default: {
                std::cout << "��Ч��ָ�����������" << std::endl;
            }
        }
    }
    
    return 0;
}