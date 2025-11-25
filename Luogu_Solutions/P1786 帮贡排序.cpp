#include<bits/stdc++.h>
using namespace std;
struct man{
	string name;
	string pos;
	int banggong;
	int level;
	int pos_start;
}Man[110],Sort[110];
string LEVEL[7]={"BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong"};
int cnt=1;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Man[i].name>>Man[i].pos>>Man[i].banggong>>Man[i].level;
		if(Man[i].pos=="BangZhu"){
			Sort[0]=Man[i];
			continue;
		}
		if(Man[i].pos=="FuBangZhu"){
			Sort[cnt]=Man[i];
			cnt++;
			continue;
		}
		Man[i].pos_start=i;
	}
    /*
    for(int i=0;i<3;i++){
        cout<<Sort[i].name<<' '<<Sort[i].pos<<' '<<Sort[i].level<<endl;
    }
    cout<<endl;
    */
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Man[j].banggong<Man[j+1].banggong){
				swap(Man[j],Man[j+1]);
			}
		}
	}
	int cnt1=3;
	for(int i=0;i<n;i++){
		if(Man[i].pos==LEVEL[0]||Man[i].pos==LEVEL[1]){
			continue;
		}
		Sort[cnt1]=Man[i];
		cnt1++;
	}
	for(int i=3;i<n;i++){
		int k=i-2;
		if(k>=1&&k<=2){
			Sort[i].pos=LEVEL[2];
		}else if(k>=3&&k<=6){
			Sort[i].pos=LEVEL[3];
		}else if(k>=7&&k<=13){
			Sort[i].pos=LEVEL[4];
		}else if(k>=14&&k<=38){
			Sort[i].pos=LEVEL[5];
		}else{
			Sort[i].pos=LEVEL[6];
		}
	}
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Sort[j].pos==Sort[j+1].pos&&Sort[j].level<Sort[j+1].level){
				swap(Sort[j],Sort[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Sort[j].pos==Sort[j+1].pos&&Sort[j].level==Sort[j+1].level&&Sort[j].pos_start>Sort[j+1].pos_start){
				swap(Sort[j],Sort[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<Sort[i].name<<' '<<Sort[i].pos<<' '<<Sort[i].level<<endl;
	}
	return 0;
}
