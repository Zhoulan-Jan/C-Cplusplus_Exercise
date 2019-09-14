#include<stdio.h>

int my_pow(int x,int y){
  int ans=1;
  while(y){
    ans*=x;
    y--;
  }
  return ans;
}

int main(){
  int m=2;
  int n=3;
  printf("%d\n",my_pow(m,n));
  return 0;
}
