#include<bits/stdc++.h>
using namespace std;
int findnum(int m,int cnt){
	int num[5101];
	memset(num,0,sizeof(num));
	num[1]=1;
	for(int i=2;i<=m;i++){
		int highestzero=5000;
		while(num[highestzero]==0){
			highestzero--;
		}
		for(int j=1;j<=highestzero+100;j++){
			num[j]*=i;
			num[j]+=num[j-1]/10;
			num[j-1]%=10;//*+%/
		}
	}
	int highestzero=5000;
		while(num[highestzero]==0){//等于零才往下减
			highestzero--;
	}
	int cnt_number=0;
	for(int i=1;i<=highestzero;i++){
		if(num[i]==cnt){
			cnt_number++;
		}
	}
	return cnt_number;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int m,cnt;
		cin>>m>>cnt;
		cout<<findnum(m,cnt)<<endl;
	}
}
