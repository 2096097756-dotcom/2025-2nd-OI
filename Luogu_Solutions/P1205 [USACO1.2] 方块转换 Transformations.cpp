#include<bits/stdc++.h>
using namespace std;
int n;
int c[100][100];
bool pd(int a1[100][100],int b1[100][100]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a1[i][j]!=b1[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
bool changeset3(int a2[100][100],int b2[100][100]){
	int c3[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c3[n-1-j][i]=a2[i][j];
		}
	}
	return pd(c3,b2);
}
bool changeset2(int a2[100][100],int b2[100][100]){
	int c2[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c2[n-1-i][n-1-j]=a2[i][j];
		}
	}
	return pd(c2,b2);
}
bool changeset1(int a2[100][100],int b2[100][100]){
	int c1[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c1[j][n-1-i]=a2[i][j];
		}
	}
	return pd(c1,b2);
}
bool changeset4(int a2[100][100],int b2[100][100]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i][n-1-j]=a2[i][j];
		}
	}
	return pd(c,b2);
}
bool changeset5(int a2[100][100],int b2[100][100]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i][n-1-j]=a2[i][j];
		}
	}
	if((changeset1(c,b2)||changeset2(c,b2))||changeset3(c,b2)){
		return 1;
	}else{
		return 0;
	}
}
bool changeset6(int a2[100][100],int b2[100][100]){
	return pd(a2,b2);
}
int main(){
	int a[100][100],b[100][100];
	string str;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str;
		for(int j=0;j<n;j++){
			if(str[j]=='@'){
				a[i][j]=1;
			}else{
				a[i][j]=2;
			}
		}
	}
	for(int i=0;i<n;i++){
		cin>>str;
		for(int j=0;j<n;j++){
			if(str[j]=='@'){
				b[i][j]=1;
			}else{
				b[i][j]=2;
			}
		}
	}
	if(changeset1(a,b))cout<<1<<endl;
	else if(changeset2(a,b))cout<<2<<endl;
	else if(changeset3(a,b))cout<<3<<endl;
	else if(changeset4(a,b))cout<<4<<endl;
	else if(changeset5(a,b))cout<<5<<endl;
	else if(changeset6(a,b))cout<<6<<endl;
	else cout<<7<<endl;
}