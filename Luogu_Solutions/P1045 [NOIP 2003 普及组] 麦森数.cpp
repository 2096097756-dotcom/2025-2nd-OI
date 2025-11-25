#include<bits/stdc++.h>
using namespace std;
int ans[1011]={0,1};//501~510;500λ
int a[1011]={0,2};
void mutipy1(){
	int temp[1011]={0};
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			temp[i+j-1]+=ans[i]*a[j];
		}
	}
	int t=0;
	for(int i=1;i<=500;i++){
		temp[i]+=t;
		t=temp[i]/10;
		ans[i]=temp[i]%10;
	}
}
void mutipy2(){
	int temp[1011]={0};
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			temp[i+j-1]+=a[i]*a[j];
		}
	}
	int t=0;
	for(int i=1;i<=500;i++){
		temp[i]+=t;
		t=temp[i]/10;
		a[i]=temp[i]%10;
	}
}
void quickpow(int n){
	while(n!=0){
		if(n%2==1){
			mutipy1();
		}
		mutipy2();
		n/=2; 
	}
}
int main(){
	int n;
	cin>>n;
	int num=n*log10(2)+1;
	cout<<num<<endl;
	quickpow(n);
	ans[1]--;
	for(int i=500;i>=1;i--){
		cout<<ans[i];
		if((i-1)%50==0){
			cout<<endl;
		}
	}
	return 0;
}
