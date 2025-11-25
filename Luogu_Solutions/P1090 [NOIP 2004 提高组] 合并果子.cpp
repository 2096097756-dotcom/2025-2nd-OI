#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int main(){
	priority_queue<int,vector<int>,greater<int>> minHeap;//优先队列
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		minHeap.push(a);
	}
	while(minHeap.size()>1){
		int firstmin=minHeap.top();
		minHeap.pop();
		int secondmin=minHeap.top();
		minHeap.pop();
		int cost=firstmin+secondmin;
		cnt+=cost;
		minHeap.push(cost);
	}
	cout<<cnt;
}