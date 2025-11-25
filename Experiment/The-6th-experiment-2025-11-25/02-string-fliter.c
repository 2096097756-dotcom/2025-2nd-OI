/*
将有重复字符的字符串（长度不超过30个字符）处理后按如下要求输出：

(1) 多于1个且不超过9个的连续字符只输出1个，并在字符前标注出字符的个数；

(2) 等于1个的字符原样输出；

(3) 超过9个的连续字符，每9个字符为一组（最后一组可不足9个字符），参照上述要求处理；

(4) 函数原型参考：

    void string_filter(char s[]);
    Ussstcc--2021
    U3st2c2-2021
*/
#include<stdio.h>
#include<string.h>
#define MAXN 1000005
char str[MAXN],ans[MAXN];

int posstr=0,posans=0;
void string_fliter(char str[]){
    int lenstr=strlen(str);
    
    for(int i=0;i<lenstr;i++){
        if(str[i]==str[i+1]){
            for(posstr=i;;posstr++){
                if(str[posstr]!=str[posstr+1]) break;
            }
            int length=posstr-i+1;
            char ch=str[i];
            while(length>0){
                if(length<=9){
                    if(length==1) ans[posans++]=ch;
                    else{
                        ans[posans++]='0'+length;
                        ans[posans++]=ch;
                    }
                    break;
                }
                ans[posans++]='9';
                ans[posans++]=ch;
                length-=9;
            }
            i=posstr;
        }else{
            ans[posans++]=str[i];
        }
    }

}  
int main(){
    fgets(str,sizeof(str),stdin);//sizeof,内存空间
    string_fliter(str);
    ans[posans++]='\0';
    printf("%s",ans);
}