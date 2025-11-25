#include<bits/stdc++.h>
using namespace std;
int n,last=0,now,cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>now;
		if(now>last){
			cnt+=now-last;
		}
		last=now;
	}
	cout<<cnt<<endl;
}
/*
模拟方法：
#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int n,road[N],CNT,cnt;
bool flag[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>road[i];
		if(road[i]==0)CNT++;
	}
	while(CNT<n){
		int new_zero=n+1,last_zero=0;
		for(int i=1;i<=n;i++){
			if(road[i]==0){
				last_zero=new_zero;
				new_zero=i;
				if(last_zero==n+1){
					last_zero=0;
				}
				if(last_zero+1<=new_zero-1){
					int minm=N;
					for(int j=last_zero+1;j<=new_zero-1;j++)minm=min(minm,road[j]);
					//cout<<minm<<endl;
					for(int j=last_zero+1;j<=new_zero-1;j++){
						road[j]-=minm;
					}
					cnt+=minm;
				}
			}
		}
		if(new_zero!=n+1){
			last_zero=new_zero;
			new_zero=n+1;
		}
		if(last_zero+1<=new_zero-1){
			int minm=N;
			for(int i=last_zero+1;i<=new_zero-1;i++)minm=min(minm,road[i]);
			for(int i=last_zero+1;i<=new_zero-1;i++){
				road[i]-=minm;
			}
			//cout<<minm<<endl;
			cnt+=minm;
		}
		CNT=0;
		for(int i=1;i<=n;i++){
			if(road[i]==0){
				CNT++;
			}
		}
	}
	cout<<cnt<<endl;
}*/