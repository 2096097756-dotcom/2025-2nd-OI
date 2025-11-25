#include<bits/stdc++.h>
using namespace std;
int division(int left,int right,vector<int> &num,int k){
	int new_left=left,new_right=right,middle=(right+left)/2,now=left;
	if(left==right){
		return num[middle];//边界条件判断，指代同一个，减少计算量
	}
	int pivot=num[middle];//实际上可以任意选择
	//从最左边开始遍历
	while(now<=new_right){//new_right是前面一位，保证遍历完全应当为等号
		if(num[now]<pivot){//锚定点一定要定！num[middle]会变化
			swap(num[now],num[new_left]);
			now++;//这时候now左边的数码全部小于等于num[middle](锚定值)
			new_left++;
		}else if(num[now]>pivot){
			swap(num[now],num[new_right]);
			new_right--;
			//这里不能让now++，因为不能确保num[new_right]的大小
		}else{
			now++;
		}
	}
	//这个时候，被分成了[left,new_left-1],[new_left,new_right],[new_right+1,right]
	if(k>new_right){
		return division(new_right+1,right,num,k);
	}else if(k<new_left){
		return division(left,new_left-1,num,k);
	}else{
		return num[k];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int result=division(0,n-1,num,k);
	cout<<result<<endl;
	return 0; 
}
