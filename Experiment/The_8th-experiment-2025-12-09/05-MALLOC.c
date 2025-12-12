/*
【描述:】
请按如下要求编写程序代码
1、动态创建字符数组，使用指针数组；
2、为字符数组随机生成度不一(5=<lenght<=10)的字符串(只包括大小写的英文字符);
3、将字符数组的内容写入文件a.txt；
4、从文件a.txt中读取内容存入字符数组中；
5、对字符数组按字母升序排序；
6、排序后的字符数组的内容写入文件b.txt。
*作者:kingzong
*日期:2025-12-02 17:01:39
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11
#define MIN 5

const char alphas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char **createPointerArray(int n)
{
    char **p;
    p=(char**)malloc(n*sizeof(char*));//列分配空间，注意这里应该分配的是指针空间
    for(int i=0;i<n;i++){
        *(p+i)=(char*)malloc(MAX*sizeof(char));
    }
    return p; 
}

void initArray(char **s, int n)
{
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++){
        int len=rand()%(MAX-MIN)+MIN;//%(MAX-MIN+1)+MIN
        int len_alpha=strlen(alphas);
        for(int j=0;j<len;j++){
            int index=rand()%(len_alpha);
            *(*(s+i)+j)=alphas[index];
        }
        *(*(s+i)+len)='\0';
    }
   
}

int write_read_file(char *filename, char *mode, char **s, int n)
{
    FILE *fp;
    if ((fp = fopen(filename, mode)) == NULL)
        return -1;
    if (!strcmp(mode, "w")) // 写模式
    {
        for(int i=0;i<n;i++){
            fprintf(fp,"%s\n",*(s+i));
        }

    }
    else // 读模式
    {
        for(int i=0;i<n;i++){
            fscanf(fp,"%s",*(s+i));
        }

    }

    fclose(fp);
    return 0;
}

void sort(char **s, int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            ;//一定要分配空间?
            if(strcmp(*(s+j),*(s+j+1))>0){//字典序!前（长度或者字典序大于后再交换）
                //内容传递是很慢的。需要指针传递！IMPORTANT
                char* temp=*(s+j);//解引用的都是指针！指针传递改变是最好的！
                *(s+j)=*(s+j+1);
                *(s+j+1)=temp;
                /*
                static char *str; // 定义了一个静态指针，默认初始化为 NULL
                // ...
                strcpy(str,*(s+j)); // 错误：试图把数据拷贝到一个空地址
                */
            }

        }
    }
    return ;
}

void print(char **s, int n)
{
    for (int i = 0; i < n; i++)
        puts(s[i]);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    char **p = createPointerArray(n);
    initArray(p, n);
    //print(p, n);

    if (write_read_file("a.txt", "w", p, n) == 0)
        printf("1\n");
    else
        printf("0\n");

    if (write_read_file("a.txt", "r", p, n) == 0)
        printf("1\n");
    else
        printf("0\n");
    sort(p, n);
    //print(p, n);

    if (write_read_file("b.txt", "w", p, n) == 0)
        printf("1\n");
    else
        printf("0\n");

    // 释放一级指针
    for (int i = 0; i < n; i++)
    {
        free(p[i]);
    }
    // 释放二级指针
    free(p);

    return 0;
}