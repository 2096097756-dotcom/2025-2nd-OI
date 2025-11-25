#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100][20];
int dfs(int step,int num){
	int total=0;
	if(step==2*n){
		if(num==0){
			return 1;
		}//清空栈
		else{
			return 0;
		}
	}
	if(dp[step][num]){
		return dp[step][num];
	}
	if(num<=n){
		total+=dfs(step+1,num+1);
	}
	if(num>0){
		total+=dfs(step+1,num-1);//只与push，pop的顺序有关，和具体的数字无关
	}
	dp[step][num]=total;
	return total;
}
int main(){
	 cin>>n;
	 cout<<dfs(0,0);
	 return 0;
}