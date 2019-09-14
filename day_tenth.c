#include<stdio.h>
#include<string.h>

char FirstCharAppOnce(char *str){
    int arr[256]={0};
    char *p=str;
    while(*p!='\0'){
        arr[*p]++;
        p++;
    }
    char *q=str;
    while(*q!='\0'){
      if(arr[*q]==1){
        return *q;
        break;
      }
      q++;
    }
    return '0';
}

int main(){
  char s[]="agaccdeff";
  printf("%c\n",FirstCharAppOnce(s));
  return 0;
}
