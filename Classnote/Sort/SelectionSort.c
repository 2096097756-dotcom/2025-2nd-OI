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

    for(int i=0;i<n-1;i++){//已经排序i个数字,注意i-1=i
        int minindex=i;//注意应该是无序部分的,从i之后就无序了
        for(int j=i;j<n;j++){
            if(a[j]<a[minindex]) minindex=j;
        }
        swap(&a[minindex],&a[i]);
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}