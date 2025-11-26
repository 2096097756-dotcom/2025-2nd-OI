//Luogu_P1024,2025.11.16
#include<bits/stdc++.h>
using namespace std;
const double MINM=1e-6;
const double MINMM=1e-14;

double a,b,c,d;
double roots[3];
int cnt;

double calequa(double x){
    return a*pow(x,3)+b*pow(x,2)+c*pow(x,1)+d;
}

double finding_roots(double left,double right){
    double mid=left+(right-left)/2;
    if(abs(calequa(mid))<MINM) return mid;
    if(calequa(right)<0&&calequa(left)>0){
        if(calequa(mid)>0) return finding_roots(mid,right);
        else return finding_roots(left,mid);
    }
    else{
        if(calequa(mid)>0) return finding_roots(left,mid);
        else return finding_roots(mid,right);
    }
}

void starting(){
    for(int i=-100;i<=100;i++){
        if(cnt>=3) break;
        if(abs(calequa(i))<MINM){
            roots[cnt++]=(double)i;
            continue;
        } //先判断端点值
        if((calequa(i)*calequa(i+1)<0)&&abs(calequa(i)*calequa(i+1))>MINMM) roots[cnt++]=finding_roots((double)i,(double)(i+1));//注意:分开端点和内容,判断内容时端点需要防止误差(>MINMM)
    }
}

void print(){
    for(int i=0;i<3;i++){
        printf("%.2f ",roots[i]);
    }
}

int main(){
    cin>>a>>b>>c>>d;
    starting();
    print();
    return 0;
}