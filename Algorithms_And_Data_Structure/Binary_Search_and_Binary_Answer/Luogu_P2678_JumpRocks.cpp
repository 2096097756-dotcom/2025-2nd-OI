//Luogu_P2678,2025.11.26
//二分法的核心是单调性,二分答案就是对于答案为自变量进行二分.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;

long long length,n,m,ans;
long long rocks[MAXN];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>length>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>rocks[i];
    }
    rocks[0]=0;//考虑开始和结尾
    rocks[n+1]=length;
} 

/*
注意区分"需要跳过的最小距离"与"能跳过的最小距离"

*/

bool check(long long x){//m:最多能移开的石头
    long long cnt=0,num=0;
    while(cnt<=n){
        for(int i=cnt+1;;i++){//跳过了中间的石头!
            if(i>n+1){
                cnt=i;
                break;//假设距离rocks[n+1]-rocks[n]=x1<x,间隔距离没有到x,这里也是合理的!
            }
            if(rocks[i]-rocks[cnt]>=x){
                cnt=i;
                break;
            }
            num++;
        }
        if(cnt>n+1) break;
    }
    if(num<=m) return 1;
    return 0;
}

/*
贪心线性扫描算法:
// 修改后的 check 函数：标准贪心策略
bool check(long long x) {
    long long cnt = 0;      // 记录移走的石头数量
    long long current_pos = 0; // 当前所在位置的坐标（注意：不是下标，是值）
    
    // 遍历所有石头，包括终点 (终点是 rocks[n+1])
    for(int i = 1; i <= n + 1; i++){
        // 计算当前位置到第 i 块石头的距离，只需要移动current-pos指针就可以了!
        if(rocks[i] - current_pos < x){
            // 距离小于 x，不满足条件，必须移走第 i 块石头
            cnt++; 
            // 注意：这里 cnt++ 对于 i==n+1 (终点) 也是成立的。
            // 逻辑上相当于：因为到终点距离不够，所以必须移走它"前面"的那块石头来凑距离。
            //就是站在最后一块石头上，移走脚下的石头来符合跳过的最少距离
            //这是总是成立的，因为前面的一段距离总是大于等于要求的最小长度！
            // 只要计数器增加即可，不必深究移走的是谁。
        } else {
            // 距离足够，跳过去
            current_pos = rocks[i]; 
        }
    }
    
    // 只要移走的总数不超过 m，这个答案 x 就是可行的
    return cnt <= m;
}
*/

long long binary_searching(){//如果间距为L,能过去吗?
    long long right=length;
    long long left=1;
    while(right>=left){
        long long mid=left+(right-left)/2;
        if(check(mid)){//间隔太小了!
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return ans;
}


int main(){//"最大的最短跳跃距离"
    input();
    cout<<binary_searching();
    return 0;
}