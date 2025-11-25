/*输入10个整数存放于数组中，请用指针处理：如果最小的数不在最前面，则将它和最前面的元素对换位置；
然后，如果最大的数不在最后面，则将它和最后面的元素对换位置。从前到后输出这10个数。*/

#include<stdio.h>
#define MAXN 10
#define MAXNN 1000000

int n,a[MAXN],minn=MAXNN,maxn=0,minindex,maxindex;

void swap(int *a1,int *a2){//如果直接传递变量，确实被交换，但是交换就被销毁了，原件从来都没有被碰过；只有传递地址才可以
    int temp=*a1;
    *a1=*a2;
    *a2=temp;
}

int main(){
    for(int i=0;i<MAXN;i++){
        scanf("%d",&a[i]);
        if(minn>a[i]){
            minindex=i;
            minn=a[i];
        }
    }
    if(minindex!=0) swap(&a[minindex],&a[0]);//这里有可能将maxindex换掉了

    for(int i=0;i<MAXN;i++){
        if(a[i]>maxn){
            maxindex=i;
            maxn=a[i];
        }
    }
    if(maxindex!=9) swap(&a[maxindex],&a[9]);
    
    for(int i=0;i<MAXN;i++){
        printf("%d ",a[i]);
    }
    return 0;
}