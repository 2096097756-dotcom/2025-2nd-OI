#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义链表节点结构体
typedef struct STEvent {
  int year;             // 年份
  char content[200];    // 大事件内容
  struct STEvent* next; // 指针域，指向下一个节点
} EventNode, *EventList,eventlist[1000];//这里是定义了一个链表，指向第一个元素
/*

所有都为形参！不是实参！
*/
//在注意：这里不能动头节点！头节点内容是垃圾值，只能动下一个数据节点！
// 1. 初始化带头节点的链表
void InitEventList(EventList *L) {
  *L = (EventList)malloc(sizeof(EventNode));
  if (*L == NULL) {
    exit(0);
    return;
  }
  (*L)->next = NULL; // 头节点指针域置空
  return;
}

// 2. 按年份升序插入节点
// 如果年份已存在，插入失败并输出"该年份事件已存在，插入失败！\n"
// 成功插入则输出"事件插入成功！\n"
void InsertEventByYear(EventList L, int year, const char *content) {

    EventNode* prev=L;//全程都在修改L指向的值，而不是L的地址，像数组一样，一级指针足够了
    //而更改头指针就涉及到头地址的改变，就需要二级指针了

    while(prev->next!=NULL&&prev->next->year<year) prev=prev->next;
    if(prev->next!=NULL&&prev->next->year==year){
        printf("该年份事件已存在，插入失败！\n");
        return ;
    }

    EventNode* new_node=(EventNode*)malloc(sizeof(EventNode));//在堆上分配空间就可以保证永久

    new_node->year=year;

    if(new_node->content!=NULL){
        strcpy(new_node->content,content);
    }
    new_node->content[199]='\0';
    
    //找到最后一个年份小于year的节点
    
    new_node->next=prev->next;  // 新节点指向后继节点
    prev->next=new_node;        // 前驱节点指向新节点
    
    printf("事件插入成功！\n");

    return ;
  // TODO
  // 1. 检查年份是否已存在
  // 2. 找到插入位置（前驱节点）
  // 3. 分配新节点并赋值
  // 4. 插入节点
}

// 3. 遍历打印所有大事记
void TraverseEventList(EventList L) {
  EventNode *p = L->next;
  if (p == NULL) {
    printf("暂无任何科技大事记！\n");
    return;
  }
  printf("===== 中国科学技术大大事记 =====\n");
  while (p != NULL) {
    printf("[%d] %s\n", p->year, p->content);
    p = p->next;
  }
  printf("===============================\n");
}

// 4. 按年份查找事件
// 如果找到则打印事件内容，格式为"[年份] 内容\n"
// 否则提示输出"未查询到该年份的大事记！\n"
void SearchEventByYear(EventList L, int year) {
    EventNode* node=L;
    node=node->next;
    while(node!=NULL){
        if(node->year==year){
            printf("[%d] %s\n",node->year,node->content);
            return ;
        }
        else node=node->next;
    }
    if(node==NULL){
        printf("未查询到该年份的大事记！\n");
        return ;
    }
    return ;
  // TODO
}

// 5. 按年份删除事件
// 如果找到并删除成功则输出"删除成功！\n"
// 否则输出"未找到该年份事件，删除失败！\n"
// Note: 注意释放被删除节点的内存，没做的助教会扣分哦~
void DeleteEventByYear(EventList L, int year) {
    EventNode* node=L;
    EventNode* prev=L;
    node=node->next;
    prev=node->next;
    while(node!=NULL){
        if(node->year==year){
            if(node->next==NULL){
                prev->next=NULL;
                printf("删除成功！\n");
                return ;
            } 
            else{
                prev->next=node->next;
                printf("删除成功！\n");
                free(node);
                node=NULL;
                return ;//注意直接return;
            }
        }
        prev=node;
        node=node->next;
    }
    if(node==NULL){
        printf("未找到该年份事件，删除失败！\n");
        return ;
    }

    return ;
  // TODO
}

// 6. 销毁链表
void DestroyEventList(EventList *L) {
  EventNode *p = *L;
  EventNode *q;
  while (p != NULL) {
    q = p->next;
    free(p); // 释放节点内存
    p = q;
  }
  *L = NULL; // 链表置空
  printf("链表已销毁，内存释放完成！\n");
}

// 菜单界面
void ShowMenu() {
  printf("===== 中国科学技术大大事记管理系统 =====\n");
  printf("1. 插入科技大事记（按年份排序）\n");
  printf("2. 查看所有大事记\n");
  printf("3. 按年份查询大事记\n");
  printf("4. 按年份删除大事记\n");
  printf("0. 退出程序\n");
  printf("========================================\n");
  printf("请输入您的选择：");
}

int main() {
  EventList L;
  // 初始化链表
  InitEventList(&L);

  int choice;
  int year;
  char content[200];
  while (1) {
    ShowMenu();
    scanf("%d", &choice);
    getchar(); // 吸收换行符，避免影响后续字符串输入

    switch (choice) {
    case 1:
      printf("请输入年份：");
      scanf("%d", &year);
      getchar();
      printf("请输入该年份的科技大事记内容：");
      fgets(content, sizeof(content), stdin);
      // 去除fgets读取的换行符
      content[strcspn(content, "\n")] = '\0';
      InsertEventByYear(L, year, content);
      break;
    case 2:
      TraverseEventList(L);
      break;
    case 3:
      printf("请输入要查询的年份：");
      scanf("%d", &year);
      SearchEventByYear(L, year);
      break;
    case 4:
      printf("请输入要删除的年份：");
      scanf("%d", &year);
      DeleteEventByYear(L, year);
      break;
    case 0:
      DestroyEventList(&L);
      printf("程序已退出！\n");
      return 0;
    default:
      printf("输入无效，请重新选择！\n");
    }
  }
  return 0;
}