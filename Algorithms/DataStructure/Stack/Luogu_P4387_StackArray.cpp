#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
int n,m;
int input[MAXN],output[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        memset(input,0,sizeof(input));
        memset(output,0,sizeof(output));
        for(int j=1;j<=m;j++) cin>>input[j];
        for(int j=1;j<=m;j++) cin>>output[j];

        stack<int> new_stack;
        int cnt_input=1,cnt_output=1;
        new_stack.push(input[cnt_input]);
        cnt_input++;
        bool if_stack=0;

        //cout<<endl;
        while(!new_stack.empty()){
            int top_number=new_stack.top();

            while(top_number==output[cnt_output]){
                new_stack.pop();
                cnt_output++;
                if(!new_stack.empty()){
                    top_number=new_stack.top();
                    //cout<<top_number<<' ';
                }else break;
            }

            if(cnt_input>m&&cnt_output<=m){
                if_stack=1;
                break;
            }else if(cnt_input==m+1&&cnt_output==m+1){
                break;
            }
            if(cnt_input<=m){
                new_stack.push(input[cnt_input]);
                cnt_input++; 
            }
             
            /*
            if(top_number!=output[cnt_output]){
                new_stack.push(input[cnt_input]);
                cnt_input++;
            }else{
                new_stack.pop();
                
                cnt_output++;
            }
            */
            
        }  
        if(if_stack==1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }

    return 0;
}