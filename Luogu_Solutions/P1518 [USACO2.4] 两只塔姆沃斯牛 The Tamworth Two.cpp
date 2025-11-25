#include<bits/stdc++.h>
using namespace std;
int F_x,F_y,C_x,C_y,cnt;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int F_dir=0,C_dir=0;
int main(){
	char map[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>map[i][j];
			if(map[i][j]=='F'){
				F_x=i;
				F_y=j;
			}
			if(map[i][j]=='C'){
				C_x=i;
				C_y=j;
			}
		}
	}
	//命题：相遇时跳出循环:F_x==C_x&&F_y==C_y
	//否定命题:F_x!=C_x||F_y!=C_y
	while(F_x!=C_x||F_y!=C_y){
		cnt++;
		int posFx=F_x+dir[F_dir][0],posFy=F_y+dir[F_dir][1];
		int posCx=C_x+dir[C_dir][0],posCy=C_y+dir[C_dir][1];
		if(posFx<0||posFx>=10||posFy<0||posFy>=10||map[posFx][posFy]=='*'){
			F_dir++;
			if(F_dir>=4){
				F_dir-=4;
			}
		}else{
			F_x=posFx;
			F_y=posFy;
		}
		if(posCx<0||posCx>=10||posCy<0||posCy>=10||map[posCx][posCy]=='*'){
			C_dir++;
			if(C_dir>=4){
				C_dir-=4;
			}
		}else{
			C_x=posCx;
			C_y=posCy;
		}
		if(cnt>10000){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
