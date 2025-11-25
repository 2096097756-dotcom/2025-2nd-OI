#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt=1,n;
	cin>>n;
	long long a=0,b=1;
	//a=0,b=1,c=
	a=(a+b)%n;
	swap(a,b);
	while(a!=0||b!=1){
		cnt++;
		long long c=(a+b)%n;
		swap(a,b);
		swap(b,c);
	}
	cout<<cnt<<endl;
	return 0;
}
