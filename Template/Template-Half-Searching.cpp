#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,m,a[MAXN];
int fast_read(){// read a single int quickly .
    int num=0,sgn=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sgn=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        num=num*10+(int)(c-'0');
        c=getchar();
    }
    return sgn*num;
}
int main(){
    int n=read(),m=read();
    for(int i=0;i<n;i++){
        a[i]=read();
    }
    
}