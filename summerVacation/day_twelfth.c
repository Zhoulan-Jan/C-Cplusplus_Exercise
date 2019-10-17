#include<stdio.h>
#include<stdlib.h>

int * TowNumsAppOnce(int *nums,int len){
  int res=0;
  for(int i=0;i<len;i++){
    res^=nums[i];
  }
  int* answer=(int *) malloc (sizeof(int)*2);
  printf("res:%d \n",res);
  for(int j=0;j<len;j++){
    for(int k=j;k<len;k++){
      if((nums[j]^nums[k])==res){
        answer[0]=nums[j];
        answer[1]=nums[k];
        break;
      }
    }
  }
  return answer;
}

int main(){
  int arr[]={1,3,5,7,7,7,7,7,7,7,1,3,5,9};
  int length=sizeof(arr)/sizeof(arr[0]);
  int returnsz=2;
 int * ans=TowNumsAppOnce(arr,length);
  for(int i=0;i<returnsz;i++){
   printf("%d \n",ans[i]);
  }
  return 0;
}
