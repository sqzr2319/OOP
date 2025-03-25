#ifndef NODE_HPP
#define NODE_HPP

struct StudentNode {
    int studentId;     // 学号
    int grade;         // 成绩
    StudentNode* prev; // 前一个节点
    StudentNode* next; // 后一个节点
};

#endif