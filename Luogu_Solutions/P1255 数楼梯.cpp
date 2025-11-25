#include<bits/stdc++.h>
using namespace std;
string dp[10001]={"1","1"};
string highresplus(string num1,string num2){
	string res="";
	int carry=0;
	int pos1=num1.length()-1;
	int pos2=num2.length()-1;//最后一位，highestzero
	while(pos1>=0||pos2>=0||carry){//进位不为0也要执行
		int sum=carry;
		if(pos1>=0){
			sum+=num1[pos1]-'0';
			pos1--;
		}
		if(pos2>=0){
			sum+=num2[pos2]-'0';
			pos2--;//位数，即使超出了也无所谓，不执行，只加上最大的
		}
		res.push_back((sum%10)+'0');
		carry=sum/10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string stairs(int n){
	if(n<0){
		return "0";
	}if(!dp[n].empty()){
		return dp[n];
	}
	dp[n]=highresplus(stairs(n-1),stairs(n-2));
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	string ans=stairs(n);
	cout<<ans<<endl;
	return 0;
}