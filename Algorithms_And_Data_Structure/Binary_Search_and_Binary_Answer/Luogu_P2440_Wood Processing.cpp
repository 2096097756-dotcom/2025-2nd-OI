//Luogu_P2440
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

int n,k,a[MAXN];
long long cnt;

bool calculate_length(long long length){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]/length;
    }
    if(sum>=k) return 1;
    return 0;
}

long long search_wood(){
    long long left=1,right=0;//这里如果left=0,就可能导致mid=0->除以零错误
    //如果left=1,连1都切割不出来(right->0)，就说明cnt=0,逻辑自洽!
    for(int i=0;i<n;i++){
        right+=a[i];
    }
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(calculate_length(mid)){//说明切割的太多了，往长的搜索
            cnt=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    return cnt;
}

int main(){//对于cnt进行离散的二分查找(ans)
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<search_wood()<<endl;
    return 0;
}