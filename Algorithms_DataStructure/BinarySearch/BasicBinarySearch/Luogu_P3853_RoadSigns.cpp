//P3853,2025-11-27
/*
B 市和 T 市之间有一条长长的高速公路，这条公路的某些地方设有路标，但是大家都感觉路标设得太少了，相邻两个路标之间往往隔着相当长的一段距离。为了便于研究这个问题，我们把公路上相邻路标的最大距离定义为该公路的“空旷指数”。

题目描述
现在政府决定在公路上增设一些路标，使得公路的“空旷指数”最小。他们请求你设计一个程序计算能达到的最小值是多少。请注意，公路的起点和终点保证已设有路标，公路的长度为整数，并且原有路标和新设路标都必须距起点整数个单位距离。

输入格式
第 1 行包括三个数 L,N,K，分别表示公路的长度，原有路标的数量，以及最多可增设的路标数量。

第 2 行包括递增排列的 N 个整数，分别表示原有的 N 个路标的位置。路标的位置用距起点的距离表示，且一定位于区间 [0,L] 内。
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;

long long L,N,K;
long long road[MAXN];
long long ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>L>>N>>K;
    for(int i=0;i<N;i++) cin>>road[i];
}

//除法就是  取整函数!
bool check(long long x){//考虑在已经插入若干个路标的way里面继续插入路标
    //最大
    long long temp=K;

    for(int i=1;i<N;i++){
        long long length=road[i]-road[i-1]-1;
        temp-=length/x;
    }

    return temp>=0;
}

long long binary_answer(){//最大距离是L可以吗?如果可以,往小了搜索
    //最小
    long long left=1,right=L;

    while(right>=left){
        long long mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    return ans;
}

int main(){
    input();
    cout<<binary_answer();

    return 0;
}