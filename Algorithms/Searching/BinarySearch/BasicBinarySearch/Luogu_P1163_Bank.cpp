//二分法解决复杂方程
//利率模型
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
const double MAXNN=3;
const double MINM=1e-5;

double w0,w,m;
double ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>w0>>w>>m;
}

bool check(double x){
    double sum=0,money=w0;
    for(int i=1;i<=m;i++){
        sum=x*money-w;//sum:欠款
        money=sum;
    }
    return sum<=0;//利率太大了
}

double binary_answer(){//连续二分

    double left=0.99,right=6.01;
    while(abs(right-left)>MINM){
        double mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            left=mid;
        }else right=mid;
    }
    return (ans-1)*100;
}

int main(){
    input();
    cout<<fixed<<setprecision(1)<<abs(binary_answer());

    return 0;
}