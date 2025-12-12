#include<stdio.h>
#include<stdlib.h>
const int MAXN=100000;

typedef struct Node{
    int value;
    Node* next;
}Node;//"Node"是别名

Node example[MAXN];

Node* createNewNode(int data){
    //返回的是新节点的地址
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("创建节点失败！\n");
        free(newnode);
        exit(1);
    }

    newnode->value=data;
    newnode->next=NULL;
    return newnode;
}
/*
和数组的区别：
数组：只需要改变值，所以只需要一级指针的运算；
链表：需要改变指针的指向（默认*headRef指向第一个节点），所以需要指针的地址，所以需要二级指针
改变某一个值，所以需要它的指针作为容器.
*/

//尾插法
void tail_insert(Node **headRef,int data){
    Node* target=*headRef;//** headref的解引用，一般的链表可以类比成数组，传递按照
    Node* newnode=createNewNode(data);
    if(target==NULL){
        target=newnode;//newnode是一个新节点的地址
        return ;
    }
    while(target!=NULL){
        target=target->next;
    }
    target->next=newnode;//下一个节点的的地址指向这个新结点的地址.newnode仍然是地址或者是指针变量
    return ;
}

void deleteNode(Node **headRef,int data){
    if(*headRef==NULL){
        free(headRef);
        printf("头已删除\n");
        return ;
    }

    Node* target=*headRef;//注意，这里的target拿出来了*headRef的第一个地址
    Node* prev=*headRef;
    while(target!=NULL&&target->value!=data){
        prev=target;
        target=target->value;
    }
    if(target==NULL){
        printf("没有找到！\n");
        return ;
    } 
    prev->next=target->next;
    return ;

}


int main(){

}