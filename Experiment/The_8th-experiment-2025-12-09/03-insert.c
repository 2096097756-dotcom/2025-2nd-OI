//输入一句话，其中包含多个单词并以空格分隔，请把这句话改为“倒装句”，即单词出现的顺序前后颠倒，单词之间有空格，输出该“倒装句”。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 200
char str[MAXN];

int legal(char c){
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')) return 1;
    return 0;
}

char* reversestr(char *str){
    char *newstr;
    newstr=(char*)malloc(MAXN*sizeof(char));//相当于定义了一快连续分配内存的区域
    char word[MAXN][MAXN];
    char pause[MAXN][MAXN];
    int cnt=0,num=0,num2=0;
    int if_inword=0;
    for(int i=0;i<strlen(str);i++){
        if(legal(str[i])){
            if(!if_inword){
                if_inword=1;
                num=0;
            }
            word[cnt][num++]=str[i];
        }
        else{//包括结束符
            if(if_inword){
                word[cnt][num]='\0';//结束了再封口
                if_inword=0;
                cnt++;
            }
        }

    }
    for(int i=cnt-1;i>=0;i--){
        for(int j=0;j<strlen(word[i]);j++){
            newstr[num2++]=word[i][j];
        }
        newstr[num2++]=' ';
    }
    newstr[num2]='\0';
    return newstr;
}


int main(){
    fgets(str,201,stdin);//应该是201!
    printf("%s",reversestr(str));
    return 0;

}