#include<bits/stdc++.h>
using namespace std;

const int MINM=-1e6;
struct Node{
    int value;
    Node* last;
    Node* next;
    Node(int val){
        this->value=val;
        this->last=nullptr;
        this->next=nullptr;
    }
};

Node* new_Deque(){
    Node* new_deque=new Node(MINM);
    return new_deque;
}

bool if_empty(Node*& head_Deque){
    if(head_Deque->value==MINM&&head_Deque->last==nullptr&&head_Deque->next==nullptr) return 1;
    return 0;
}

int sizeof_Deque(Node*& head_Deque){
    if(if_empty(head_Deque)) return 0;

    int cnt=1;
    Node* p=head_Deque;
    while(p->next!=nullptr){
        cnt++;
        p=p->next;
    }
    return cnt;
}

void pushLeft(Node*& head_Deque,int new_value){
    Node* new_node=new Node(new_value);
    if(if_empty(head_Deque)){
        head_Deque->value=new_value;
        return ;
    }
    new_node->next=head_Deque;
    head_Deque->last=new_node;
    head_Deque=new_node;
    return ;
}

void pushRight(Node*& head_Deque,int new_value){
    Node* new_node=new Node(new_value);
    if(if_empty(head_Deque)){
        head_Deque->value=new_value;
        return ;
    }
    Node* p=head_Deque;
    while(p->next!=nullptr){
        p=p->next;
    }
    p->next=new_node;
    new_node->last=p;
    return ;
}

void popLeft(Node*& head_Deque){
    if(if_empty(head_Deque)) return ;
    if(head_Deque->next==nullptr){
        head_Deque->value=MINM;
        return ;
    }
    Node* p=head_Deque->next;
    Node* old_head=head_Deque;
    old_head->next=nullptr;
    p->last=nullptr;
    head_Deque=p;
    delete old_head;
    return ;
}

void popRight(Node*& head_Deque){
    if(if_empty(head_Deque)){
        return ;
    }
    Node* p=head_Deque;
    if(p->next==nullptr){
        head_Deque->value=MINM;
    }
    while(p->next->next!=nullptr){
        p=p->next;
    }
    p->next->last=nullptr;
    p->next=nullptr;
    return ;
}

void print(Node*& head_Deque){
    Node* p=head_Deque;
    if(if_empty(head_Deque)){
        cout<<"NULL!"<<endl;
        return;
    }
    cout<<"the elements of the deque is:";
    cout<<p->value<<' ';
    while(p->next!=nullptr){
        p=p->next;
        cout<<p->value<<' ';
    }
    cout<<endl;
    cout<<"the size of deque is:"<<sizeof_Deque(head_Deque)<<endl;
    return ;
}

void test(){
    Node* new_deque=new_Deque();
    for(int i=1;i<=10;i++) pushLeft(new_deque,i);
    print(new_deque);
    for(int i=11;i<=20;i++) pushRight(new_deque,i);
    print(new_deque);
    for(int i=1;i<=5;i++) popLeft(new_deque);
    print(new_deque);
    for(int i=1;i<=5;i++) popRight(new_deque);
    print(new_deque);
    return ;
}

int main(){

    test();
    return 0;
}