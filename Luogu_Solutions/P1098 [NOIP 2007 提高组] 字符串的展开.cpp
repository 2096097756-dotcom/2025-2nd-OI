#include<bits/stdc++.h>
using namespace std;
int main(){
	int p1,p2,p3;
	string str,ans,store;
	cin>>p1>>p2>>p3>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]=='-'){
			if(str[i-1]>=str[i+1]||str[i-1]>'z'||(str[i-1]<'a'&&str[i-1]>'9')||str[i-1]<'0'||str[i+1]>'z'||(str[i+1]<'a'&&str[i+1]>'9')||str[i+1]<'0'||abs(str[i-1]-str[i+1])>='a'-'9'){//注意不要写成str[i],以及对于两边不同类型的检查
				cout<<ans<<'-';
				ans="";
				store="";
			}else{
				for(int j=str[i-1]+1;j<=str[i+1]-1;j++){
					for(int k=0;k<p2;k++){
						char ch=j;
						store+=ch;
					}
				}
				if(p1==1&&str[i-1]>='a'){
				}else if(p1==2&&str[i-1]>='a'){
					for(int j=0;j<store.length();j++){
						store[j]=toupper(store[j]);
					}
				}else if(p1==3){
					for(int j=0;j<store.length();j++){
						store[j]='*';
					}
				}
				if(p3==1){
				}else if(p3==2){
					reverse(store.begin(),store.end());
				}
				cout<<ans<<store;
				ans="";
				store="";
			}
		}else{
			ans+=str[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
