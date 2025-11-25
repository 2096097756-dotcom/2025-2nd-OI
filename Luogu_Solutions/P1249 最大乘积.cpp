#include<bits/stdc++.h>
using namespace std;
int num[1000];
int ans[5100]={0,1};
int highestzero;
void gjd(int m){
	highestzero=5000;
	while(ans[highestzero]==0){
		highestzero--;
	}
	for(int i=1;i<=highestzero+10;i++){
		ans[i]*=m;
		ans[i]+=ans[i-1]/10;
		ans[i-1]%=10;
	}
}
int main(){
	int n;
	cin>>n;
	if(n==3){
		cout<<3<<endl<<3<<endl;
		return 0;
	}else if(n==4){
		cout<<4<<endl<<4<<endl;
		return 0;
	}else{
		bool flag=0;
		long long cnt=2,sum=0,timess=1;
		for(int i=2;;i++){
			num[cnt]=i;
			cnt++;
			sum+=i;
			if(sum>=n&&flag==0){
				flag=1;
				break;
			}
		}//一共有cnt个数
		int del=sum-n;
		if(del==1){
			num[2]=0;
			num[cnt-1]++;
			for(int i=3;i<cnt;i++){
				cout<<num[i]<<' ';
				gjd(num[i]);
			}
		}else if(del==0){
			for(int i=2;i<cnt;i++){
				cout<<i<<' ';
				gjd(i);
			}
		}else{
			num[del]=0;
			for(int i=2;i<cnt;i++){
				if(i==del){
					continue;
				}
				cout<<i<<' ';
				gjd(i);
			}
		}
	}
	cout<<endl;
	highestzero=5000;
	while(highestzero>0&&ans[highestzero]==0){
		highestzero--;
	}
	for(int i=highestzero;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
