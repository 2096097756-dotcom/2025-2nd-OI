//LuoguP1678
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;

int n,m;
int stu[MAXN],school[MAXN];
long long cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>m>>n;
    for(int i=0;i<m;i++) cin>>school[i];
    for(int i=0;i<n;i++) cin>>stu[i];
    sort(school,school+m);
    for(int i=0;i<n;i++){
        int target=0;
        int p=lower_bound(school,school+m,stu[i])-school;//p是最大的下标,第一个>=stu[i]的下标

        if(p>=m) target=stu[i]-school[m-1];//学生考的最高
        else if(p==0) target=school[0]-stu[i];//学生考的最低
        else target=min(abs(school[p-1]-stu[i]),abs(school[p]-stu[i]));

        cnt+=target;
    }
    cout<<cnt<<endl;
    return 0;
}