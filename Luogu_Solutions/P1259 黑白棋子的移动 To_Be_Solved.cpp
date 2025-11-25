#include<bits/stdc++.h>
using namespace std;
int n,a[200];
void print(){
	for(int i=0;i<2*n+2;i++){
		if(a[i]==0) cout<<'o';
		else if(a[i]==1) cout<<'*';
		else cout<<'-';
	}
	cout<<endl;
}
void print_(){
	for(int i=0;i<2*n+2;i++){
		if(a[i]==0) cout<<'o';
		else if(a[i]==1) cout<<'*';
		else cout<<'-';
	}
}
void doubleswap(int pos1,int pos2){
	swap(a[pos1],a[pos2]);
	swap(a[pos1+1],a[pos2+1]);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		a[i]=0;
		a[n+i]=1;
	}
	a[2*n]=a[2*n+1]=2;
	print();
	for(int Index=n;Index>=4;Index--){//6,14
		doubleswap(Index-1,2*Index);print();
		if(Index==4)break;
		doubleswap(Index-1,2*Index-2);print();
	}
	doubleswap(3,7);print();
	doubleswap(1,7);print();
	doubleswap(1,6);print();
	doubleswap(0,6);print_();
}