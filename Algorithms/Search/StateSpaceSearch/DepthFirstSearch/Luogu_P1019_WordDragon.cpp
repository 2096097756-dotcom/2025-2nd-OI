//LuoguP1019 WordDragon
#include<bits/stdc++.h>
using namespace std;
const int MAXN=30;

int n,maxm=0;

struct Dragon{
    int len,cnt=2;
    string s;
}word_dragon[MAXN];
char ch;


Dragon Integrate_word(string str_now,string add_str){

    Dragon new_str={0,0,""};
    int num;

    //if(str_now[str_now.length()-1]!=add_str[0])return new_str;原来的代码太严格，不能直接判断!

    new_str.s=str_now;

    for(num=1;num<=min(str_now.length(),add_str.length())-1;num++){//从1开始!
        if(str_now.substr(str_now.length()-num)==add_str.substr(0,num)){//注意是下标索引
            break;
        }//从大开始往小了贪心?
        //不对！！！应该是先从小的开始，然后找到最小的就可以了!
    }//重复的长度为num(index:0~(num-1))?并不是!这时候可以直接取num+1;

    if(num<min(str_now.length(),add_str.length())){
        for(int i=num;i<add_str.length();i++){
            new_str.s+=add_str[i];
        }
        new_str.len=str_now.length()+add_str.length()-num;
    }

    return new_str;//返回总长度!
    //保持清晰的头脑，任何时候想一想怎么写返回，注释写的对不对

}

void dfs(int total_length,string str_now){
    
    for(int i=1;i<=n;i++){
        if(word_dragon[i].cnt>0){
            int len_new=Integrate_word(str_now,word_dragon[i].s).len;

            if(len_new){

                word_dragon[i].cnt--;
                dfs(len_new,Integrate_word(str_now,word_dragon[i].s).s);//这里是拼接好的字符串了!
                word_dragon[i].cnt++;

            }
        }
    }

    maxm=max(maxm,total_length);

    //cout<<str_now<<endl;
    return ;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>word_dragon[i].s;
    getchar();
    cin>>ch;

    for(int i=1;i<=n;i++){
        if(word_dragon[i].s[0]==ch){
            word_dragon[i].cnt--;
            dfs(word_dragon[i].s.length(),word_dragon[i].s);//初始值需要改!
            word_dragon[i].cnt++;//漏掉了回溯！
        } 
    }

    cout<<maxm<<endl;
    return 0;
}
/*
Gemini_Solution 图论法

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
string words[25];
int g[25][25];  // g[i][j] 存储 words[i] 接 words[j] 的最小重合长度
int used[25];   // 记录使用次数
int ans = 0;

// 预处理函数：计算 s1 接 s2 的最小重合长度
int calc_overlap(string &s1, string &s2) {
    // 同样是从 1 开始枚举
    // 必须 < min_len，不能包含
    int limit = min(s1.length(), s2.length());
    for (int k = 1; k < limit; k++) {
        // 检查 s1 的后缀 == s2 的前缀
        if (s1.substr(s1.length() - k) == s2.substr(0, k)) {
            return k; // 找到最小重合，直接返回
        }
    }
    return 0; // 接不上
}

// u: 上一个单词的下标
// len: 当前龙的总长度
void dfs(int u, int len) {
    ans = max(ans, len);

    // 遍历所有可能的下一个单词 v
    for (int v = 0; v < n; v++) {
        // 条件1: 两个单词之间有重合 (g[u][v] > 0)
        // 条件2: 单词 v 使用次数还没满 2 次
        if (g[u][v] > 0 && used[v] < 2) {
            used[v]++;
            // 新长度 = 当前长 + 单词v的长 - 重合部分
            dfs(v, len + words[v].length() - g[u][v]);
            used[v]--; // 回溯
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> words[i];
    
    char start_ch;
    cin >> start_ch;

    // 1. 预处理所有单词对之间的重合关系
    // 这是一个 N*N 的矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = calc_overlap(words[i], words[j]);
        }
    }

    // 2. 寻找龙头，开始 DFS
    for (int i = 0; i < n; i++) {
        if (words[i][0] == start_ch) {
            used[i]++;
            // 初始状态：上一个词是 i，当前长度是 i 的长度
            dfs(i, words[i].length());
            used[i]--;
        }
    }

    cout << ans << endl;
    return 0;
}


*/