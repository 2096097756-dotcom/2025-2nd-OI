#include<bits/stdc++.h>
using namespace std;
int mutipy[20001],cnt;
string expand(){
	int times;
	char imp;
	string ans="",str="";
	while(cin>>imp){
		if(imp=='['){
			cin>>times;
			str=expand();
			while(times--){
				ans+=str;
			}
		}
		else if(imp==']'){
			return ans;
		}else{
			ans+=imp;	
		}
	}
	return ans;
}
int main(){
	cout<<expand();//即时处理！
	return 0;
}