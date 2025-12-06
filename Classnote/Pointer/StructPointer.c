#include <stdio.h>
#include <stdlib.h> // 用于 malloc, free
#include <string.h> // 用于 strcpy

// 定义学生结构体
struct student {
    int sno;        // 学号
    char sname[20]; // 姓名
    float gpa;      // 绩点
};

// ========================================================
// 【左侧模式】修改传入的指针
// 场景：外面已经有了结构体，函数负责修改它
// ========================================================
struct student *getData_ByPointer(struct student *s) {
    // s 指向的是 main 函数里的那个变量
    struct student *temp = s; 
    
    // 修改数据
    temp->gpa = 4.0; 
    
    // 返回传入的地址 (其实这个返回值有时候是多余的，因为外界已经有地址了，
    // 但为了支持链式调用或风格统一，常这么写)
    return temp;
}

// ========================================================
// 【右侧模式】动态分配内存 (Malloc)
// 场景：外面啥也没有，函数负责“造”一个新结构体出来
// ========================================================
struct student *getData_ByMalloc() {
    // 1. 在堆(Heap)上申请一块内存
    struct student *temp = (struct student *)malloc(sizeof(struct student));//地址
    
    // 检查申请是否成功
    if (temp == NULL) {
        return NULL;
    }

    // 2. 填充数据
    temp->sno = 2;
    
    // 注意：字符串数组不能直接用 = 赋值，必须用 strcpy
    strcpy(temp->sname, "kingzong"); //目标字符串,源字符串
    
    temp->gpa = 4.0;

    // 3. 返回堆内存地址 (即使函数结束，这块内存依然存在)
    return temp;
}

int main(void) {
    // -------------------------------------------
    // 测试左侧模式 (传入指针)
    // -------------------------------------------
    printf("=== Test Left Side (Pass Pointer) ===\n");
    // 1. 在栈上定义变量，初始化为 3.5 分
    struct student s = {1, "king", 3.5}; 
    struct student *ps_stack;

    // 2. 传址调用
    ps_stack = getData_ByPointer(&s);

    // 3. 打印结果 (发现分数变成了 4.0)
    printf("Sno:%d, Name:%s, GPA:%.2f\n\n", ps_stack->sno, ps_stack->sname, ps_stack->gpa);


    // -------------------------------------------
    // 测试右侧模式 (Malloc)
    // -------------------------------------------
    printf("=== Test Right Side (Malloc) ===\n");
    struct student *ps_heap;

    // 1. 获取新对象
    ps_heap = getData_ByMalloc();

    if (ps_heap != NULL) {
        // 2. 打印结果
        printf("Sno:%d, Name:%s, GPA:%.2f\n", ps_heap->sno, ps_heap->sname, ps_heap->gpa);
        
        // 3. 【非常重要】用完必须释放！
        free(ps_heap); 
        ps_heap = NULL; // 避免悬空指针
    }

    return 0;
}