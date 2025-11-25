#include<bits/stdc++.h>
using namespace std;
int n,room;
double total;
struct BAG{
	double value;
	int mass;
}bag[5005];
bool cmp(BAG a,BAG b){
	if(a.value!=b.value){
		return a.value>b.value;
	}
	return a.mass>b.mass;
}
int main(){
	cin>>n>>room;
	for(int i=0;i<n;i++){
		double m,v;
		cin>>m>>v;
		bag[i].value=v/m;
		bag[i].mass=m;
	}
	sort(bag,bag+n,cmp);
	for(int i=0;i<n;i++){
		cout<<bag[i].value<<' '<<bag[i].mass<<endl;
	}//从大到小，sort默认从小到大
	int cnt=0;
	while(room>0&&cnt<n){//两边夹，上面和下面，对于每一个自增、减的变量进行考察
		if(room>=bag[cnt].mass){
			total+=bag[cnt].value*bag[cnt].mass;
			room-=bag[cnt].mass;
		}else{
			total+=room*bag[cnt].value;
			room=0;
			break;
		}
		cnt++;
	}
	printf("%.2f\n",total);
	return 0;
}