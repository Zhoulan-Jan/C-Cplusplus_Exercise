#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>

/**��������������
// ��������//ϣ������//��������//�ϲ�����//������
*/

//���������������  ÿ��n=20  20��
//����һ��len���ȵ��������
void BuildArr(double *arr,int len){
	for (int i = 0; i < len; i++) {
		arr[i] = rand() + (rand() % 100)*0.01;
	}
}

//ð������
//��������
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

//��һ������������С�������±� //���㿪ʼ
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
//ѡ������
//ÿ���ڲ������̵ĺ��������ҵ���С������
void SelectSort(double *arr, int len) {
	for (int i = 0; i < len-1; i++) {
		/*int minIndex = SelectMinKey(arr+sizeof(double), len-i,len);//�ú������ɹ�
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

//��������
//��һ�����ֲ��뵽�������
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

//ϣ������
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

//��������
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
	//ѭ��������low==high
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

//�ϲ�����
//���������������ϵ������ϲ�Ϊһ�������
void Merge(double *arr, double *backArr, int left, int mid, int right){
	//����1 [left...mid]
	//����2 [mid+1...right]
	int start1 = left;   int end1 = mid;
	int start2 = mid + 1;  int end2 = right;
	int k = left;//�״�
	while (start1 <= end1 && start2 <= end2){
		backArr[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	}
	while (start1 <= end1){
		backArr[k++] = arr[start1++];
	}
	while (start2 <= end2){
		backArr[k++] = arr[start2++];
	}
	//for (int k = left; k <= right; k++) {
	//	arr[k] = backArr[k];
	//}
}
void MergeSort(double *arr, double *returnArr, int left, int right){
	double *returnArr2=NULL;
	if (left >= right) {
		returnArr[left] = arr[left];
		return;
	}
	else {
		int mid = ((right - left) >> 1) + left;  //(left + right) / 2;
		int start1 = left;  int end1 = mid;
		int start2 = mid + 1;  int end2 = right;
		MergeSort(arr, returnArr2, start1, end1);
		MergeSort(arr, returnArr2, start2, end2);
		Merge(returnArr2, returnArr, left, mid, right);  //error
		//int k = left;
		//while (start1 <= end1 && start2 <= end2) {
		//	returnArr[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
		//}
		//while (start1 <= end1) {
		//	returnArr[k++] = arr[start1++];
		//}
		//while (start2 <= end2) {
		//	returnArr[k++] = arr[start2++];
		//}
		for (int k = left; k <= right; k++) {  //������õ������ԭ����
			arr[k] = returnArr[k];
		}
	}
}
//������

//��ӡ����
void Print(double *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%.2f   ", arr[i]);
	}
	printf("\n");
}

int main(){
	srand((unsigned)time(NULL));
	double arr[10]={ 0 };
	/*printf("%f",rand()+ (rand() % 100)*0.01);*/
	int len = sizeof(arr) / sizeof(arr[0]);
	//BuildArr(arr,len);

	//���ü򵥵ģ���֤�����㷨�Ƿ�д��
	for (int i = 0; i < len;i++){
		arr[i] = len-i;
	}

	printf("û������ǰ��");
	Print(arr, len);

	//printf("ð�������");
	//BubbleSort(arr, len);
	//Print(arr, len);

	//printf("ѡ�������");
	//SelectSort(arr, len);
	//Print(arr, len);

	//printf("���������");
	//InsertSort(arr, len);
	//Print(arr, len);

	//printf("ϣ�������");
	//int dlta[] = { 5, 3, 1 };
	//int len_dlta = sizeof(dlta) / sizeof(dlta[0]);
	//ShellSort(arr,len,dlta,len_dlta);
	//Print(arr, len);

	//printf("���������");
	//QuickSort(arr, 0, len-1);
	//Print(arr, len);

	printf("�鲢�����");
	double reg[10] = { 0 };
	MergeSort(arr, reg, 0, len - 1);
	Print(reg, len);

	system("pause");
	return 0;
}




