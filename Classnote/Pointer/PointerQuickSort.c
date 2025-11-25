#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 整数比较函数
 * 规则：返回 (值1 - 值2) 实现升序排列
 */
int comp_int(const void *i1, const void *i2) {
    // 1. (int *)i1  : 将通用指针强转为 int指针
    // 2. *(int *)i1 : 解引用，获取具体的值
    return (*(int *)i1 - *(int *)i2);
}

/**
 * 字符串比较函数
 * 注意：主函数里是 char *str[] (字符串指针数组)
 * 所以这里传入的参数 s1 是指向 "char *" 的指针，即 "char **"
 */
int comp_str(const void *s1, const void *s2) {
    // 1. (char **)s1    : 将通用指针强转为 二级字符指针
    // 2. *(char **)s1   : 解引用一次，获得具体的字符串首地址 (char *)
    // 3. strcmp         : C标准库函数，用于比较两个字符串
    return strcmp(*(char **)s1, *(char **)s2);
}

int main() {
    /*
    (int *)i1：强制类型转换。告诉编译器“把这个通用指针当作整数指针”。
    *(int *)i1：解引用。取出指针指向的整数值。 
    */
    // 声明一个函数指针，它可以指向任何符合 (int)(const void*, const void*) 格式的函数
    int (*cmp)(const void *, const void *);
    
    int i;
    
    // 1. 定义整数数组
    int a[] = {15, 42, 93, 54, 15, 66, 37, 8, 81};
    
    // 2. 定义字符串数组 (指针数组)
    // 保持 PPT 原文的拼写 "Suesan"
    char *str[] = {"Tom", "Mary", "Allen", "Jane", "Suesan", "Jimi"};

    // ================= 处理整数排序 =================
    
    // 让函数指针指向整数比较函数
    cmp = comp_int; 
    
    // 调用 qsort
    // 参数含义：数组首地址, 元素个数, 每个元素的大小, 比较函数指针
    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), cmp);

    // 打印排序后的整数
    printf("Sorted Integers:\n");
    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d\t", a[i]);
    }
    printf("\n\n");

    // ================= 处理字符串排序 =================

    // 让函数指针指向字符串比较函数
    cmp = comp_str;

    // 调用 qsort
    // 注意：这里每个元素的大小是 sizeof(char *)，即指针的大小（通常是4或8字节）
    qsort(str, sizeof(str)/sizeof(str[0]), sizeof(str[0]), cmp);

    // 打印排序后的字符串
    printf("Sorted Strings:\n");
    for (i = 0; i < sizeof(str)/sizeof(str[0]); i++) {
        printf("%s\t", str[i]);
    }
    printf("\n");

    return 0;
}