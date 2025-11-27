//LuoguP1182, 2025.11.27
//最大值最小->二分答案
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
const int MAXNN=1e9+10;

long long N,M;
long long a[MAXN];
long long ans;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;//分成M段,每段和最大值的最小值
    for(int i=0;i<N;i++)cin>>a[i];
}

/*
bool check(long long x){//每段和的最大值
    long long cnt=0,sum=0;
    for(int i=0;i<N;i++){
        if(a[i]>x) return 0;
        sum+=a[i];
        if(sum>x){
            sum=0;
            cnt++;
            i--;
        }
        if(i==N-1){
            cnt++;
            break;
        }
    }

    return cnt<=M;
}*/

bool check(long long x) {
    long long cnt = 1;       // 只要有数据，初始就是第1段
    long long current_sum = 0;
    
    for(int i = 0; i < N; i++) {
        // 如果单个数本身就大于限制x，直接不可能，返回false
        // (注：如果二分下界Left设为了max(a[i])，这一句其实可以省略)
        if(a[i] > x) return false; 
        
        if(current_sum + a[i] > x) {
            // 如果加上当前数超过了x，说明当前数必须作为新的一段的开始,使用//前一段的和//
            cnt++;
            current_sum = a[i]; //直接赋予此值
        } else {
            // 否则，加到当前段中
            current_sum += a[i];
        }
    }
    
    return cnt <= M;
}

long long binary_answer(){//针对于“每段和的最大值->left,right,mid”,最小值,往小了搜索
    long long left=1,right=MAXNN;
    while(right>=left){
        long long mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            right=mid-1;
        }else left=mid+1;
    }

    return ans;
}

int main(){
    input();
    cout<<binary_answer()<<endl;

    return 0;
}