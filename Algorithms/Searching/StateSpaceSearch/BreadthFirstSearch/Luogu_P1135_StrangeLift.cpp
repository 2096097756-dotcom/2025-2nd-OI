//Luogu P1135 StrangeLift

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+1;

int N,A,B;
int lift[MAXN],dist[MAXN];

void bfs(){

    int cnt=0;
    queue<int> q;
    dist[A]=0;
    q.push(A);
    while(!q.empty()){
        int t=q.front();
        if(t==B) return ;
        q.pop();
        if((t-lift[t])>0&&dist[t-lift[t]]==-1){
            q.push(t-lift[t]);
            dist[t-lift[t]]=dist[t]+1;
        }
        if((t+lift[t])<=N&&dist[t+lift[t]]==-1){
            q.push(t+lift[t]);
            dist[t+lift[t]]=dist[t]+1;//注脚:当前层+1
        }
    }
    return ;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dist,-1,sizeof(dist));
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++){
        cin>>lift[i];
    }
    
    bfs();

    cout<<dist[B];
    return 0;
}