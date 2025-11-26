//Luogu P1873,2025/11/26
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;

long long a[MAXN],n,m;

long long count(int num){
    long long cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>=num) cnt+=(a[i]-num);
    }
    return cnt;
}

int binary_search(int left,int right){
    if(left>right) return right;//标准的递归中止代码，left停留在第一个不满足条件,right停留在最后一个满足条件的位置
    int mid=left+(right-left)/2;
    long long sum=count(mid);
    if(sum>=m) return binary_search(mid+1,right);//大于等于,否则会漏掉精确解,给left操作空间更大，才能使得在接下来>right
    //寻找大于等于m的第一个索引(H),中间其实是check()，条件恰好为m>=sum;
    else return binary_search(left,mid-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    long long maxm=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxm=max(maxm,a[i]);
    }
    cout<<binary_search(0,maxm)<<endl;
    return 0;
}
/*
用gemini给出的方法写:
int ans;//注意ans定义在循环的外面.
while(left<=right){
    int mid=left+(right-left)/2;
    long long sum=count(mid);
    if(sum>=m){//题目所给的条件,就是找符合要求的至少得到m的树木
        ans=mid;//这个时候mid就符合要求，记录下来
        left=mid+1;//往右边搜索,找到最大的索引
    }else{
        right=mid-1;//往左边搜索，不记录不符合要求的ans
    }
}
    [left=mid+1,right=mid-1,mid]索引,只有这样才能出现right<left的余地!
*/