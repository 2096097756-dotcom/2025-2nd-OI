/*
【问题描述】

编写函数，按出版时间由早到晚的顺序，对图书信息进行排序。在main函数中输入图书信息，调用该函数排序，并输出排序后的图书信息。

【编程要求】

(1) 日期结构体类型及别名定义如下：


    typedef struct date {

        int year;

        int month;

    } DATE;

(2) 图书信息结构体类型定义如下：


    struct book {

        int  num;

        char title[20];

        DATE ptime;

    };

(3) 设图书数量为6，符号常量定义如下：


    #define N 6

(4) 函数原型参考：

    void sortBook(struct book[], int);


(5) 主函数中图书数组定义及函数调用参考：

    struct book lib[N];

    sortBook(lib, N);


【输入形式】

共6行：每行一本图书信息，依次为书号、书名（不含空白字符）、出版年份、出版月份，用空格隔开。

【输出形式】

共6行：按照出版时间由早到晚排序后的图书信息，每行一本图书信息，格式与输入形式相同。

【样例输入】


101 C_Programming 2001 10
102 Calculus 2010 5
103 Linear_Algebra 2001 8
104 Mechanics 2010 9
105 College_English 2020 4
106 Neural_Network 2019 7

【样例输出】


103 Linear_Algebra 2001 8
101 C_Programming 2001 10
102 Calculus 2010 5
104 Mechanics 2010 9
106 Neural_Network 2019 7
105 College_English 2020 4
*/
#include<stdio.h>

#define N 6
typedef struct DATE{
    int year;
    int month;
}date;

struct book{
    int  num;
    char title[20];
    date ptime;
};


void struct_swap(struct book *a,struct book *b){
    struct book temp=*a;
    *a=*b;
    *b=temp;
}

void sortBook(struct book lib[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(lib[j].ptime.year>lib[j+1].ptime.year){
                struct_swap(&lib[j],&lib[j+1]);
            }else if(lib[j].ptime.year==lib[j+1].ptime.year){
                if(lib[j].ptime.month>lib[j+1].ptime.month){
                    struct_swap(&lib[j],&lib[j+1]);
                }
            }
        }
    }
}


int main(){
    struct book lib[N];
    for(int i=0;i<N;i++){
        scanf("%d %s %d %d",&lib[i].num,&lib[i].title,&lib[i].ptime.year,&lib[i].ptime.month);
    }
    sortBook(lib,N);
    for(int i=0;i<N;i++){
        printf("%d %s %d %d\n",lib[i].num,lib[i].title,lib[i].ptime.year,lib[i].ptime.month);
    }
    return 0;
}