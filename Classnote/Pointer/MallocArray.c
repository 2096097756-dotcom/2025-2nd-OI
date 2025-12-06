#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int row, col;

    // 图片中没有显示 row 和 col 的赋值过程
    // 这里为了让程序能跑起来，添加了用户输入功能
    printf("请输入行数 (row) 和列数 (col): ");
    scanf("%d %d", &row, &col);

    // --- 对应图片 2 的内容：动态内存分配 ---

    // 1. 分配“行”指针数组
    // p 是一个二级指针，指向一个包含 row 个指针的数组
    int **p = (int **)malloc(row * sizeof(int *));//指针数组
    
    // 检查内存是否分配成功
    if (p == NULL) {
        puts("error!");
        exit(-1);
    }

    // 2. 为每一行分配具体的“列”空间
    for (int i = 0; i < row; i++) {
        p[i] = (int *)malloc(col * sizeof(int));//二次分配!
        // 严谨写法通常在这里也要检查 p[i] 是否为 NULL
    }

    // --- 对应图片 3 的内容：赋值与打印 ---

    // 初始化随机数种子，确保每次运行产生的数字不同
    srand((unsigned)time(NULL));

    // 遍历数组，填充随机数
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // 生成 0 到 100 之间的随机数
            p[i][j] = rand() % 101;
        }
    }

    printf("\n生成的矩阵如下：\n");

    // 遍历数组，打印内容
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // %d\t 表示打印数字后加一个制表符用于对齐
            printf("%d\t", p[i][j]);
        }
        // 每一行打印完后换行
        printf("\n");
    }

    // --- 补充内容：释放内存 ---
    // 图片中没有显示释放内存的代码，但在 C 语言中这是必须的
    // 也就是 malloc 对应必须有 free
    for (int i = 0; i < row; i++) {
        free(p[i]); // 释放每一行的空间
    }
    /*
    和定义一样，这里就是要实现二级指针指向的指针数组和指针数组中每一个指针指向的数组进行内存释放
    */
    free(p); // 释放指针数组的空间

    return 0;
}