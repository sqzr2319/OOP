#include "StudentList.hpp"
#include <iostream>

StudentList::StudentList(NodeFactory& nodeFactory) 
    : head(nullptr), tail(nullptr), size(0), factory(nodeFactory) {
}

StudentList::~StudentList() {
    // �ͷ����нڵ㣬�����Ի��յ�����
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
    // �ӹ�����ȡһ���ڵ�
    StudentNode* newNode = factory.getNode();
    newNode->studentId = studentId;
    newNode->grade = grade;
    
    if (head == nullptr) {
        // ������
        head = newNode;
        tail = newNode;
        size = 1;
        return;
    }
    
    // �ҵ����ʵ�λ�ò��루��ѧ������
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->studentId > studentId) {
            // ���뵽currentǰ��
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
            // ���³ɼ�
            current->grade = grade;
            factory.recycleNode(newNode); // ����δʹ�õĽڵ�
            return;
        }
        current = current->next;
    }
    
    // ���뵽����β��
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
            // �ҵ���Ҫɾ���Ľڵ�
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
            
            factory.recycleNode(current); // ���սڵ㵽����
            size--;
            return true;
        }
        current = current->next;
    }
    
    return false; // δ�ҵ�ָ��ѧ��
}

int StudentList::removeByGrade(int grade) {
    if (head == nullptr) return 0;
    
    int removedCount = 0;
    StudentNode* current = head;
    
    while (current != nullptr) {
        StudentNode* next = current->next;
        
        if (current->grade == grade) {
            // �ҵ���Ҫɾ���Ľڵ�
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
            
            factory.recycleNode(current); // ���սڵ㵽����
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
        std::cout << "û���ҵ��ɼ�Ϊ " << grade << " ��ѧ��";
    }
    std::cout << std::endl;
}

void StudentList::printAll() const {
    if (head == nullptr) {
        std::cout << "ѧ���б�Ϊ��" << std::endl;
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