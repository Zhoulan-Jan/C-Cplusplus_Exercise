#include<stdio.h>

int tract(int n){
  int res=0;
  int num=n;
  int tmp;
  while(n){
    tmp=n%10;
    res=res*10+tmp;
    n/=10;
  }
  if(res==num){
    return 1;
  }else return 0;
}

int main(){
  int n=123344321;
  printf("%d \n",tract(n));
  return 0;
}
