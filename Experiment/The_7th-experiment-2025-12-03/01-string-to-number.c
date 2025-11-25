#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getDigitStr(const char *str, char (*p)[100]) {//数组指针
    int is_in_num=0,cnt=0,now_num=0,pos=0;
    for(int i=0;i<=strlen(str);i++){
        if(str[i]<='9'&&str[i]>='0'){
            if((!(str[i-1]<='9'&&str[i-1]>='0')&&!(str[i+1]<='9'&&str[i+1]>='0'))||(i==0&&!(str[i+1]<='9'&&str[i+1]>='0'))){
                continue ;
            }
            if(is_in_num==0){
                cnt++;
                is_in_num=1;
            }
            *(*(p+cnt-1)+pos)=str[i];
            pos++;
        }else{
            if(is_in_num==1){
                *(*(p+cnt-1)+pos)='\0';
                now_num=0;
                pos=0;
                is_in_num=0;
            }
        }
    }
    return cnt;
}

int main(void) {
    char digitStr[100][100] = {""}, str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    int counts = getDigitStr(str, digitStr);
    printf("%d\n", counts);
    for (int i = 0; i < counts; i++) {
        printf("%s%c", digitStr[i], i == counts - 1 ? '\n' : ' ');
    }

    return 0;
}