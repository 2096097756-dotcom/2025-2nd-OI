#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,num=1,a[100];
	cin>>n;
	for(int i=1;i<=n;i++){
		num*=i;
		a[i]=i;
	}
	for(int i=1;i<=num;i++){
		for(int j=1;j<=n;j++){
			cout<<"    "<<a[j];
		}
		cout<<endl;
		next_permutation(a+1,a+n+1);
	}
	return 0;
}
