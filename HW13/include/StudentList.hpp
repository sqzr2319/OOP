#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include "Node.hpp"
#include "NodeFactory.hpp"

class StudentList {
private:
    StudentNode* head;     // ����ͷ
    StudentNode* tail;     // ����β
    int size;              // �����С
    NodeFactory& factory;  // �ڵ㹤������

public:
    StudentList(NodeFactory& nodeFactory);
    ~StudentList();
    
    // ����ѧ����¼����ѧ������
    void insert(int studentId, int grade);
    
    // ɾ��ָ��ѧ�ŵĵ�һ��ѧ��
    bool removeById(int studentId);
    
    // ɾ������ָ���ɼ���ѧ��
    int removeByGrade(int grade);
    
    // ����ָ��ѧ�ŵ�ѧ���ɼ�
    bool findById(int studentId, int& grade) const;
    
    // ��������ָ���ɼ���ѧ��
    void findByGrade(int grade) const;
    
    // ��ӡ����ѧ����Ϣ
    void printAll() const;
    
    // ��ȡ�����С
    int getSize() const;
};

#endif