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
    //声明一个新的指针 ，这个指针 指向一个新建的初始化变量.
    new_node->next=head_linkedlist;//语法糖+可以直接利用地址引用
    head_linkedlist=new_node;//头指针指向新的节点!这个时候在堆里面他们还是连在一起的
    return ;
    
}
/*
指针传入的地址的改变是虚的
解引用之后改变的是堆内存！就是说指向的值是实的
“把它改成地址传递，就能实现了。这是因为我们做的是对指针指向的内容的改变，改变的是该地址对应的真实内存（无论是栈还是堆），而不是仅仅修改了函数里的复印件。”
*/
void insert_tail(Node* &head_linkedlist,int val){//注意这个&,是地址传递!,传递的是地址的值，会真的改变head 的值
    //对于地址，是值传递的，我们真的拿到了真实的地址，从而可以改变函数真正的值
    //改变低一级的
    //凡是涉及修改链表结构（插入、删除）的函数，参数一律用 Node*& head。
    //这里全部是实参！
    if(head_linkedlist=nullptr){
        head_linkedlist=new Node(val);
        return ;
    }

    Node* curr_ptr=head_linkedlist;
    Node* new_node=new Node(val);
    while(curr_ptr->next!=nullptr){//不能改变头指针！
        curr_ptr=curr_ptr->next;// 接在最后，这里确实将堆内存（公共内存）接在了后面
        //注意:当改变p=p->next时，改变的是值
        //当改变p->next=A时，改变的是堆内存
    }
    curr_ptr->next=new_node;
    return ;
}

//这里涉及到指针的地址的改变就用地址传递，比如引入一个新节点，让头节点重新等于这个节点
//但是我们写的.next是修改指针指向的内容，这里地址不变（传入的也是地址），改变的就是真实的堆内存
/*
// 依然是值传递
void append(Node* head, int val) {
    // 特判空链表
    if (head == nullptr) {
        // 4. 这里的 head 是 main 函数里那个 nullptr 的【复印件】
        // 你让复印件指向了新房子
        head = new Node(val); 
        return;
    }错误！
    
    // ... 后面的代码 ...
}
*/

int main(){

} 