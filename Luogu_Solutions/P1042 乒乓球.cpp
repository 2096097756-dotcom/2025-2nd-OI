#include<bits/stdc++.h>
using namespace std;
int main(){
	string str[3000];
	int count=0;
	while(cin>>str[count]){
		for(int i=0;i<str[count].length();i++){
            if(str[0][0]=='E'){
        		cout<<"0:0"<<endl<<endl<<"0:0"<<endl;
                return 0;
        	}
			if(str[count][i]=='E'){
				str[count].erase(i);
				break;
			}
		}
		count++;
	}//0~count
	int W=0,L=0;
	for(int i=0;i<=count;i++){
		for(int j=0;j<str[i].length();j++){
			if(str[i][j]=='L'){
				L++;
			}else if(str[i][j]=='W'){
				W++;
			}
			if(max(L,W)>=11&&abs(L-W)>=2){
				cout<<W<<":"<<L<<endl;
				L=0;
				W=0;
			}
		}
	}
	cout<<W<<":"<<L<<endl;
	L=0;
	W=0;
	cout<<endl;
	for(int i=0;i<count;i++){
		for(int j=0;j<str[i].length();j++){
			if(str[i][j]=='L'){
				L++;
			}else if(str[i][j]=='W'){
				W++;
			}
			if(max(L,W)>=21&&abs(L-W)>=2){
				cout<<W<<":"<<L<<endl;
				L=0;
				W=0;
			}
		}
	}
	cout<<W<<":"<<L<<endl;
	return 0;
}