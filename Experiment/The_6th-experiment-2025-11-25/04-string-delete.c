/*
4. 实验P126-7-删除字符

【问题描述】

编写函数实现删除字符串中所有指定字符的功能。

【编程要求】

(1) 字符串和要删除的字符都从键盘输入；

(2) 字符串的读入及字符删除操作都用函数实现；

(3) 编写主程序完成函数功能的测试；

(4) 函数原型参考：

    void getString(char[]);

    void deleteCharInString(char[], char);

【输入形式】

共2行。

第1行：一个字符串，待删除指定字符的字符串，不包含换行符，可包含空格和制表符，长度不超过100；

第2行：一个字符，待删除的指定字符。

【输出形式】

共1行：删除指定字符后的字符串。

【样例输入】


C Programming Language
a

【样例输出】

C Progrmming Lnguge
*/
#include<stdio.h>
#include<string.h>
#define MAXN 100001
char str[MAXN],ans[MAXN];
char delstr;
int posans=0;

void getstring(char ch[]){
    //fgets(ch,sizeof(ch),stdin);作为指针传递时,ch是数组指针,只能占有8位,所以只能读取8个字符
    fgets(ch,MAXN,stdin);
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]=='\n') ch[i]='\0';
    }
}

void deleteCharString(char str[],char delstr){
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=delstr) ans[posans++]=str[i];
    }
}

int main(){
    getstring(str);
    scanf("%c",&delstr);

    deleteCharString(str,delstr);

    ans[posans++]='\0';
    printf("%s",ans);
    return 0;
}