#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val){
        this->value=val;
        this->next=nullptr;
    }
};

Node* head=nullptr;
int n,stua,LeftOrRight;
int m,delete_stu;

Node* New_node(int val){
    Node* new_node=new Node(val);//指向这个新节点"="，新的一定要malloc
    //new给了你一个地址!delete删除了地址对应的堆内存！
    return new_node;
}

void leftinsert(int insert_stu,int target_stu){
    if(head->value==target_stu){
        Node* new_node=New_node(insert_stu);
        new_node->next=head;
        head=new_node;
        return ;
    }
    
    Node* new_node=New_node(insert_stu);
    Node* p=head;
    while(p->next!=nullptr&&p->next->value!=target_stu){
        p=p->next;
    }//p的value
    new_node->next=p->next;
    p->next=new_node;

    return ;
}

void rightinsert(int insert_stu,int target_stu){
    Node* new_node=New_node(insert_stu);
    Node* p=head;
    while(p->next!=nullptr&&p->value!=target_stu){//p.next!=nullptr是共识
        p=p->next;
    }
    if(p->next==nullptr){
        p->next=new_node;
    }else{
        new_node->next=p->next;
        p->next=new_node;
        
        return ;
    }
}


void linkedlistInsert(int insert_stu,int target_stu,int LeftOrRight){
    if(head==nullptr){
        head=New_node(1);
        return ;
    }
    if(LeftOrRight==0) leftinsert(insert_stu,target_stu);
    else rightinsert(insert_stu,target_stu);
    return ;
}

void delete_num(int delete_stu){
    Node* p=head;//地址的值传递!
    if(head->value==delete_stu){
        
        head->value=-1;
        head->next=nullptr;
        return ;
    }
    while(p->next!=nullptr&&p->next->value!=delete_stu){
        p=p->next;
    }
    if(p->next!=nullptr){
        
        Node* delete_node=p->next;
        delete_node=p->next->next;
        p->next=delete_node;
        delete_node->next=nullptr;
        delete delete_node;

    } 
    return ;
}

void print_linkedlist(){
    Node* p=head;
    while(p!=nullptr){
        cout<<p->value<<' ';
        p=p->next;
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    linkedlistInsert(1,1,1);
    for(int i=2;i<=n;i++){
        cin>>stua>>LeftOrRight;
        linkedlistInsert(i,stua,LeftOrRight);
    }

    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>delete_stu;
        delete_num(delete_stu);
    }

    print_linkedlist();
    return 0;
}