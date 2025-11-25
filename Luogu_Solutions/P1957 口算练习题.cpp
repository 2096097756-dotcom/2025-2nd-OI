#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	char ch_now=0,ch_last=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		getline(cin,str);
		int a,b;
		stringstream ss(str);
		string token,parts[3];
		int count=0;
		while(ss>>token){
			parts[count]=token;
			count++;
		}
		if(count==2){
			ch_now=ch_last;
			a=stoi(parts[0]);
			b=stoi(parts[1]);
		}
		if(count==3){
			ch_now=parts[0][0];
			a=stoi(parts[1]);
			b=stoi(parts[2]);
		}
		string output;
		if(ch_now=='a'){
			output=to_string(a)+'+'+to_string(b)+'='+to_string(a+b);
			cout<<output<<endl<<output.length()<<endl;
		}
		if(ch_now=='b'){
			output=to_string(a)+'-'+to_string(b)+'='+to_string(a-b);
			cout<<output<<endl<<output.length()<<endl;
		}
		if(ch_now=='c'){
			output=to_string(a)+'*'+to_string(b)+'='+to_string(a*b);
			cout<<output<<endl<<output.length()<<endl;
		}
		ch_last=ch_now;
	}
	return 0;	
}