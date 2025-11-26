//Luogu P1102
//2025-11-26
#include<bits/stdc++.h>
using namespace std;

const long long MAXN=2e5+10;

bool cmp(int a,int b){
    return a<b;//朝那一边就按什么排列
}

int a[MAXN],n,C,maxm;
long long cnt;

int do_search(int m){
    int top=upper_bound(a,a+n,m)-a;
    int low=lower_bound(a,a+n,m)-a;
    if(m!=a[low])return -1;
    return top-low;
}

int main(){
    cin>>n>>C;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n,cmp);
    maxm=a[n-1];
    for(int i=0;i<n;i++){
        if(a[i]+C>maxm) break;
        int num=do_search(a[i]+C);
        if(num>0){
            cnt+=num;
        }
    }

    cout<<cnt<<endl;
    return 0;
}