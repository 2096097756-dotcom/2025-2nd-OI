#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 105

char str[MAXN];
char* ans;
int n,m;

char *findstr(char *str,int n,int m){
    //“==”比较的是地址而不是内容
    static char ans[MAXN];//注意作为返回值的封装或者申请内存
    int cnt=0;
    if((n-1)<0||(m-1)>strlen(str)||n>m){
        return NULL;
    }
    for(int i=n-1;i<=m-1;i++){
        *(ans+(cnt++))=*(str+i);
    }
    *(ans+cnt)='\0';
    return ans;//注意返回值的封装

}

int main(){
    if(fgets(str,101,stdin)!=NULL){
        int len=strlen(str);
        if(len>0&&str[len-1]=='\n') str[len-1]='\0';
    }
    scanf("%d%d",&n,&m);
    ans=findstr(str,n,m);
    if(ans==NULL){
        printf("Null pointer\n");
    }else{
        printf("%s\n",ans);
    }
    return 0;
}