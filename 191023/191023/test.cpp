#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

#define LENGTH 200000

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
	//BiNode(double val) :val(val), rchild(NULL), lchild(NULL){}
}*BiTree,BiTNode;

//����
BiTree insert(BiTree root, double val) {
	BiTree node = (BiTree)malloc(sizeof(BiTNode));
	node->val = val;
	node->lchild = node->rchild = NULL;
	//����
	if (!root) {
		root = node;
		return root;
	}
	//�ҵ����ʵ�λ��
	BiTree cur = root;
	BiTree parent = NULL;
	while (cur != NULL) {
		if (cur->val == val) {  //�������иýڵ�
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
	} //ѭ��������cur == NULL
	//���µĽ��ŵ���λ��
	if (parent->val < val) {
		parent->rchild = node;
	}
	else {
		parent->lchild = node;
	}
	return root;
}

//���� �ɹ�
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

//�������
void PrintTree(BiTree root) {
	if (root == NULL) {
		return;
	}
	PrintTree(root->lchild);
	printf("%.4f  ", root->val);
	PrintTree(root->rchild);
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

	//clock_t run_start = clock();

	//���ҳɹ�:������������С��Χ�ڵ�һ������
	int index = rand() % LENGTH;
	//����ʧ�ܣ�������ɸ���������
	double num_tofind = rand() + (rand() % 10000)*0.0001;

	//printf("˳����ң�\n");
	//printf("���ҳɹ�������£�%.4f  �±꣺%d\n", SequenSearch(arr, len, index),index);
	//SequenSearch2(arr, len, num_tofind);

	printf("���ֲ��ң�\n");
	QuickSort(arr, 0, len - 1);
	//Print(arr, len);
	clock_t run_start = clock();
	printf("���ҳɹ�������£�%.4f  �±꣺%d\n", BinarySearch(arr, len, index),index);
	//BinarySearch2(arr, len, num_tofind);

	//printf("������������\n");
	////��������������
	//BiTree root = NULL;
	//for (int i = 0; i < len; i++) {
	//	root = insert(root, arr[i]);
	//}
	////PrintTree(root);  //�������������������Ϊ����
	//clock_t run_start = clock();  //������������������Ҫ�ܶ��ʱ��
	//printf("���ҳɹ�������£�%.4f  �±꣺%d\n", SearchTree(root, arr[index]), index);
	////printf("���Ҳ��ɹ���"); SearchTree(root, num_tofind);

	//����ʱ��
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	system("pause");
	return 0;
}