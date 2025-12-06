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

    for(int i=1;i<n;i++){
        int target=a[i];
        int j=i-1;
        while(j>=0&&a[j]>target){
            a[j+1]=a[j];//挪移
            j--;
        }
        a[j+1]=target;//此时下标小于j+1的全部都小于等于了target，并且j不满足条件就是正式指向了第一个小于等于的元素
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}