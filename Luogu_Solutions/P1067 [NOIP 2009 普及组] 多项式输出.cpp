#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	bool flag=0;
	cin>>n;
	for(int i=n;i>=0;i--){
		int num;
		cin>>num;
		if(num==0){
			continue;
		}else if(num==1&&flag==1&&i!=0){
			cout<<"+";
			flag=1;
		}else if(num==1&&flag==1&&i==0){
			cout<<"+1";
			flag=1;
		}else if(num==1&&flag==0&&i==0){
			cout<<"1";
		}else if(num==1&&flag==0){
			flag=1;
		}else if(num==-1&&i!=0){
			cout<<"-";
			flag=1;
		}else if(num==-1&&i==0){
			cout<<"-1";
			flag=1;
		}else if(num>0&&flag==0){
			cout<<num;
			flag=1;
		}else if(num>0&&flag==1){
            cout<<"+"<<num;
            flag=1;
        }else if(num<0){
			cout<<"-"<<-num;
			flag=1;
		}
        if(i!=0){
            cout<<"x^"<<i;
        }else{
            continue;
        }
	}
	return 0;
}
