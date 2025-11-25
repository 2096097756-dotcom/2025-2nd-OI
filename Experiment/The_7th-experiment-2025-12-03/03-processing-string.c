#include <stdio.h>
 
#define MAXS 100
 
//函数定义实现代码
char *match(char *str, char ch_start, char ch_end){//指针函数
    static char ans[MAXS]="";
    int len=0,pos=0,if_in_str=0,if_cnt=0;
    while(str[len]!='\0') len++;
    for(int i=0;i<len;i++){//状态机!
        if(str[i]==ch_start&&!(if_cnt)){
            if_in_str=1;
            if_cnt=1;
        }
        if(if_in_str){
            ans[pos]=str[i];
            pos++;
        }
        if(str[i]==ch_end&&if_in_str){
            if_in_str=0;
        }
    }
    ans[pos]='\0';
    return ans;
}
 
int main()
{
  char str[MAXS], ch_start, ch_end, *p;
  
  scanf("%s", str);
  scanf(" %c %c", &ch_start, &ch_end);
  p = match(str, ch_start, ch_end);
  printf("%s\n", p);
 
  return 0;
}