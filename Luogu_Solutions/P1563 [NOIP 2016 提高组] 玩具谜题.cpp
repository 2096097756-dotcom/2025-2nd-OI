#include<bits/stdc++.h>
using namespace std;
struct People{
	int dir;
	string name;
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<People> toy(n);
	for(int i=0;i<n;i++){
		cin>>toy[i].dir>>toy[i].name;
	}
	int pos_now=0;
	for(int i=0;i<m;i++){
		int way,num;
		cin>>way>>num;
		if(way+toy[pos_now].dir==1){
			pos_now+=num;
		}else{
			pos_now-=num;
		}
		if(pos_now<0){
			pos_now+=n;
		}else if(pos_now>=n){
			pos_now-=n;
		}
	}
	cout<<toy[pos_now].name<<endl;
}