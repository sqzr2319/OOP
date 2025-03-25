#ifndef NODE_FACTORY_HPP
#define NODE_FACTORY_HPP

#include "Node.hpp"

class NodeFactory {
private:
    StudentNode* unusedHead;  // 备用节点链表头
    StudentNode* unusedTail;  // 备用节点链表尾
    int unusedCount;          // 备用节点数量

public:
    NodeFactory();
    ~NodeFactory();
    
    // 获取一个节点，如果备用池为空则创建新节点
    StudentNode* getNode();
    
    // 回收一个节点到备用池
    void recycleNode(StudentNode* node);
    
    // 获取备用节点数量（用于测试）
    int getUnusedCount() const;
};

#endif