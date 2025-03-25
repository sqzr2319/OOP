#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include "Node.hpp"
#include "NodeFactory.hpp"

class StudentList {
private:
    StudentNode* head;     // 链表头
    StudentNode* tail;     // 链表尾
    int size;              // 链表大小
    NodeFactory& factory;  // 节点工厂引用

public:
    StudentList(NodeFactory& nodeFactory);
    ~StudentList();
    
    // 插入学生记录（按学号升序）
    void insert(int studentId, int grade);
    
    // 删除指定学号的第一个学生
    bool removeById(int studentId);
    
    // 删除所有指定成绩的学生
    int removeByGrade(int grade);
    
    // 查找指定学号的学生成绩
    bool findById(int studentId, int& grade) const;
    
    // 查找所有指定成绩的学生
    void findByGrade(int grade) const;
    
    // 打印所有学生信息
    void printAll() const;
    
    // 获取链表大小
    int getSize() const;
};

#endif