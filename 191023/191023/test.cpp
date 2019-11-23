#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

#define LENGTH 200000

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
	//BiNode(double val) :val(val), rchild(NULL), lchild(NULL){}
}*BiTree,BiTNode;

//建树
BiTree insert(BiTree root, double val) {
	BiTree node = (BiTree)malloc(sizeof(BiTNode));
	node->val = val;
	node->lchild = node->rchild = NULL;
	//空树
	if (!root) {
		root = node;
		return root;
	}
	//找到合适的位置
	BiTree cur = root;
	BiTree parent = NULL;
	while (cur != NULL) {
		if (cur->val == val) {  //树中已有该节点
			return NULL;
		}
		else if (cur->val < val) {
			parent = cur;
			cur = cur->rchild;
		}
		else {
			parent = cur;
			cur = cur->lchild;
		}
	} //循环结束后，cur == NULL
	//将新的结点放到该位置
	if (parent->val < val) {
		parent->rchild = node;
	}
	else {
		parent->lchild = node;
	}
	return root;
}

//查找 成功
double SearchTree(BiTree root, double target) {
	if (root == NULL) {
		return -1;
	}
	BiTree cur = root;
	while (cur != NULL) {
		if (cur->val == target) {
			return cur->val;
		}
		else if (cur->val > target) {
			cur = cur->lchild;
		}
		else {
			cur = cur->rchild;
		}
	}
	return -1;
}

//中序遍历
void PrintTree(BiTree root) {
	if (root == NULL) {
		return;
	}
	PrintTree(root->lchild);
	printf("%.4f  ", root->val);
	PrintTree(root->rchild);
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

	//clock_t run_start = clock();

	//查找成功:随机生成数组大小范围内的一个索引
	int index = rand() % LENGTH;
	//查找失败：随机生成浮点数查找
	double num_tofind = rand() + (rand() % 10000)*0.0001;

	//printf("顺序查找：\n");
	//printf("查找成功的情况下：%.4f  下标：%d\n", SequenSearch(arr, len, index),index);
	//SequenSearch2(arr, len, num_tofind);

	printf("二分查找：\n");
	QuickSort(arr, 0, len - 1);
	//Print(arr, len);
	clock_t run_start = clock();
	printf("查找成功的情况下：%.4f  下标：%d\n", BinarySearch(arr, len, index),index);
	//BinarySearch2(arr, len, num_tofind);

	//printf("二叉搜索树：\n");
	////建立二叉搜索树
	//BiTree root = NULL;
	//for (int i = 0; i < len; i++) {
	//	root = insert(root, arr[i]);
	//}
	////PrintTree(root);  //中序输出二叉搜索树即为排序
	//clock_t run_start = clock();  //建立二叉搜索树会需要很多的时间
	//printf("查找成功的情况下：%.4f  下标：%d\n", SearchTree(root, arr[index]), index);
	////printf("查找不成功！"); SearchTree(root, num_tofind);

	//计算时间
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	system("pause");
	return 0;
}