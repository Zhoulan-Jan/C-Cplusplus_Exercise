#include<stdio.h>

int FindHalfLength(int *num,int len){
  for(int i=0;i<len;i++){
    for(int j=0;j<i;j++){
      if(num[j]>num[j+1]){
          int t=num[j];
          num[j]=num[j+1];
          num[j+1]=t;
      }
    }
  }
  return num[len/2];
}

int main(){
  int arr[]={1,2,3,2,2,2,5,4,2};
  int length=sizeof(arr)/sizeof(arr[0]);
  printf("%d \n",FindHalfLength(arr,length));
  return 0;
}
