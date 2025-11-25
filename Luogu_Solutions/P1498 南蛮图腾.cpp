#include<bits/stdc++.h>
using namespace std;
int n;
char ch[3000][3000],storage[3000][3000];//01Index
int main(){//尺度:2^n*2^(n+1)
	cin>>n;
	ch[1][2]='/',ch[1][3]='\\',ch[2][1]='/',ch[2][2]='_',ch[2][3]='_',ch[2][4]='\\';
	for(int i=1;i<n;i++){//下移，左移，上移
		for(int j=1;j<=(int)pow(2,i);j++){
			for(int k=1;k<=(int)pow(2,i+1);k++){
				storage[j][k]=ch[j][k];
				ch[j][k]=0;
			}
		}
		for(int j=1;j<=(int)pow(2,i);j++){
			for(int k=1;k<=(int)pow(2,i+1);k++){
				ch[j+(int)pow(2,i)][k]=storage[j][k];
				ch[j+(int)pow(2,i)][k+(int)pow(2,i+1)]=storage[j][k];
				ch[j][k+(int)pow(2,i)]=storage[j][k];//不能直接赋值！会影响原图形一半之后的图案
			}
		}
	}
	for(int i=1;i<=(int)pow(2,n);i++){
		for(int j=1;j<=(int)pow(2,n+1);j++){
			if(ch[i][j])cout<<ch[i][j];
			else cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}