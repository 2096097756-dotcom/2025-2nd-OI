#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
const double MAXNN=1e10+1;
const double MINN=1e-9;

double ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(double t){
    
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

/*long long binary_answer(){//找到最小值
    //最小
    long long left=1,right=L;

    while(right>=left){
        long long mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            right=mid-1;//与下面调换:找到……的最大值
        }else{
            left=mid+1;
        }
    }

    return ans;
}*/

int main(){
    input();
    cout<<binary_answer();

    return 0;
}