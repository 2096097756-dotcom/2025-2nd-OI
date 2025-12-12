#include <stdio.h>

struct ustc
{
    int year;
    char events[200];
    struct ustc *next; // 【修正】这里必须指向自身的结构体类型
} s[4] = {
    // 这里的逻辑是将数组元素串联成一个链表
    {1958, "建校北京", &s[1]},
    {1970, "南迁合肥", &s[2]},
    {1995, "入选211工程", &s[3]},
    {1999, "入选985工程", NULL}
};

int main()
{
    struct ustc *head = s; // head 指向数组的第一个元素,就是s[0]
    
    while(head) // 只要 head 不为 NULL，就继续循环
    {
        printf("%d:%s\n", head->year, head->events);
        head = head->next; // 移动到下一个节点
    }
    
    return 0;
}