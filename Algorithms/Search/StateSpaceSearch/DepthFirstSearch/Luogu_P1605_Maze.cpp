#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
const int MAXNN=1e7+1;
const int MAZE_MAXN=20;

int N,M,T;
int SX,SY,FX,FY;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct BARRIER{
    int x,y;
}mazeBarrier[MAXN];
int cnt=0;
bool if_visit[MAZE_MAXN][MAZE_MAXN];

bool legal(int x,int y){

    if(x<=0||y<=0||x>N||y>M) return 0;
    for(int i=1;i<=T;i++){
        if(x==mazeBarrier[i].x&&y==mazeBarrier[i].y) return 0;
    }
    if(if_visit[x][y]) return 0;
    return 1; 

}

void input(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>T;
    cin>>SX>>SY>>FX>>FY;
    for(int i=1;i<=T;i++) cin>>mazeBarrier[i].x>>mazeBarrier[i].y;

}

void dfs(int x_now,int y_now){
   if(x_now==FX&&y_now==FY){
        cnt++;
        return ;
   }

   for(int i=0;i<4;i++){
        int x_new=x_now+dx[i];
        int y_new=y_now+dy[i];
        if(legal(x_new,y_new)){
            if_visit[x_new][y_new]=1;
            dfs(x_new,y_new);
            if_visit[x_new][y_new]=0;
        }
   }

   return ;
}

void solve(){
    dfs(SX,SY);
}

int main(){

    input();
    solve();
    cout<<cnt<<endl;

    return 0;
}