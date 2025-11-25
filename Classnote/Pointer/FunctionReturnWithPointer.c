#include <stdio.h>
#include <stdlib.h> // 用于 malloc 示例

// ==========================================
// 【错误示例】左侧代码：返回局部变量的地址
// ==========================================
float *getData_Wrong(float a, float b) {
    float t;
    t = a > b ? a : b;
    // 警告：返回了局部变量的地址！
    // 函数结束后，t 的内存就被释放了。
    return &t; 
}

// ==========================================
// 【正确示例1】右侧代码：返回传入的指针
// ==========================================
float *getData_Right(float *a, float *b) {
    // a 和 b 指向的是 main 函数里的变量
    // main 函数没结束，这些变量就一直活着
    return (*a > *b) ? a : b;
}

// ==========================================
// 【正确示例2】PPT底部提到的：使用动态内存分配
// ==========================================
float *getData_Malloc(float a, float b) {
    // 在堆(Heap)上申请内存
    // 除非手动 free，否则一直存在
    float *p = (float *)malloc(sizeof(float));
    if (p == NULL) return NULL;
    
    *p = (a > b) ? a : b;
    return p;
}

int main(void) {
    float a = 1.0, b = 2.0;
    float *ps;

    // --- 测试正确方法 (PPT 右侧) ---
    // 传入地址 &a, &b
    ps = getData_Right(&a, &b);
    printf("Right Way Result: %.2f\n", *ps);


    // --- 测试 Malloc 方法 (PPT 底部文字) ---
    float *p_heap = getData_Malloc(a, b);
    if (p_heap != NULL) {
        printf("Malloc Way Result: %.2f\n", *p_heap);
        free(p_heap); // 记得释放！
    }


    // --- 测试错误方法 (PPT 左侧) ---
    // 现代编译器通常会在这里报错或警告
    // 运行结果可能是乱码，或者程序崩溃
    /* 
    ps = getData_Wrong(a, b);
    // 此时 ps 是悬空指针
    printf("Wrong Way Result: %.2f\n", *ps); 
    */

    return 0;
}


//struct Student *stu = (struct Student *)malloc(sizeof(struct Student));