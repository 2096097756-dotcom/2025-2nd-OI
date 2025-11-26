#include<bits/stdc++.h>//从小到大排列
using namespace std;
#define N 900001

int n,m,a[N];

int fast_read(){
    int x=0, f=1; char ch=getchar();
    while (ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int find(int op){//[l,r]是一个闭区间,直到区间长度为1截止
    int left=0,right=n-1;
    while(right>left){
        int mid=left+(right-left)/2;
        if(op<=a[mid]) right=mid;//想象一个以mid为中心的平台
        else left=mid+1;//一定不在左边了!且至少在后面一个！
    }
    if(a[left]==op) return left+1;//left==right
    return -1;
}

int find1(int op,int left,int right){//递归做
    if(left==right){
        if(op==a[left]) return left;
        return -1;
    }
    int mid=left+(right-left)/2;
    if(op<=a[left]) return find1(op,left,mid);
    else return find1(op,mid+1,right);
}
/*
    第三个方法:STL，1-index
    int n=read(),m=read();//读入
	for(int i=1;i<=n;i++) a[i]=read();
	while(m--){
		int x=read();
		int ans=lower_bound(a+1,a+n+1,x)-a;//二分搜，注意-a,就是下标等于指针相减.
        //lower_bound是下确界,就是第一次出现的地方,upperbound是上确界upperbound-1就是最后一次出现的地方.
		if(x!=a[ans]) printf("-1 ");//没有，输出-1
		else printf("%d ",ans);//有，输出ans
	}
*/

int main(){
    n=fast_read(),m=fast_read();
    for(int i=0;i<n;i++){
        a[i]=fast_read();
    }
    for(int i=0;i<m;i++){
        int op;
        op=fast_read();
        printf("%d ",find(op));
        //printf("%d ",find1(op,0,n-1));
    }
    return 0;
}
/*
用gemini给出的方法写:
int ans;//注意ans定义在循环的外面.
while(left<=right){
    int mid=left+(right-left)/2;
    long long sum=count(mid);
    if(sum>=m){//题目所给的条件,就是找符合要求的至少得到m的树木
        ans=mid;//这个时候mid就符合要求，记录下来
        left=mid+1;//往右边搜索,找到最大的索引
    }else{
        right=mid-1;//往左边搜索，不记录不符合要求的ans
    }
}
    [left=mid+1,right=mid-1,mid]索引,只有这样才能出现right<left的余地!
*/