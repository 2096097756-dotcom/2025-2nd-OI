#include<stdio.h>
#define MAXN 100001
int n,dec,index=0;
char str[MAXN];
char table[32]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H'};
void dec2sn(int decimal, int radix){
    if(decimal>0) dec2sn(decimal/radix,radix);
    if(decimal==0) return ;
    int num=decimal%radix;
    str[index++]=table[num];
}
int main(){
    scanf("%d%d",&n,&dec);
    dec2sn(n,dec);
    str[index++]='\0';
    printf("%s",str);
}