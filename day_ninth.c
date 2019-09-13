#include<stdio.h>

int MaxSubarr(int *nums,int len){
    int sum=0;
    int max_sum=0;
    for(int i=0;i<len;i++){
      if(sum<0) sum=nums[i];
      else sum+=nums[i];
      if(max_sum<sum) max_sum=sum;
    }
    return max_sum;
}

int main(){
  int arr[]={1,-2,3,10,-4,7,2,-5};
  int length = sizeof(arr)/sizeof(arr[0]);
  printf("%d\n",MaxSubarr(arr,length));
  return 0;
}
