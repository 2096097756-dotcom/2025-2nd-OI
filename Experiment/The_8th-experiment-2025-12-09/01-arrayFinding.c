#include<stdio.h>
const int MAXN=1e6+10;

int n;
int a[200];
int maxsum=-MAXN,maxindex;

int max(int a,int b){
    return (a>b)?a:b;
}

int find_maxm(int *a,int n){
    for(int i=0;i<n-2;i++){
        int sum=0;
        for(int j=i;j<=i+2;j++){
            sum+=*(a+j);
        }
        if(sum>maxsum){
            maxsum=sum;
            maxindex=i;
        }
    }
    return maxindex;
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",find_maxm(a,n));

    return 0;
}