#include<stdio.h>
#define MAXN 1000000

int n;
int a[MAXN];

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);//在每次移动中抓大头,另外对于第一次,j+1正好满足了n
        }
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}