//NOIP提高组2025T1
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+1;//栈溢出?
const long long MAXNN=1e9+1;

long long n,money;
long long ans;

struct CANDY{
    long long odd,even;
    bool pos_candy=0;
}candy[MAXN];

void reset(){
    for(int i=1;i<=n;i++) candy[i].pos_candy=0;
}

bool check(int num_candy){//现在买num个糖果可不可以?
    //现在有m的钱,n种糖果
    //实时排序!

    reset();

    long long candy_sort[MAXN],num=1,sum=0;

    while(num<=num_candy){

        long long minmm=MAXNN,minindex=0;
        for(int i=1;i<=n;i++){
            if(candy[i].pos_candy==0) candy_sort[i]=candy[i].odd;
            else candy_sort[i]=candy[i].even;
            if(candy_sort[i]<minmm){//这里的数据被修改了!
                minmm=candy_sort[i];
                minindex=i;
            }
        }
        sum+=minmm;
        candy[minindex].pos_candy=!candy[minindex].pos_candy;
        
        if(sum>money) return 0;
        num++;
    }
    if(sum<=money) return 1;
    return 0;
}

long long binary_search(){
    long long left=0,right=MAXNN;
    while(right>=left){

        reset();
        long long mid=left+(right-left)/2;
        if(check(mid)){
            //cout<<mid<<endl;
            ans=mid;//糖果少的情况下可以
            left=mid+1;
        }
        else right=mid-1;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>money;
    for(long long i=1;i<=n;i++){
        cin>>candy[i].odd>>candy[i].even;
    }

   cout<<binary_search()<<endl;

   return 0;
}