#include<bits/stdc++.h>
using namespace std;
int a[3001],b[3001],ans[6002];
int main(){
	string str1,str2,answ;
	cin>>str1>>str2;
	int len1=str1.length(),len2=str2.length();
	for(int i=0;i<len1;i++){
		a[i]=str1[len1-i-1]-'0';
	}
	for(int i=0;i<len2;i++){
		b[i]=str2[len2-i-1]-'0';
	}
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			ans[i+j]+=a[i]*b[j];
			ans[i+j+1]+=ans[i+j]/10;
			ans[i+j]%=10;
		}
	}
	int f0=len1+len2;
	while(f0>0&&ans[f0]==0){
		f0--;//f0至少1位
	}
	for(int i=f0;i>=0;i--){
		cout<<ans[i];
    }
	return 0;
}