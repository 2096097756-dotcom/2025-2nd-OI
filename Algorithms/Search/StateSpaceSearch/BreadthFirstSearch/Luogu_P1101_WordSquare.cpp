#include<bits/stdc++.h>
using namespace std;
const int MAXN =1001;

int n;
char ch[MAXN][MAXN];
int dist[MAXN][MAXN];
char word[7]={'y','i','z','h','o','n','g'};
int dx[8]={-1,-1,-1,1,1,1,0,0};
int dy[8]={1,-1,0,1,-1,0,-1,1};

bool legal(int x,int y){
    if(x<=n&&x>=1&&y<=n&&y>=1) return 1;
    return 0;
}

int find(char c){
    for(int i=0;i<7;i++){
        if(word[i]==c) return i;
    }
    return -1;
}

vector<pair<int,int>> path;

void dfs(int x,int y,int level,int dir){
    if(!legal(x,y)) return ;
    if(ch[x][y]!=word[level]) return ;
    if(level==6){
        int x_now=x;
        int y_now=y;
        for(int i=0;i<=6;i++){
            dist[x_now][y_now]=1;
            x_now-=dx[dir];
            y_now-=dy[dir];
        }
        return ;
    }

    dfs(x+dx[dir],y+dy[dir],level+1,dir);
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ch[i][j];//用cin就可以，会跳过换行符
        }
    }
    memset(dist,0,sizeof(dist));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ch[i][j]=='y'){
                
                for(int k=0;k<8;k++){
                    dfs(i,j,0,k);
                }
            }
        }
    }//这里只要标记走过的就可以了!其余全部打上*

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!dist[i][j]) cout<<'*';
            else cout<<ch[i][j];
        }
        cout<<endl;
    }
    return 0;

}