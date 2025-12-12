#include <stdio.h>
#include <stdlib.h> // 使用 malloc 和 free 需要包含此头文件

// 1. 定义节点结构体
typedef struct Node {
    int data;           // 数据域：存放数据
    struct Node* next;  // 指针域：指向下一个节点
} Node;

// 辅助函数：创建一个新节点
// 作用：分配内存，初始化数据，将next设为NULL
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 2. 尾插法：在链表末尾添加节点
// 注意：这里用 Node** headRef 是为了能修改头指针（处理空链表的情况）
void appendNode(Node** headRef, int data) {//改变地址上的值！仍然是值传递！
    Node* newNode = createNode(data);

    // 情况A：如果链表为空，新节点就是头节点
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // 情况B：链表不为空，找到最后一个节点
    Node* temp = *headRef;//链表作为指针,*temp就是
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 将最后一个节点的 next 指向新节点
    temp->next = newNode;
}

// 3. 删除节点：根据数值删除第一个匹配的节点
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;//temp指针指向第一个元素的地址
    Node* prev = NULL;

    // 情况A：头节点就是要删除的节点
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next; // 改变头指针指向下一个
        free(temp);            // 释放内存
        printf("已删除头节点: %d\n", key);
        return;
    }

    // 情况B：遍历查找要删除的节点
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果没找到
    if (temp == NULL) {
        printf("未找到数值: %d\n", key);
        return;
    }

    // 找到了，执行删除操作（跳过 temp）
    prev->next = temp->next;
    free(temp);
    printf("已删除节点: %d\n", key);
}

// 4. 打印链表
void printList(Node* head) {
    Node* temp = head;
    printf("当前链表: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 5. 销毁链表（释放所有内存）
// 养成好习惯，程序结束前清理内存
void freeList(Node** headRef) {
    Node* current = *headRef;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next; // 先记住下一个节点
        free(current);            // 再释放当前节点
        current = nextNode;       // 移动指针
    }
    *headRef = NULL; // 头指针置空，防止野指针
    printf("链表内存已释放。\n");
}

int main() {
    // 初始化头指针为空，表示空链表
    Node* head = NULL;

    // 添加数据
    appendNode(&head, 10);//值传递变成了地址传递
    appendNode(&head, 20);
    appendNode(&head, 30);
    printList(head); // 输出: 10 -> 20 -> 30 -> NULL

    // 删除中间节点
    deleteNode(&head, 20);
    printList(head); // 输出: 10 -> 30 -> NULL

    // 删除头节点
    deleteNode(&head, 10);
    printList(head); // 输出: 30 -> NULL

    // 删除不存在的节点
    deleteNode(&head, 99);

    // 释放内存
    freeList(&head);
    
    return 0;
}