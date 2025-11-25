#include<stdio.h>
#include<math.h>
#define MAXN 50
long long n;
char str[MAXN];
int pos=0;

void int_to_string(long long n){
    if(n<0) str[pos++]='-';
    if(n/10!=0) int_to_string(n/10);
    str[pos++]='0'+n%10;
}
int main(){
    scanf("%d",&n);

    int_to_string(n);

    printf("%s",str);

    return 0;
}