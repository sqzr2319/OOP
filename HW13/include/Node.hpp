#ifndef NODE_HPP
#define NODE_HPP

struct StudentNode {
    int studentId;     // ѧ��
    int grade;         // �ɼ�
    StudentNode* prev; // ǰһ���ڵ�
    StudentNode* next; // ��һ���ڵ�
};

#endif