#include "NodeFactory.hpp"
#include <iostream>

NodeFactory::NodeFactory() : unusedHead(nullptr), unusedTail(nullptr), unusedCount(0) {
}

NodeFactory::~NodeFactory() {
    // 释放所有备用节点
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
        // 备用池为空，创建新节点
        StudentNode* newNode = new StudentNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    } else {
        // 从备用池取一个节点
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
    
    // 清除节点的数据
    node->studentId = 0;
    node->grade = 0;
    
    // 添加到备用池
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