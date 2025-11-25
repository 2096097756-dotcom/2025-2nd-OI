/*
2025-11-25,16:10
【问题描述】实现一个简单的字符串压缩算法。对于字符串中连续出现的相同字符，将其替换为"字符+出现次数"的形式。例如，"aaa"压缩为"a3"。压缩后的结果也是一行字符串，其中出现次数以字符形式表示（如12次表示为连续的'1''2'字符）。如果压缩后的字符串长度不小于原字符串，则输出原字符串。


【样例输入输出】

abc
abc
aaaaaaaaaaaaaabbb
a14b3
*/
#include<stdio.h>
#include<string.h>
#define MAXN 1000005

char str[MAXN],ans[MAXN];
int posstr=0,posans=0;

void add_num(char *ans,int length){
    if(length>=10) add_num(ans,length/10); 
    ans[posans++]=length%10+'0';
}

void string_fliter(char str[]){
    int lenstr=strlen(str);
    for(int i=0;i<lenstr;i++){
            for(posstr=i;;posstr++){
                if(str[posstr]!=str[posstr+1]) break;
            }
            int length=posstr-i+1;
            char ch=str[i];
            ans[posans++]=str[i];
            add_num(ans,length);
            i=posstr;
    }
}  

int main(){
    fgets(str,sizeof(str),stdin);//sizeof,内存空间
    for(int i=0;i<=strlen(str);i++){
        if(str[i]=='\n') str[i]='\0';
    }

    string_fliter(str);
    ans[posans++]='\0';

    if(strlen(ans)>=strlen(str)){
        printf("%s",str);
        return 0;
    }
    printf("%s",ans);
    return 0;
}