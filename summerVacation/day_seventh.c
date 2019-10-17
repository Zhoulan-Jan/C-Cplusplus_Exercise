#include<stdio.h>

int MinKNum(int *num,int k){
    int min=num[0];
    for(int i=0;i<k;i++){
      if(min>num[i]){
        min=num[i];
      }
    }
    return min;
}

int main(){
  int arr[]={5,6,3,7,8,10,2};
  //int len=sizeof(arr)/sizeof(arr[0]);
  printf("%d\n",MinKNum(arr,4));
}
