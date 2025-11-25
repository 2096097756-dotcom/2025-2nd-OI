/*
(1) 输入字符串限200个字符以内，若超出200个则只取前200个；

(2) 规定单词的含义为连续的字母（大写或小写）构成的字符串，字母以外的其他符号和空白符号都视为单词之间的分隔符；

(3) 若有多个等长单词均达到最大长度，则只输出最先出现的那一个；

(4) 要求用指针实现。
*/
#include<stdio.h>
#include<string.h>
#define MAXN 100000

int if_word(char c){
    if((c>='a'&&c<='z')||(c>'A'&&c<'Z')) return 1;
    return 0;
}

char *find_the_longest_word(char *str){
    int len=strlen(str);
    static char ans[MAXN];

    int if_in_word=0,new_word_index=0,maxn=0;
    for(int i=0;i<len;i++){
        if(if_word(str[i])&&!(if_in_word)){
            if_in_word=1;
            new_word_index=i;
        }
        if(!if_word(str[i])){
            if_in_word=0;
            int len_word=i-new_word_index;
            if(len_word>maxn){
                maxn=len_word;
                for(int j=new_word_index;j<=i;j++){
                    int pos=j-new_word_index;
                    ans[pos]=str[j];
                    if(pos==199){
                        ans[200]='\0';
                        break;
                    }
                }
                if(len_word<200) ans[len_word]='\0';
                else ans[200]='\0';
            }
        }
    }

    return ans;
}

char str[MAXN],*ans;
int main(){
    fgets(str,200,stdin);//注意:最多读取MAXN个
    ans=find_the_longest_word(str);
    printf("%s",ans);
    return 0;
}