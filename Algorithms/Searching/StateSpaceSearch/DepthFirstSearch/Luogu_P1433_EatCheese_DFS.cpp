#include<bits/stdc++.h>
using namespace std;
const int MAXN=30;
const int MAXNN=1e6+10;
const int MAXNNN=1<<16;

struct Cheese{
    double x,y;
}cheese[MAXN];

int n;
double cheese_distance[MAXN][MAXN];
double min_distance=MAXNN;
bool if_visit[MAXN];

/*
第三次修改,2025.12.04,22:30
*/

double mem[MAXNNN][MAXN];

struct Node{
    int id_cheese;
    double dist;
};

bool cmp(const Node &a, const Node &b){//加上 const 和 & 是好习惯
    return a.dist<b.dist;
}


void dfs(int level,double now_distance,int nowpos,int mask){//区间状态压缩!mask应当是一个二进制数
    if(now_distance>min_distance) return ;

    if(mem[mask][nowpos]!=0&&mem[mask][nowpos]<=now_distance){
        return ;
    }//之前走过的路与现在的状态?

    if(level==n){
        min_distance=min(min_distance,now_distance);
    }
    int cnt=0,to_visit[MAXN];//cnt可能不会初始化
    
    vector<Node> candidates;
    for(int i=1;i<=n;i++){
        if(!if_visit[i]) candidates.push_back({i,cheese_distance[nowpos][i]});//向后推入
    }

    mem[mask][nowpos]=now_distance;

    sort(candidates.begin(),candidates.end(),cmp);

    for(int i=0;i<candidates.size();i++){
        int next_node=candidates[i].id_cheese;
        double cost=candidates[i].dist;

        if_visit[next_node]=1;
        dfs(level+1,now_distance+cost,next_node,mask|(1<<(next_node-1)));//注意，这一步+下一步距离
        //本质上是一系列状态机:10001.....，1：第一块奶酪被吃了...
        //|:状态的叠加，按位或
        //next_node为1，那么存放在第0位,n/n-1位，以此类推!
        if_visit[next_node]=0;

    }

    return ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cheese_distance[0][0]=0.0;
    memset(if_visit,0,sizeof(if_visit));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>cheese[i].x>>cheese[i].y;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cheese_distance[i][j]=sqrt(pow((cheese[i].x-cheese[j].x),2)+pow(cheese[i].y-cheese[j].y,2));
        }
    }

    dfs(0,0.0,0,0);
    printf("%.2f\n",min_distance,0);
    return 0;
}
/*
1.优化:ans特判
2.优化:动态数组贪心优化
*/