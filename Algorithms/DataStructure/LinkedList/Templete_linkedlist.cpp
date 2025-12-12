#include <iostream>
using namespace std;

// ==========================================
// 1. 节点定义 (数据域 + 指针域)
// ==========================================
template <typename T>
struct Node {
    T val;              // 数据
    Node* next;         // 指针

    // 构造函数：方便你用 new Node(10) 直接赋值
    Node(T v) : val(v), next(nullptr) {}
};

// ==========================================
// 2. 链表工具箱 (函数集)
// ==========================================

/**
 * 核心难点解析：为什么要用 Node*& head (指针的引用)？
 * - 如果只传 Node* head，函数里修改的是 head 的副本，外面的链表头不会变。
 * - 传 Node*& head，意味着函数里修改 head，外面的 head 也会跟着变。
 *   这对“头部插入”和“删除头节点”至关重要！
 */

// [增] 头插法：O(1) - 最常用的插入方式
template <typename T>
void insertHead(Node<T>*& head, T val) {
    Node<T>* newNode = new Node<T>(val); // 1. 造房子
    newNode->next = head;                // 2. 新房子的下家是旧头
    head = newNode;                      // 3. 现在的头变成新房子
}

// [增] 尾插法：O(N) - 如果没有维护 tail 指针，需要遍历到最后
template <typename T>
void insertTail(Node<T>*& head, T val) {
    if (head == nullptr) {
        insertHead(head, val);
        return;
    }
    Node<T>* p = head;
    while (p->next != nullptr) { // 走到最后一个节点
        p = p->next;
    }
    p->next = new Node<T>(val); // 接在最后
}

// [删] 删除值为 val 的第一个节点
template <typename T>
void remove(Node<T>*& head, T val) {
    if (head == nullptr) return;

    // 特判：如果要删的是头节点
    if (head->val == val) {
        Node<T>* temp = head; // 记住要拆的房子
        head = head->next;    // 头指针移走
        delete temp;          // 拆房
        return;
    }

    // 寻找目标节点的前一个节点 (Pre-node)
    Node<T>* p = head;
    while (p->next != nullptr && p->next->val != val) {
        p = p->next;
    }

    // 找到了 (p->next 就是要删的)
    if (p->next != nullptr) {
        Node<T>* temp = p->next;
        p->next = temp->next; // 跨过 temp 连线
        delete temp;          // 释放内存
    }
}

// [查] 查找是否存在
template <typename T>
Node<T>* find(Node<T>* head, T val) {
    Node<T>* p = head;
    while (p != nullptr) {
        if (p->val == val) return p;
        p = p->next;
    }
    return nullptr;
}

// [改] 修改第 index 个节点的值 (从0开始)
template <typename T>
void update(Node<T>* head, int index, T newVal) {
    Node<T>* p = head;
    for (int i = 0; i < index && p != nullptr; i++) {
        p = p->next;
    }
    if (p != nullptr) p->val = newVal;
}

// [遍历] 打印链表
template <typename T>
void printList(Node<T>* head) {
    Node<T>* p = head;
    while (p != nullptr) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// [销毁] 彻底释放内存 (防止内存泄漏)
template <typename T>
void destroyList(Node<T>*& head) {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==========================================
// 3. 实战测试
// ==========================================
int main() {
    // 这里的 head 就是我在上个回答里说的“手里的签子”
    // 一开始手里什么都没有，指向 nullptr
    Node<int>* myLink = nullptr; //指向头的指针！

    cout << "1. 插入数据:" << endl;
    insertHead(myLink, 10); // [10]
    insertHead(myLink, 20); // [20]->[10]
    insertTail(myLink, 30); // [20]->[10]->[30]
    printList(myLink);

    cout << "\n2. 查找并修改:" << endl;
    Node<int>* target = find(myLink, 10);
    if (target) cout << "Found: " << target->val << endl;
    update(myLink, 2, 999); // 把第3个节点(30)改成999
    printList(myLink);

    cout << "\n3. 删除头节点(20):" << endl;
    remove(myLink, 20);
    printList(myLink);

    cout << "\n4. 销毁链表:" << endl;
    destroyList(myLink);
    printList(myLink); // 应该是 NULL

    return 0;
}