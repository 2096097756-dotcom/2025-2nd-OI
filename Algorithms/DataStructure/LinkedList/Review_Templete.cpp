#include<bits/stdc++.h>
using namespace std;

struct Node{

    int value;
    Node* next;//指针指向一个node地址
    //Node(T v) : val(v), next(nullptr) {}用来初始化T,方便你用 new Node(10) 直接赋值
    Node(int val){
        this->value=val;
        this->next=nullptr;
    }

};

void insert_head(Node* &head_linkedlist,int val){//用头指针来指代整个链表
    if(head_linkedlist=nullptr){
        head_linkedlist=new Node(val);
        return ;
    }

    Node* new_node=new Node(val);//指向node类型的指针？指针在变量后面
    new_node->next=head_linkedlist;//语法糖+可以直接利用地址引用
    head_linkedlist=new_node;//头指针指向新的节点!这个时候在堆里面他们还是连在一起的
    return ;
    
}

void insert_tail(Node* &head_linkedlist,int val){//注意这个&,是地址传递!,传递的是地址的值，会真的改变！
    if(head_linkedlist=nullptr){
        head_linkedlist=new Node(val);
        return ;
    }

    while(head_linkedlist->next!=nullptr){//不能改变头指针！
        
    }

}

int main(){

} 