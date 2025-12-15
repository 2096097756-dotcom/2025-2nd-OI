#include<bits/stdc++.h>
using namespace std;

string str,new_string;
stack<char> value_stack;
struct OP{
    char op;
    int value;
};

OP new_operator[4]={{'+',1},{'-',1},{'*',2},{'/',2}};

bool cmp_operator(char ch1,char ch2){
    int val1=-1,val2=-1;
    for(int i=0;i<4;i++){
        if(ch1==new_operator[i].op) val1=new_operator[i].value;
        if(ch2==new_operator[i].op) val2=new_operator[i].value;
    }
    return val1>val2;
}
/*
void put_stack(char ch){
    string str_new="";
    str_new+=ch;
    value_stack.push(str_new);
    return ;
}*/


int get_priority(char op) {
    if (op=='+'||op=='-') return 1;
    if (op=='*'||op=='/') return 2;
    return 0; // 如果是 '(' 或者其他
}


string tail_to_mid(string str){
    string new_str;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='(') value_stack.push(ch);
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(!value_stack.empty()){//top需要特判
                char stack_top_op=value_stack.top();
                if(stack_top_op!='('){
                    if(cmp_operator(stack_top_op,ch)){//如果栈顶的运算逻辑高一些，那么就一直输出栈顶直到碰到"("或者"+"为止
                        while(!value_stack.empty()&&get_priority(value_stack.top())>get_priority(ch)){
                            new_str+=value_stack.top();//出去
                            value_stack.pop();//运算符是不能直接输出的，必须进栈。
                        }//短路！
                        value_stack.push(ch);
                        //value_stack.push(ch);
                    }else value_stack.push(ch);//优先级高
                }else value_stack.push(ch);
            }
            else value_stack.push(ch);
        }
        else if(ch==')'){
            while(!value_stack.empty()&&value_stack.top()!='('){
                new_str+=value_stack.top();
                value_stack.pop();
            }
            value_stack.pop();//这个括号结束了!
        }
        else new_str+=ch;
    }
    while(!value_stack.empty()){
        char ch=value_stack.top();
        new_str+=ch;
        value_stack.pop();
    }
    return new_str;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,str);
    new_string=tail_to_mid(str);
    cout<<new_string<<endl;
    return 0;
}

/*
三条规则：
数字按顺序排列
运算符压入栈
一旦低的跑到高的的上面，就弹出来那些高的运算符，先做他们的运算再压栈
括号栈内优先级最低，弹进去"("，")"不弹，直到弹出来直到前面括号的表达式（两个括号之间可以看成独立的中缀表达式）
最后栈吐出来


后缀表达式里面没有括号，栈就是顺序
*/

/*
这里的优先级只是相对优先级，只在括号内起作用
优先级的层数就是树的层数
清空括号就是递归的小树结束运算！（依次搞完剩下的优先级比较低的部分  吧）
*/