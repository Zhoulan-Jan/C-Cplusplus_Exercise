#include<stdio.h>
#include<stdlib.h>

int* AddtoK(int *nums,int len,int k){
  int left=0;
  int right=len-1;
  int *ans=(int *)malloc (sizeof(int) *2);
  while(left<=right){
    if(nums[left]+nums[right]== k) {
        ans[0]=left;
        ans[1]=right;
        return ans;
    }
    else if(nums[left]+nums[right]> k) right--;
    else left++;
  }
  ans[0]=-1;
  ans[1]=-1;
  return ans;
}

int main(){
  int arr[]={1,2,3,5,8,9,10};
  int length=sizeof(arr)/sizeof(arr[0]);
  int *res=AddtoK(arr,length,18);
  int returnsz=2;
  for(int i=0;i<returnsz;i++){
    printf("%d\n",res[i]);
  }
  return 0;
}
