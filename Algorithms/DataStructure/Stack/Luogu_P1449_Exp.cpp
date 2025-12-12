#include<bits/stdc++.h>
using namespace std;
string str;
stack<int> num_stack;


bool if_num(char c){
    if(c<='9'&&c>='0')return 1;
    return 0;
}

int cal(string str){
    bool if_in_num=0;
    int now_num=0;
    for(int i=0;i<str.length();i++){
        if(if_num(str[i])){
            if(if_in_num==0){
                if_in_num=1;
            }
            now_num=now_num*10+(int)(str[i]-'0');
        }else{
            if(if_in_num==1&&str[i]=='.'){
                if_in_num=0;
                num_stack.push(now_num);
                //cout<<now_num<<endl;
                now_num=0;
            }
            if(str[i]!='.'&&str[i]!='@'){
                int numa=num_stack.top();
                num_stack.pop();
                int numb=num_stack.top();
                num_stack.pop();
                int new_num=0;
                //cout<<str[i]<<endl;

                switch(str[i]){
                    case '+':{
                        new_num=numb+numa;//后缀：老资历在前面
                        break;
                    }
                    case '-':{
                        new_num=numb-numa;
                        break;
                    }
                    case '*':{
                        new_num=numb*numa;
                        break;
                    }
                    case '/':{
                        new_num=numb/numa;
                        break;
                    }
                }
                //cout<<new_num<<endl;
                num_stack.push(new_num);
            }
        }
    }
    return num_stack.top();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>str;
    cout<<cal(str)<<endl;
    return 0;
}