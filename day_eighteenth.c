#include<stdio.h>
#include<stdlib.h>

int isPowTwo(int n){
  for(int i = 1;i <= n;i<<=1){
    if(i == n) return 1;
  }
  return 0;
}

int main(){
  int n1=30;
  int n2=32;
  printf("%d %d \n",isPowTwo(n1),isPowTwo(n2));
  return 0;
}
