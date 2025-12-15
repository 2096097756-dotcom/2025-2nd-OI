//2025.12.13,17:33
//1.3.9_编写一段程序，补全括号
//不带地址的void全是形式参数
#include<bits/stdc++.h>
using namespace std;

stack<char> op;
stack<string> value;//当作一个新的操作数，压回操作数栈。
//value 是一个存放数字和表达式的结构！

string fill_out(string str){
    int len=str.length();
    for(int i=0;i<len;i++){
        char ch=str[i];
        if(ch<='9'&&ch>='0'){
            string Temporary_str;
            Temporary_str+=ch;
            value.push(Temporary_str);
        }
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/') op.push(ch);
        if(ch==')'){
            string value1=value.top();//这里的value应该是一个string!
            value.pop();
            string value2=value.top();
            value.pop();
            char op_now=op.top();
            op.pop();
            string target_str="("+value2+op_now+value1+")";
            value.push(target_str);
        }
    }
    return value.top();
} 

string str,new_string;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>str;
    new_string=fill_out(str);
    cout<<new_string<<endl;
    return 0;
}