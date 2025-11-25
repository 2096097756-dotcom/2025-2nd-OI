#include<bits/stdc++.h>
using namespace std;
int n;
void print(int n){
	int num=n,cnt=log(n)/log(2);
	if(n==1) return ;
	if(n==2){
		cout<<"2";
		return ;
	}
	while(n){
		if(n>=pow(2,cnt)){
			if(cnt==1){
				cout<<2;
				if(n==pow(2,cnt)) return ;
				else cout<<"+";
			}
			else{
				cout<<"2(";
				if(cnt==0) cout<<"0)";
				else{
					if(n==pow(2,cnt)){
						print(cnt);
						cout<<")";
					}else{
						print(cnt);
						cout<<")+";
					}
				}
			} 
			n-=pow(2,cnt);
		}
		cnt--;
	}
}
int main(){
	cin>>n;
	print(n);
	return 0;
}