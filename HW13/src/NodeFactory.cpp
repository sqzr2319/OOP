#include "NodeFactory.hpp"
#include <iostream>

NodeFactory::NodeFactory() : unusedHead(nullptr), unusedTail(nullptr), unusedCount(0) {
}

NodeFactory::~NodeFactory() {
    // �ͷ����б��ýڵ�
    StudentNode* current = unusedHead;
    while (current != nullptr) {
        StudentNode* next = current->next;
        delete current;
        current = next;
    }
    unusedHead = nullptr;
    unusedTail = nullptr;
    unusedCount = 0;
}

StudentNode* NodeFactory::getNode() {
    if (unusedHead == nullptr) {
        // ���ó�Ϊ�գ������½ڵ�
        StudentNode* newNode = new StudentNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    } else {
        // �ӱ��ó�ȡһ���ڵ�
        StudentNode* node = unusedHead;
        unusedHead = unusedHead->next;
        
        if (unusedHead != nullptr) {
            unusedHead->prev = nullptr;
        } else {
            unusedTail = nullptr;
        }
        
        node->next = nullptr;
        node->prev = nullptr;
        unusedCount--;
        
        return node;
    }
}

void NodeFactory::recycleNode(StudentNode* node) {
    if (node == nullptr) return;
    
    // ����ڵ������
    node->studentId = 0;
    node->grade = 0;
    
    // ��ӵ����ó�
    if (unusedHead == nullptr) {
        unusedHead = node;
        unusedTail = node;
        node->prev = nullptr;
        node->next = nullptr;
    } else {
        node->prev = nullptr;
        node->next = unusedHead;
        unusedHead->prev = node;
        unusedHead = node;
    }
    
    unusedCount++;
}

int NodeFactory::getUnusedCount() const {
    return unusedCount;
}