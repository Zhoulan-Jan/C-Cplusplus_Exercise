#define _CRT_SECURE_NO_WARNINGS 1

//�÷�֧�޽編�ⱳ������

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
using namespace std;

//�Ӽ����Ľ��
class bbnode {
public:
	bbnode * parent;
	bool LChild;
};

//����ѵĽ��
template<class T1,class T2>
class HeapNode {
public:
	int upValue; //���ļ�ֵ�Ͻ�
	T1 value; //���ļ�ֵ
	T2 size; //���Ĵ�С
	int level; //���Ĳ���
	bbnode * ptr; //���Ӽ�������Ӧ����ָ��
	bool operator < (const HeapNode &H) const
	{
		return upValue<H.upValue;
	}
};

//const int num = 5; //��Ʒ����
//int capacity = 10; //��������
//int size[] = { 2, 2, 6, 5, 4 }; //��Ʒ���
//int value[] = { 6, 3, 5, 4, 6 }; //��Ʒ��ֵ

const int num = 100; //��Ʒ����
int capacity; //��������
int size[num]; //��Ʒ���
int value[num]; //��Ʒ��ֵ

int curSize = 0; //��ǰ���
int curValue = 0; //��ǰ��ֵ
int best = 0; //��ǰ���ż�ֵ

bbnode *extend; //ָ����չ����ָ��
int* bestx; //���Ž�
priority_queue<HeapNode<int, int>> H; //���ȶ���

//�������100����Ʒ size , value
void BuildArr(int *size, int *value, int len) {
	for (int i = 0; i < len; i++) {
		size[i] = rand() % 10 + 1;
	}
	for (int i = 0; i < len; i++) {
		value[i] = rand() % 10 + 1;
	}
}

//���ɱ������� ��Ʒ������0.6-0.7
int getCap(int *size, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += size[i];
	}
	return sum * 0.6;
}

//�򵥰���޽纯��
int Bound(int i) {
	int res = curValue;
	int sum = 0;
	for (; i <= num; i++) {
		sum += value[i];
	}
	res += sum;
	return res;
}

//��һ��������뵽�Ӽ��������ȶ�����
void AddLiveNode(int upValue, int curValue, int curSize, bool ch, int lev) {
	bbnode *newNode = new bbnode;
	newNode->parent = extend;
	newNode->LChild = ch;

	HeapNode<int, int> N;
	N.upValue = upValue;
	N.value = curValue;
	N.size = curSize;
	N.level = lev;
	N.ptr = newNode;
	H.push(N);
}

//���ȶ��з�֧�޽編
int MaxKnapsack() {
	H = priority_queue<HeapNode<int, int>>();
	int i = 0;
	extend = 0;
	curSize = curValue = 0;
	bestx = new int[num + 2];
	int bestValue = 0; //��ǰ����ֵ
	int up = Bound(1); //�����Ͻ�
	//�����Ӽ��ռ���
	while (i != num) {
		if (curSize + size[i] <= capacity) {
			if (curValue + value[i] > bestValue) {
				bestValue = curValue + value[i];
			}
			AddLiveNode(up, curValue + value[i], curSize + size[i], true, i + 1);
		}
		int up = Bound(i + 1);
		if (Bound(i + 1) >= bestValue) {
			AddLiveNode(up, curValue, curSize, false, i + 1);
		}
		HeapNode<int, int> N;
		N = H.top();
		H.pop();
		extend = N.ptr;
		curSize = N.size;
		curValue = N.value;
		up = N.upValue;
		i = N.level;
	}
	//���쵱ǰ���Ž�
	for (int j = num - 1; j >= 0; j--) {
		bestx[j] = extend->LChild;
		extend = extend->parent;
		//printf("%d ", extend->LChild);
		//extend = extend->parent;
	}
	return curValue;
}

int main() {
	srand((unsigned)time(NULL));
	BuildArr(size, value, num);
	capacity = getCap(size, num);
	clock_t run_start = clock();
	printf("����ֵΪ��%d \n", MaxKnapsack());
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);

	printf(" ��Ʒ�����Ϊ��");
	for (int i = 0; i < num; i++) {
		printf("%d ", size[i]);
	}
	printf("\n ��Ʒ�ļ�ֵΪ��");
	for (int i = 0; i < num; i++) {
		printf("%d ", value[i]);
	}
	printf("\n1��ʾ�Ÿ���Ʒ��");
	for (int i = 0; i < num; i++) {
		printf("%d ", bestx[i]);
	}
	system("pause");
	return 0;
}