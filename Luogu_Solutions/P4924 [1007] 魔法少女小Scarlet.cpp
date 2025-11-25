#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> matrix;
void turn(int x,int y,int r,int z){
	int x_min=x-r-1;
	int x_max=x+r-1;
	int y_min=y-r-1;
	int y_max=y+r-1;
	int size=2*r+1;
	vector<vector<int>> store(size,vector<int>(size));
	vector<vector<int>> rotated(size,vector<int>(size));
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			store[i][j]=matrix[i+x_min][j+y_min];
		}
	}
	if(z==1){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				rotated[i][j]=store[j][size-i-1];
			}
		}
	}
	else if(z==0){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				rotated[i][j]=store[size-j-1][i];
			}
		}	
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matrix[i+x_min][j+y_min]=rotated[i][j];
		}
	}
}
int main(){
	cin>>n>>m;
	matrix.resize(n,vector<int>(n));
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			count++;
			matrix[i][j]=count;
		}
	}
	for(int i=0;i<m;i++){
		int x,y,r,z;
		cin>>x>>y>>r>>z;
		turn(x,y,r,z);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
/*
旋转公式：0~n-1标准方阵
[i][j]=[j][n-1-i](逆时针)
[i][j]~[n-1-j][i](顺时针)
先调换i,j位置
*/
