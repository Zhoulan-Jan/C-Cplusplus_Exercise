#include<stdio.h>
#include<math.h>

//int Fibonacci1(int n){
  //double sqrt5=sqrt(5.0);
  //double res=pow((1+sqrt5)/2,n+1)-pow((1-sqrt5)/2,n+1);
  //return (int) (res/sqrt5);
//}

int Fibonacci2(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int first=1;
    int second=2;
    for(int i=3;i<=n;i++){
      int third=first+second;
      first=second;
      second=third;
    }
    return second;
}

int main(){
  int n=18;
  //printf("%d\n",Fibonacci1(n));
  printf("%d\n",Fibonacci2(n));
  return 0;
}
