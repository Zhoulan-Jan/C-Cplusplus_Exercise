#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>


/**将数组升序排列
// 插入排序//希尔排序//快速排序//合并排序//堆排序
*/

//随机浮点数的生成  每组n=20  20组
//生成一组len长度的随机数组
void BuildArr(double *arr,int len){
	for (int i = 0; i < len; i++) {
		arr[i] = rand() + (rand() % 100)*0.01;
	}
}

//冒泡排序
//大数沉淀
void BubbleSort(double *arr, int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j]>arr[j + 1]) {
				double t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

//在一个数组里找最小的数字下标 //从零开始
int SelectMinKey(double *arr, int actlen,int len){
	double min = arr[0];
	int index = 0;
	for (int i = actlen; i < len; i++){
		if (min>arr[i]){
			min = arr[i];
			index = i;
		}
	}
	return index;
}
//选择排序
//每次在不断缩短的后面数组找到最小的数字
void SelectSort(double *arr, int len) {
	for (int i = 0; i < len-1; i++) {
		/*int minIndex = SelectMinKey(arr+sizeof(double), len-i,len);//该函数不成功
		if (i != minIndex) {
			double t = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = t;
		}*/
		int minIndex = i;
		int j;
		for (j = i+1; j < len; j++) {
			if (arr[minIndex]>arr[j]) {
				minIndex = j;
			}
		}
		if (i != minIndex) {
			double t = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = t;
		}
	}
}

//插入排序
//将一个数字插入到有序表中
void InsertSort(double *arr, int len) {
	for (int i = 1; i < len; i++){
		if (arr[i] < arr[i - 1]){
			double toInsertNum = arr[i];
			int j;
			for (j = i - 1; toInsertNum<arr[j]; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = toInsertNum;
		} 
	}
}

//希尔排序
void shellInsert(double *arr, int len, int dk){
	for (int i = dk; i < len; i++){
		if (arr[i] < arr[i - dk]){
			double toInsertNum = arr[i];
			int j;
			for (j = i - dk; toInsertNum < arr[j] && j >= 0; j -= dk){
				arr[j + dk] = arr[j];
			}
			arr[j + dk] = toInsertNum;
		}
	}
}
void ShellSort(double *arr, int len, int *dlta, int t){
	for (int k = 0; k < t; k++){
		shellInsert(arr, len, dlta[k]);
	}
}

//快速排序
int Partition(double *arr, int low,int high){
	double pivotkey = arr[low];
	while (low < high){
		while (low < high && pivotkey <= arr[high]){
			--high;
		}
		arr[low] = arr[high];
		while (low < high && pivotkey >= arr[low]){
			++low;
		}
		arr[high] = arr[low];
	}
	//循环结束后，low==high
	arr[low] = pivotkey;
	return low;
}
void QuickSort(double *arr, int low, int high){
	if (low < high){
		int pivotloc = Partition(arr, low, high);
		QuickSort(arr, low, pivotloc - 1);
		QuickSort(arr, pivotloc + 1, high);
	}
}

//归并排序
//将两个或两个以上的有序表合并为一个有序表
//void Merge(double *arr, double *backArr, int left, int right){
//	//数组1 [left...mid]
//	//数组2 [mid+1...right]
//	int mid = (left + right) / 2;
//	int start1 = left;   int end1 = mid;
//	int start2 = mid + 1;  int end2 = right;
//	int k = left; //易错
//	while (start1 <= end1 && start2 <= end2){
//		backArr[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
//	}
//	while (start1 <= end1){
//		backArr[k++] = arr[start1++];
//	}
//	while (start2 <= end2){
//		backArr[k++] = arr[start2++];
//	}
//	for (int k = left; k <= right; k++) {
//		arr[k] = backArr[k];
//	}
//}
//void MergeSorterror(double *arr, double *returnArr, int left, int right){
//	double *returnArr2 = { 0 };
//	if (left >= right) {
//		returnArr[left] = arr[left];
//		return;
//	}
//	else {
//		int mid = ((right - left) >> 1) + left;  //(left + right) / 2;
//		int start1 = left;  int end1 = mid;
//		int start2 = mid + 1;  int end2 = right;
//		MergeSort(arr, returnArr2, start1, end1);
//		MergeSort(arr, returnArr2, start2, end2);
//		Merge(returnArr2, returnArr, left,right);  //error
//	}
//}

//参考他人的算法
void MergeSort(double *arr, double *returnArr, int left, int right) {
	if (left >= right) {
		//returnArr[left] = arr[left];
		return;
	}
	else {
		int mid = ((right - left) >> 1) + left;
		int start1 = left; int end1 = mid;
		int start2 = mid + 1; int end2 = right;
		MergeSort(arr, returnArr, start1, end1);
		MergeSort(arr, returnArr, start2, end2);
		int k = left;
		while (start1 <= end1 && start2 <= end2) 
		{
			returnArr[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
		}
		while (start1 <= end1) {
			returnArr[k++] = arr[start1++];
		}
		while (start2 <= end2) {
			returnArr[k++] = arr[start2++];
		}
		for (int k = left; k <= right; k++) {
			arr[k] = returnArr[k];
		}
	}
}
//堆排序
void MaxHeap(double *arr, int len, int n)
{
	int parent = n;
	int child = parent * 2 + 1;
	double tmp = 0;
	while (child < len)
	{
		if (child + 1 < len && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] < arr[child])
		{
			tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;

	}
}

void BuildHeap(double *arr, int len)
{
	int i = len - 1;
	for (i; i >= 0; i--)
	{
		MaxHeap(arr, len, i);
	}
}

void HeapSort(double *arr, int len)
{
	BuildHeap(arr, len); //建堆
	double tmp = 0;
	int n = len - 1;
	for (int i = len; i > 0; i--)
	{
		tmp = arr[0];    // 交换
		arr[0] = arr[i - 1];
		arr[i - 1] = tmp;
		MaxHeap(arr, --len, 0);  //再次建堆
	}
}

//打印数组
void Print(double *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%.2f   ", arr[i]);
	}
	printf("\n");
}

#define LENGTH 200000
int main(){
	srand((unsigned)time(NULL));
	double arr[LENGTH]={ 0 };
	/*printf("%f",rand()+ (rand() % 100)*0.01);*/
	int len = sizeof(arr) / sizeof(arr[0]);
	BuildArr(arr,len);

	//先用简单的数据，验证排序算法是否写对
	//for (int i = 0; i < len;i++){
	//	arr[i] = len-i;
	//}

	printf("没有排序前：");
	/*Print(arr, len);*/
	clock_t run_start = clock();

	//printf("冒泡排序后：");
	//BubbleSort(arr, len);
	//Print(arr, len);

	//printf("选择排序后：");
	//SelectSort(arr, len);
	//Print(arr, len);

	//printf("插入排序后：");
	//InsertSort(arr, len);
	//Print(arr, len);

	//printf("希尔排序后：");
	//int dlta[] = { 5, 3, 1 };
	//int len_dlta = sizeof(dlta) / sizeof(dlta[0]);
	//ShellSort(arr,len,dlta,len_dlta);
	//Print(arr, len);

	//printf("快速排序后：");
	//QuickSort(arr, 0, len-1);
	//Print(arr, len);

	//printf("归并排序后：");
	//double reg[LENGTH] = { 0 };
	//MergeSort(arr, reg, 0, len - 1);
	/*Print(reg, len);*/

	printf("堆排序后：");
	HeapSort(arr, len);

	//计算时间
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);

	system("pause");
	return 0;
}

//int main() {
//	clock_t run_start = clock();
//	myfunc();
//	clock_t run_end = clock();
//	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
//	printf("Run Time: %.3f s \n", runtime);
//	system("pause");
//	return 0;
//}




