#include<stdio.h>

int NumOne(int n){
  int cnt=0;
  while(n){
    n=n & (n-1);
    cnt++;
  }
  return cnt;
}

int main(){
  int n=2019;
  printf("%d \n",NumOne(n));
  return 0;
}
