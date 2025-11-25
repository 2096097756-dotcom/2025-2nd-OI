#include <stdio.h>

/**
 * 交换函数 swap3
 * 接收两个二级指针 (int **a, int **b)
 */
void swap3(int **a, int **b)
{
    // 【核心操作】
    // 这里交换的是 *a 和 *b
    // *a 代表 main 函数里的 pa (一级指针)
    // *b 代表 main 函数里的 pb (一级指针)
    // 所以：这里是在交换 pa 和 pb 的指向，而不是交换整数值
    int *temp = *a;
    *a = *b;
    *b = temp;

    // PPT 中函数内部的打印
    // 注意：此时在函数内部，a 已经指向了原 pb 指向的地址
    printf("swap within function:a=%p,b=%p\n", *a, *b);
    printf("swap within function:a=%d,b=%d\n", **a, **b);
}

int main()
{
    // 1. 初始化整数变量
    int a = 1958, b = 2022;

    // 2. 初始化一级指针
    // pa 指向 a, pb 指向 b
    int *pa = &a, *pb = &b;

    // 3. 初始化二级指针
    // ppa 指向 pa, ppb 指向 pb
    int **ppa = &pa, **ppb = &pb;

    // 【交换前打印】
    // *ppa 就是 pa (即 a 的地址)
    // **ppa 就是 a 的值 (1958)
    printf("Before swap3:*ppa=%p,*ppb=%p\n", *ppa, *ppb);
    printf("Before swap3:**ppa=%d,**ppb=%d\n", **ppa, **ppb);

    // 【调用交换函数】
    // 传入 pa 和 pb 的地址
    swap3(&pa, &pb); 
    // 注：这里也可以写成 swap3(ppa, ppb); 效果完全一样

    // 【交换后打印】
    // 此时 pa 变了，pb 也变了
    // pa 变成了指向 b，pb 变成了指向 a
    printf("After swap3:*ppa=%p,*ppb=%p\n", *ppa, *ppb);
    printf("After swap3:**ppa=%d,**ppb=%d\n", **ppa, **ppb);
    
    // 【最终验证】
    // a 和 b 本身的值并没有改变
    printf("After swap3:a=%d,b=%d\n", a, b);

    return 0;
}