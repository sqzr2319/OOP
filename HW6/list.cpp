#include<iostream>
#include"list.hpp"

list::list(){
    head=NULL;
    tail=NULL;
    size=0;
}

list::~list(){
    STUDENT *temp=head;
    while(temp!=NULL){
        STUDENT *temp2=temp->next;
        delete temp;
        temp=temp2;
    }
}

void list::insert(int index, int score){
    STUDENT *temp=new STUDENT;
    temp->index=index;
    temp->score=score;
    temp->next=NULL;
    temp->last=NULL;
    if(size==0){
        head=temp;
        tail=temp;
        size++;
        return ;
    }
    STUDENT *temp2=head;
    while(temp2!=NULL){
        if(temp2->index>index){
            if(temp2==head){
                temp->next=head;
                head->last=temp;
                head=temp;
                size++;
                return ;
            }
            temp->next=temp2;
            temp->last=temp2->last;
            temp2->last->next=temp;
            temp2->last=temp;
            size++;
            return ;
        }
        if(temp2->index==index){
            temp2->score=score;
            delete temp;
            return ;
        }
        temp2=temp2->next;
    }
    tail->next=temp;
    temp->last=tail;
    tail=temp;
    size++;
    return ;
}

void list::erase(int index){
    STUDENT *temp=head;
    while(temp!=NULL){
        if(temp->index==index){
            if(temp==head){
                head=head->next;
                if(head!=NULL) head->last=NULL;
                delete temp;
                size--;
                return ;
            }
            if(temp==tail){
                tail=tail->last;
                tail->next=NULL;
                delete temp;
                size--;
                return ;
            }
            temp->last->next=temp->next;
            temp->next->last=temp->last;
            delete temp;
            size--;
            return ;
        }
        temp=temp->next;
    }
}

void list::erase_all(int score){
    STUDENT *current = head;
    while(current != NULL){
        STUDENT *next = current->next; // 保存下一个节点
        if(current->score == score){
            if(current == head){
                head = current->next;
                if(head != NULL)
                    head->last = NULL;
            }
            else{
                current->last->next = current->next;
            }
            if(current == tail){
                tail = current->last;
                if(tail != NULL)
                    tail->next = NULL;
            }
            else{
                if(current->next != NULL)
                    current->next->last = current->last;
            }
            delete current;
            size--;
        }
        current = next;
    }
}

void list::find(int index){
    STUDENT *temp=head;
    while(temp!=NULL){
        if(temp->index==index){
            std::cout<<temp->score<<std::endl;
            return ;
        }
        temp=temp->next;
    }
}

void list::find_all(int score){
    STUDENT *temp=head;
    while(temp!=NULL){
        if(temp->score==score){
            std::cout<<temp->index<<" ";
        }
        temp=temp->next;
    }
    std::cout<<std::endl;
}

void list::print(){
    STUDENT *temp=head;
    while(temp!=NULL){
        std::cout<<temp->index<<" "<<temp->score<<std::endl;
        temp=temp->next;
    }
}