//Luogu_P2895
#include<bits/stdc++.h>
using namespace std;
const int MAXN=310;
const int MAXNN=1e6+1;

int m;
int farm[MAXN][MAXN],dist[MAXN][MAXN],accessible[MAXN][MAXN];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};

struct STAR{
    int x;
    int y;
    int t;
}star[MAXNN];

bool if_legal(int x,int y){
    if(x>=0&&y>=0) return 1;//注意这里人可能会走到外面,不需要上界限制
    return 0;
}

int bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});

    if(accessible[0][0]==-1) return 0;
    if(accessible[0][0]==0) return -1;//端点特殊判断!

    dist[0][0]=0;
    
    while(!q.empty()){
        pair<int,int> current=q.front();
        q.pop();
        int time=dist[current.first][current.second]+1;

        for(int i=1;i<5;i++){
            int x_now=current.first+dx[i];
            int y_now=current.second+dy[i];

            if(if_legal(x_now,y_now)){
                if(accessible[x_now][y_now]>time&&dist[x_now][y_now]==-1&&accessible[x_now][y_now]>=0){
                    dist[x_now][y_now]=time;
                    q.push({x_now,y_now});
                }
                else if(accessible[x_now][y_now]==-1&&dist[x_now][y_now]==-1) return time;
            }
        }
    }  

    return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dist,-1,sizeof(dist));
    memset(accessible,-1,sizeof(accessible));

    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>star[i].x>>star[i].y>>star[i].t;
        for(int j=0;j<5;j++){
            if(if_legal(star[i].x+dx[j],star[i].y+dy[j])){
                accessible[star[i].x+dx[j]][star[i].y+dy[j]]=(accessible[star[i].x+dx[j]][star[i].y+dy[j]]==-1)?star[i].t:min(star[i].t,accessible[star[i].x+dx[j]][star[i].y+dy[j]]);//注意star[i].t
            }
        }
    }

    int final_time=bfs();
    cout<<final_time<<endl;

    return 0;

}