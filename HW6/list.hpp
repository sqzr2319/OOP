#ifndef List
#define List

typedef struct student{
    int index;
    int score;
    struct student *next;
    struct student *last;
}STUDENT;

class list{
    public:
        list();
        ~list();
        // 按index升序插入
        void insert(int index, int score);
        // 按index删除
        void erase(int index);
        // 按score删除全部
        void erase_all(int score);
        // 按index查找并输出对应score
        void find(int index);
        // 按score查找并输出所有对应index
        void find_all(int score);
        // 输出所有index和score
        void print();
    private:
        STUDENT *head;
        STUDENT *tail;
        int size;
};

#endif