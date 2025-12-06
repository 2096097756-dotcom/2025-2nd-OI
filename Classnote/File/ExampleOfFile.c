#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 定义结构体
struct student {
    char sNo[12];    // 学号
    char sName[20];  // 姓名
    // 截图里似乎有 sName2，这里为了简单先只用一个名字，或者你可以加一个 char sName2[20];
    int age;         // 年龄
    float scores[5]; // 5门课成绩
};

int main() {
    // 2. 初始化一些模拟数据 (数组 s2)
    struct student s2[3] = {
        {"202501", "Alice", 18, {85.5, 90.0, 88.0, 92.0, 80.0}},
        {"202502", "Bob",   19, {70.0, 75.5, 80.0, 65.0, 78.0}},
        {"202503", "Charlie",20,{95.0, 92.0, 98.0, 89.0, 90.0}}
    };

    FILE *fp;//解释：FILE 是 C 语言定义的一个结构体，用来存放文件的信息（如缓冲区、当前读写位置等）。fp 是一个指针，指向这个结构体。以后所有的操作（读、写、关闭）都要靠这个 fp 来指挥。
    int i;

    // ==========================================
    // 第一步：将数据写入文件 (Write to File)
    // ==========================================
    if ((fp = fopen("data.txt", "w")) == NULL) {//注意前后
        puts("Open file error!");
        exit(-1);
    }

    /*
    fopen：打开文件函数。
    "data.txt"：文件名。如果文件不存在，会自动创建；如果文件已存在，会被清空/覆盖。
    "w" (Write)：表示以“只写”模式打开。
    NULL 检查：如果磁盘满了或者没有权限，文件打开会失败，fopen 返回 NULL。这一步是防错处理。
    */

    // 循环写入数据
    for (i = 0; i < 3; i++) {
        // 使用逗号作为分隔符，写入学号、姓名、年龄和5个成绩
        // 注意：最后的 \n 是为了换行，方便下次按行读取
        fprintf(fp, "%s %s %d %.2f %.2f %.2f %.2f %.2f\n", 
                s2[i].sNo, s2[i].sName, s2[i].age,
                s2[i].scores[0], s2[i].scores[1], s2[i].scores[2], s2[i].scores[3], s2[i].scores[4]);//注意这里应该是加上fp
    }

    // 写完必须关闭！否则数据可能还在内存缓冲区里
    fclose(fp);//注意关闭,而且关闭的就是fp指针
    printf("Data written to data.txt successfully.\n\n");


    // ==========================================
    // 第二步：从文件中读取数据 (Read from File)
    // ==========================================
    struct student s5[3]; // 用来存放读取出来的数据

    // 必须重新打开，这次用 "r" (Read) 模式
    if ((fp = fopen("data.txt", "r")) == NULL) {
        puts("Open file error (read)!");
        exit(-1);
    }

    printf("Reading data from file:\n");
    for (i = 0; i < 3; i++) {
        // fscanf 对应上面的 fprintf 格式
        // 注意：fscanf 读取字符串遇到空格会停止，所以这里用空格分隔比较安全
        fscanf(fp, "%s %s %d %f %f %f %f %f", 
               s5[i].sNo, s5[i].sName, &s5[i].age,
               &s5[i].scores[0], &s5[i].scores[1], &s5[i].scores[2], &s5[i].scores[3], &s5[i].scores[4]);
        
        // 打印到屏幕验证读取是否正确
        printf("Student %d: %s, %s, Age: %d, Score1: %.2f\n", 
               i+1, s5[i].sNo, s5[i].sName, s5[i].age, s5[i].scores[0]);
    }

    fclose(fp);

    return 0;
}