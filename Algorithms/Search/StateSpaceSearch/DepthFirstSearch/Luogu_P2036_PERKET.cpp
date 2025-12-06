//总的酸度为每一种配料的酸度总乘积；总的苦度为每一种配料的苦度的总和
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
const int MAXNN=1e7+1;

int n;
struct PERKET{
    int sour,bitter;
}perket[MAXN];
int minm=MAXNN;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>perket[i].sour>>perket[i].bitter;

}

void dfs(int level,int total_sour,int total_bitter,int select){//当前层数,判断；总酸度，总苦度
    if(level>n){
        if(select==0||select>n) return ;
        int value=abs(total_bitter-total_sour);
        minm=min(minm,value);
        return ;
    }

    dfs(level+1,total_sour,total_bitter,select);
    dfs(level+1,total_sour*perket[level].sour,total_bitter+perket[level].bitter,select+1);

    return ;
}

void solve(){
    dfs(1,1,0,0);
}

int main(){

    input();
    solve();
    cout<<minm<<endl;

    return 0;
}

