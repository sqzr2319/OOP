#ifndef NODE_FACTORY_HPP
#define NODE_FACTORY_HPP

#include "Node.hpp"

class NodeFactory {
private:
    StudentNode* unusedHead;  // ���ýڵ�����ͷ
    StudentNode* unusedTail;  // ���ýڵ�����β
    int unusedCount;          // ���ýڵ�����

public:
    NodeFactory();
    ~NodeFactory();
    
    // ��ȡһ���ڵ㣬������ó�Ϊ���򴴽��½ڵ�
    StudentNode* getNode();
    
    // ����һ���ڵ㵽���ó�
    void recycleNode(StudentNode* node);
    
    // ��ȡ���ýڵ����������ڲ��ԣ�
    int getUnusedCount() const;
};

#endif