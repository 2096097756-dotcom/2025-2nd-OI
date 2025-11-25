/**
#include<bits/stdc++.h>
using namespace std;
int num[2000],ans[2000],highestzero;

void times(int m){
    memset(num,0,sizeof(num));
    num[1]=1;
    for(int j=2;j<=m;j++){
        highestzero=1998;
        while(num[highestzero]==0&&highestzero>1){
            highestzero--;
        }
        for(int k=1;k<=highestzero+10;k++){
            num[k]*=j;
        }
        for(int k=1;k<=highestzero+10;k++){
            num[k+1]+=num[k]/10;
            num[k]%=10;
        }
    }
}
void pluss(){
    highestzero=1998;
    while(num[highestzero]==0&&highestzero>1){
        highestzero--;
    }
    for(int j=1;j<=highestzero+10;j++){
        ans[j]+=num[j];
        ans[j+1]+=ans[j]/10;
        ans[j]%=10;
    }
}
int main(){
    int n;
    cin>>n;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        times(i);
        pluss();
    }
    highestzero=1998;
    while(ans[highestzero]==0&&highestzero>1){
        highestzero--;
    }
    for(int i=highestzero;i>=1;i--){
        cout<<ans[i];
    }
}*/
#include<bits/stdc++.h>
using namespace std;
int num[2000],ans[2000],highestzero;
void times(int m){
    num[1]=1;
    for(int j=2;j<=m;j++){
        highestzero=1000;
        while(num[highestzero]==0){
            highestzero--;
        }
        for(int k=1;k<=highestzero+10;k++){
            num[k]*=j;
            num[k]+=num[k-1]/10;
            num[k-1]%=10;
        }
    }
}
void pluss(){
    for(int j=1;j<=highestzero+10;j++){
        ans[j]+=num[j];
        ans[j+1]+=ans[j]/10;
        ans[j]%=10;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        times(i);
        pluss();
        memset(num,0,sizeof(num));
    }
    highestzero=1000;
    while(ans[highestzero]==0){
        highestzero--;
    }
    for(int i=highestzero;i>=1;i--){
        cout<<ans[i];
    }
}
