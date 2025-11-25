#include<bits/stdc++.h>
using namespace std;
long long dp[30][30];
bool visit[30][30];
int x,y,mx,my;
long long dfs(int x,int y){
	if(x<0||y<0){
		return 0;
	}
	if(visit[x][y]==0){
		return 0;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];//dp用来存储结果，避免重复运算
	}
	if(x==0&&y==0){
		return 1;
	}
	return dp[x][y]=dfs(x-1,y)+dfs(x,y-1);	
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin>>x>>y>>mx>>my;
	for(int i=0;i<=x;i++){
		for(int j=0;j<=y;j++){
			if((i==mx&&j==my)||(i==mx+2&&j==my+1)||(i==mx+1&&j==my+2)||(i==mx-1&&j==my+2)||(i==mx-2&&j==my+1)||(i==mx-1&&j==my-2)||(i==mx-2&&j==my-1)||(i==mx+1&&j==my-2)||(i==mx+2&&j==my-1)){
				visit[i][j]=0;
			}
			else{
				visit[i][j]=1;
			}
		}
	}
	cout<<dfs(x,y)<<endl;
} 