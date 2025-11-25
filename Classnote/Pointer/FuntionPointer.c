#include<stdio.h>
int getmax(int a,int b){
    return (a>b)?a:b;
}
int main(){

    int (*pf)(int a,int b);
    pf=getmax;//函数名本身就代表了函数的地址
    printf("max=%d\n",pf(10,20));
    printf("max=%d\n",(*pf)(10,20));

    
}