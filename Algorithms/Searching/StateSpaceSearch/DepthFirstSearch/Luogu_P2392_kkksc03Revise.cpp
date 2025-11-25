#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;

/*分成四个小问题:每个小问题都是在找单线程的最小状态
双子集和问题*/

int s[4];
int practice[4][MAXN];
int cnt_time,min_time=MAXN;

void dfs(int current_timeA,int current_timeB,int tasks,int task_name){
    if(tasks==s[task_name]){
        min_time=min(min_time,max(current_timeB,current_timeA));
        return ;
    }
    if(current_timeA>min_time||current_timeB>min_time) return ;
    dfs(current_timeA+practice[task_name][tasks],current_timeB,tasks+1,task_name);
    dfs(current_timeA,current_timeB+practice[task_name][tasks],tasks+1,task_name);
    return ;
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<4;i++) cin>>s[i];
    for(int i=0;i<4;i++){
        for(int j=0;j<s[i];j++){//j++!
            cin>>practice[i][j];
        }
    }
}

void solve(){
    for(int i=0;i<4;i++){
        dfs(0,0,0,i);
        cnt_time+=min_time;
        min_time=MAXN;
    }
}
void output(){
    cout<<cnt_time<<endl;
}

int main(){

    input();
    solve();
    output();

    return 0;
}