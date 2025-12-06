#include<bits/stdc++.h>
using namespace std;
const int MAXN=30;
const int MAXNN=1e6+10;

int n,cnt=1;
int ans[MAXN];
int total_ans[MAXNN][MAXN];
bool col_occupied[MAXN],diag1_occupied[2*MAXN+1],diag2_occupied[2*MAXN+1];//状态参量

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    memset(col_occupied,1,sizeof(col_occupied));
    memset(diag1_occupied,1,sizeof(diag1_occupied));
    memset(diag2_occupied,1,sizeof(diag2_occupied));

}

bool check(int row,int col){
    int diag1=row-col+n;
    int diag2=row+col;
    return ((col_occupied[col])&&(diag1_occupied[diag1]))&&diag2_occupied[diag2];
}

void output(){
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<((i==n)?"":" ");
        total_ans[cnt][i]=ans[i];
    }
    cout<<endl;
}

void dfs(int row){
    if(row>n){

        if(cnt<=3){
            output();
        }
        cnt++;
        return ;
    }

    for(int i=1;i<=n;i++){//row+col=const,diag2;row-col=const,diag1
        if(check(row,i)){

            int diag1=row-i+n;//主队角线和副对角线的index
            int diag2=row+i;

            col_occupied[i]=0;
            diag1_occupied[diag1]=0;
            diag2_occupied[diag2]=0;
            ans[row]=i;

            dfs(row+1);

            ans[row]=0;
            col_occupied[i]=1;
            diag1_occupied[diag1]=1;
            diag2_occupied[diag2]=1;
        }
    }

    return ;
}

void print(){
    dfs(1);
    cout<<cnt-1<<endl;

}

int main(){
    input();
    print();

    return 0;
}