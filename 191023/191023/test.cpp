#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

#define LENGTH 20

//四位小数 二十 二百 二千 二万 二十万 二百万
//相等 不能用 ==
void BuildArr(double *arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = rand() + rand() % 10000 * 0.0001;
	}
}

//顺序查找
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
	printf("查找不成功！");
	return -1;
}

//快速排序 +二分查找 
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
	printf("查找不成功！");
	return -1;
}

//二分搜索树 二叉排序树
typedef struct BiNode{
	double val; 
	BiNode *rchild;
	BiNode *lchild;
	BiNode(double val) :val(val), rchild(NULL), lchild(NULL){}
}*BiTree,BiTNode;

//搜索
//BiTree SearchBST(BiTree T, double key, BiTree f, BiTree p) {
//	if (!T) {
//		p = f;
//		return false;
//	}
//	else if (key - T->val > 0.1) {  //在右子树搜索
//		return SearchBST(T->rchild, key, T, p);
//	} 
//	else if (key - T->val < 0.1) {
//		return SearchBST(T->lchild, key, T, p);
//	}
//	else {
//		p = T;
//	}
//}

//建树
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

//打印数组
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

	//查找成功:随机生成数组大小范围内的一个索引
	int index = rand() % LENGTH;
	//查找失败：随机生成浮点数查找
	double num_tofind = rand() + (rand() % 10000)*0.0001;

	//printf("顺序查找：\n");
	//printf("查找成功的情况下：%.4f  下标：%d\n", SequenSearch(arr, len, index),index);
	//SequenSearch2(arr, len, num_tofind);

	//printf("二分查找：\n");
	//QuickSort(arr, 0, len - 1);
	//Print(arr, len);
	//printf("查找成功的情况下：%.4f  下标：%d\n", BinarySearch(arr, len, index),index);
	//BinarySearch2(arr, len, num_tofind);

	printf("二叉搜索树：\n");
	BiTree head = InsertBST(arr,len, ;
	for (int i = 1; i < len; i++) {
		InsertBST(head, arr[i]);
	}

	//计算时间
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	system("pause");
	return 0;
}