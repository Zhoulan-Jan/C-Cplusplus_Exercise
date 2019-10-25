#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

#define LENGTH 20

//��λС�� ��ʮ ���� ��ǧ ���� ��ʮ�� ������
//��� ������ ==
void BuildArr(double *arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = rand() + rand() % 10000 * 0.0001;
	}
}

//˳�����
double SequenSearch(double *arr, int len,int index) {
	for (int i = 0; i < len; i++) {
		if (i == index) {
			return arr[i];
		}
	}
	return -1;
}

double SequenSearch2(double *arr, int len, double key) {
	for (int i = 0; i < len; i++) {
		double x = arr[i] - key;
		if (x >= -0.001 && x <= 0.0001) {
			return arr[i];
		}
	}
	printf("���Ҳ��ɹ���");
	return -1;
}

//�������� +���ֲ��� 
int Partition(double *arr, int low, int high){
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

double BinarySearch(double *arr, int len, int index) {
	int left = 0; 
	int right = len - 1;
	while (left <= right) {
		int mid = (right - left)/2 + left;
		if (index > mid) left = mid + 1;
		else if (index < mid) right = mid - 1;
		else return arr[mid];
	}
	return -1;
}

double BinarySearch2(double *arr, int len, double key) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (key - arr[mid] > 0.1) left = mid + 1;
		else if (key - arr[mid] < 0.1) right = mid - 1;
		else return arr[mid];
	}
	printf("���Ҳ��ɹ���");
	return -1;
}

//���������� ����������
typedef struct BiNode{
	double val; 
	BiNode *rchild;
	BiNode *lchild;
	BiNode(double val) :val(val), rchild(NULL), lchild(NULL){}
}*BiTree,BiTNode;

//����
//BiTree SearchBST(BiTree T, double key, BiTree f, BiTree p) {
//	if (!T) {
//		p = f;
//		return false;
//	}
//	else if (key - T->val > 0.1) {  //������������
//		return SearchBST(T->rchild, key, T, p);
//	} 
//	else if (key - T->val < 0.1) {
//		return SearchBST(T->lchild, key, T, p);
//	}
//	else {
//		p = T;
//	}
//}

//����
BiTree InsertBST(BiNode *T, int len, int *pi) {
	//BiTree p = NULL;
	//if (!SearchBST(T, elem, NULL, p)) {
	//	BiTree newNode = (BiTree)malloc(sizeof(BiTNode));
	//	newNode->val = elem;
	//	newNode->lchild = newNode->rchild = NULL;
	//	if (!p) {
	//		T = newNode;
	//	}
	//	else if (elem - p->val < 0.1) {
	//		p->lchild = newNode;
	//	}
	//	else p->rchild = newNode;
	//}
	BiTree newNode = (BiTree)malloc(sizeof(BiTNode));
	newNode->val = T[*pi];
	newNode->lchild = newNode->rchild = NULL;
	if (T == NULL) {
		return newNode;
	}
	if (elem - T->val < 0.1) {
		T->lchild = InsertBST(T, elem);
	}
	else if (elem - T->val > 0.1) {
		T->rchild = InsertBST(T, elem);
	}
	return T;
}

//��ӡ����
void Print(double *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%.4f  ", arr[i]);
	}
	printf("\n");
}

int main() {
	srand((unsigned)time(NULL));
	double arr[LENGTH] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BuildArr(arr, len);
	//Print(arr, len);

	clock_t run_start = clock();

	//���ҳɹ�:������������С��Χ�ڵ�һ������
	int index = rand() % LENGTH;
	//����ʧ�ܣ�������ɸ���������
	double num_tofind = rand() + (rand() % 10000)*0.0001;

	//printf("˳����ң�\n");
	//printf("���ҳɹ�������£�%.4f  �±꣺%d\n", SequenSearch(arr, len, index),index);
	//SequenSearch2(arr, len, num_tofind);

	//printf("���ֲ��ң�\n");
	//QuickSort(arr, 0, len - 1);
	//Print(arr, len);
	//printf("���ҳɹ�������£�%.4f  �±꣺%d\n", BinarySearch(arr, len, index),index);
	//BinarySearch2(arr, len, num_tofind);

	printf("������������\n");
	BiTree head = InsertBST(arr,len, ;
	for (int i = 1; i < len; i++) {
		InsertBST(head, arr[i]);
	}

	//����ʱ��
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	system("pause");
	return 0;
}