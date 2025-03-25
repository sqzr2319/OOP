#include "StudentList.hpp"
#include <iostream>

StudentList::StudentList(NodeFactory& nodeFactory) 
    : head(nullptr), tail(nullptr), size(0), factory(nodeFactory) {
}

StudentList::~StudentList() {
    // 释放所有节点，并尝试回收到工厂
    StudentNode* current = head;
    while (current != nullptr) {
        StudentNode* next = current->next;
        factory.recycleNode(current);
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void StudentList::insert(int studentId, int grade) {
    // 从工厂获取一个节点
    StudentNode* newNode = factory.getNode();
    newNode->studentId = studentId;
    newNode->grade = grade;
    
    if (head == nullptr) {
        // 空链表
        head = newNode;
        tail = newNode;
        size = 1;
        return;
    }
    
    // 找到合适的位置插入（按学号升序）
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->studentId > studentId) {
            // 插入到current前面
            newNode->next = current;
            newNode->prev = current->prev;
            
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            } else {
                head = newNode;
            }
            
            current->prev = newNode;
            size++;
            return;
        } else if (current->studentId == studentId) {
            // 更新成绩
            current->grade = grade;
            factory.recycleNode(newNode); // 回收未使用的节点
            return;
        }
        current = current->next;
    }
    
    // 插入到链表尾部
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = nullptr;
    tail = newNode;
    size++;
}

bool StudentList::removeById(int studentId) {
    if (head == nullptr) return false;
    
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->studentId == studentId) {
            // 找到了要删除的节点
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            
            factory.recycleNode(current); // 回收节点到工厂
            size--;
            return true;
        }
        current = current->next;
    }
    
    return false; // 未找到指定学号
}

int StudentList::removeByGrade(int grade) {
    if (head == nullptr) return 0;
    
    int removedCount = 0;
    StudentNode* current = head;
    
    while (current != nullptr) {
        StudentNode* next = current->next;
        
        if (current->grade == grade) {
            // 找到了要删除的节点
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            
            factory.recycleNode(current); // 回收节点到工厂
            removedCount++;
            size--;
        }
        
        current = next;
    }
    
    return removedCount;
}

bool StudentList::findById(int studentId, int& grade) const {
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->studentId == studentId) {
            grade = current->grade;
            return true;
        }
        current = current->next;
    }
    return false;
}

void StudentList::findByGrade(int grade) const {
    StudentNode* current = head;
    bool found = false;
    
    while (current != nullptr) {
        if (current->grade == grade) {
            std::cout << current->studentId << " ";
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        std::cout << "没有找到成绩为 " << grade << " 的学生";
    }
    std::cout << std::endl;
}

void StudentList::printAll() const {
    if (head == nullptr) {
        std::cout << "学生列表为空" << std::endl;
        return;
    }
    
    StudentNode* current = head;
    while (current != nullptr) {
        std::cout << current->studentId << " " << current->grade << std::endl;
        current = current->next;
    }
}

int StudentList::getSize() const {
    return size;
}