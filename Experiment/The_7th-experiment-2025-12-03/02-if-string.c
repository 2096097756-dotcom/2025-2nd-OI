#include <stdio.h>
#include <string.h>

int strendByIndex(const char *s1, const char *s2) {
    int len1=strlen(s1),len2=strlen(s2);
    if(len2>len1) return 0;//len1-len2
    int delta=len1-len2;
    for(int i=0;i<len2;i++){//这里最后一位是\0!
        if(s1[delta+i]!=s2[i]) return 0;
    }
    return 1;
}

int strendByPointerOffset(const char *s1, const char *s2) {
    int len1=strlen(s1),len2=strlen(s2);
    if(len2>len1) return 0;
    int delta=len1-len2;
    for(int i=0;i<len2;i++){//这里最后一位是\0!
        if(*(s1+delta+i)!=*(s2+i)) return 0;
    }
    return 1;
}

int strendByPointer(const char *s1, const char *s2) {
    int len1=strlen(s1),len2=strlen(s2);
    if(len2>len1) return 0;
    int delta=len1-len2;
    for(int i=0;i<len2;i++){//这里最后一位是\0!
        char *p1=(char *)s1+delta+i,*p2=(char *)s2+i;
        if(*(s1+delta+i)!=*(s2+i)) return 0;
    }
    return 1;

}

int main() {
  char s1[100], s2[100];
  scanf("%s", s1);
  scanf("%s", s2);
  printf("%d\n", strendByIndex(s1, s2));
  printf("%d\n", strendByPointerOffset(s1, s2));
  printf("%d\n", strendByPointer(s1, s2));

  return 0;
}