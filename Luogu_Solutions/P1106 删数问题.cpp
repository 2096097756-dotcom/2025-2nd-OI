#include<bits/stdc++.h>
using namespace std;
string str;
int n;
int main(){
	cin>>str>>n;
	while(n){
		int i;
		for(i=0;str[i]<=str[i+1];){
			i++;
		}
		str.erase(i,1);//从第i个位置开始连续删除一个
		n--;
	}
	while(str[0]=='0'&&str.length()>1){
		str.erase(0,1);
	}
	cout<<str;
	return 0;
}//删除掉最高峰==保留最低峰