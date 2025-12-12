#include<stdio.h>
#include <stdlib.h>
int main(){
    FILE *fp;
    fp=fopen("Data.txt","w");
    fprintf(fp,"Hello,world!\n");
    fclose(fp);
    free(fp);
    fp=NULL;
    
    return 0;
}