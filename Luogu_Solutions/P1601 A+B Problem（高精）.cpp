#include<bits/stdc++.h>
using namespace std;
int pls1[500],pls2[500],sum[501],flo;
void num(string str,int a[]){
    for(int i=0;i<str.length();i++){
        int s=str.length()-i-1;
        a[i]=str[s]-'0';
    }
}
int main(){
    string str1,str2,ans;
    cin>>str1>>str2;
    num(str1,pls1);
    num(str2,pls2);
    int maxm=max(str1.length(),str2.length());
    for(int i=0;i<maxm;i++){
        sum[i]=pls1[i]+pls2[i]+flo;
        flo=sum[i]/10;
        sum[i]%=10;
    }
    sum[maxm]=flo;
    if(flo==0){
        for(int i=0;i<maxm;i++){
            cout<<sum[maxm-i-1];
        }
    }else{
        for(int i=0;i<maxm+1;i++){
            cout<<sum[maxm-i];
        }
    }
    return 0;
}