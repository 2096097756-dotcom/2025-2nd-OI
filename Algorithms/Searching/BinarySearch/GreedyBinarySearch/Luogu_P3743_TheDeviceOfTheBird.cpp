//LuoguP3743,2025.11.27
//求最大时间:用二分?单调性?
/*1. 为什么可以使用二分查找？
找到时间值T(边界!)使得对于大于时间值都不成立,小于时间值都成立!
2.思路是什么?
不用特别的找一个时间t，先确定一个时间t，在根据贪心判断是否合理!
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
const double MAXNN=1e10+1;
const double MINN=1e-9;

double n,k;
struct PRODUCT{
    double a;
    double b;
}product[MAXN];

double ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>product[i].a>>product[i].b;
}

bool check(double t){//先定下来时间t来考虑
    double sum=0;
    for(int i=0;i<n;i++){
        double num=product[i].b-t*product[i].a;
        if(num<0) sum-=num;
    }
    return sum<=(k*t);//统一时间
}

double binary_answer(){//连续二分

    double left=0,right=MAXNN;
    for(int i=0;i<100;i++){
        double mid=left+(right-left)/2;
        if(mid>MAXNN-1) return -1;
        if(check(mid)){
            ans=mid;
            left=mid;
        }else right=mid;
    }
    return ans;
}

int main(){
    input();
    cout<<binary_answer();

    return 0;
}