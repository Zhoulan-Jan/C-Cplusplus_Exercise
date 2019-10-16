#include<stdio.h>

char *DeleteStr(char *str1,char *str2){
     int arr[256]={0};
     char *s=str2;
     while(*s!='\0'){
       arr[*s]=1;
       s++;
     }
     char * pDel=str1;
     char * pRes=str1;
     while(*pRes!='\0'){
       if(arr[*pRes]!=1){
         *pDel=*pRes;
         pRes++;
         pDel++;
       }else{
         pRes++;
       }
     }
     *pDel='\0';
     return str1;
}

int main(){
  char str1[]="they are students";
  char str2[]="aeiou";
  printf("%s\n",DeleteStr(str1,str2));
  return 0;
}
