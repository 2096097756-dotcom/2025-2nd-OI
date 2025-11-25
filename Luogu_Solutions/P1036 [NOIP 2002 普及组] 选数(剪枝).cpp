#include<bits/stdc++.h>
using namespace std;
int n,k,a[21];
bool ifprime(int n){
	if(n==1) return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int dfs(int num,int k,int total){
	if(n-num<k) return 0;
	int res=0;
	if(k==0&&total){
		if(ifprime(total)) return 1;
		else return 0;
	}
	if(num>=n) return 0;
	for(int i=num;i<=n-k;i++){
		res+=dfs(i+1,k-1,total+a[i]);
	}
	return res;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,k,0)<<endl;
	return 0;
}