#include <stdio.h>
#include <string.h> // 用于 strcpy

// 定义结构体
struct student {
    char sNo[12];
    char sName[20];
    int age;
    float scores[5];
} s1, s2[10], *s; // s1是变量, s2是数组, s是指针

int main() {
    // 【新增步骤】为了演示效果，我们先给 s1 赋值
    // 实际项目中可以通过 scanf 输入或者初始化列表赋值
    strcpy(s1.sNo, "2025001");
    strcpy(s1.sName, "ZhangSan");
    s1.age = 20;
    for(int i=0; i<5; i++) {
        s1.scores[i] = 80.0f + i; // 假造成绩：80, 81, 82...
    }

    // 【关键修复】将指针 s 指向结构体变量 s1 的地址
    // 如果没有这一行，下面使用 s->... 时程序会崩溃
    s = &s1;

    // --- 第一部分：通过结构体变量 (s1.) 访问 ---
    printf("Access via struct variable (s1.):\n");
    printf("%s, %s, %d: ", s1.sNo, s1.sName, s1.age);
    for(int i = 0; i < 5; i++) {
        printf("%.2f\t", s1.scores[i]);
    }
    printf("\n\n");

    // --- 第二部分：通过结构体指针 (s->) 访问 ---
    printf("Access via pointer (s->):\n");
    // "->" 运算符等价于 (*s). ，用于通过指针访问成员
    printf("%s, %s, %d: ", s->sNo, s->sName, s->age);
    for(int i = 0; i < 5; i++) {
        printf("%.2f\t", s->scores[i]);
    }
    printf("\n");

    return 0;
}
/*

是的，完全正确！
针对你图片中的代码写法（使用 char sNo[12] 和 char sName[20] 这种固定数组），在结构体变量被定义的那一刻，存放字符串的空间就已经自动准备好了。
你可以把这种结构体想象成一套精装修的房子：
1. 你的写法 (数组写法)
code
C
struct student {
    char sName[20]; // 这是一个自带的“房间”
};

struct student s1; // 盖了一栋房子 s1
情况：当你定义 s1 时，这 20 个字节的“房间”就已经建在 s1 里面了。
操作：你可以直接把家具（数据）搬进去。
strcpy(s1.sName, "Tom"); ✅ 直接用，不需要 malloc。
2. 另一种写法 (指针写法 - 需要避坑)
code
C
struct student {
    char *sName; // 这只是一张“地契”（指针），没有房间
};

struct student s1; // 盖了一栋房子 s1
情况：定义 s1 时，sName 只是一个指向不知名地方的指针，并没有实际存字符串的空间。
操作：你必须先去买一块地（malloc），把地契填好，才能搬东西。
strcpy(s1.sName, "Tom"); ❌ 直接崩，因为没空间。
s1.sName = (char*)malloc(20); ✅ 必须额外分配空间。
进阶理解：即使是 malloc 整个结构体的情况
即使你后来决定动态分配整个结构体对象（比如用结构体指针），如果成员是数组，你依然不需要为成员额外分配空间。
看这个例子：
code
C
// 你的结构体
struct student {
    char sName[20]; 
};

// 动态分配一个学生对象
struct student *p = (struct student*)malloc(sizeof(struct student));
这里的 malloc 是分配了“整个大结构体”。
因为 sName[20] 包含在这个结构体的大小里。
所以，这唯一的一次 malloc 同时也把字符串的空间分配好了。
你依然可以直接用：strcpy(p->sName, "Tom"); ✅
*/