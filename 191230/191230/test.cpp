#define _CRT_SECURE_NO_WARNINGS 1

//用分支限界法解背包问题

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//子集树的结点
class bbnode {
public:
	bbnode * parent;
	bool LChild;
};

//大根堆的结点
template<class T1,class T2>
class HeapNode {
public:
	int upValue; //结点的价值上界
	T1 value; //结点的价值
	T2 size; //结点的大小
	int level; //结点的层数
	bbnode * ptr; //在子集树中相应结点的指针
	bool operator < (const HeapNode &H) const
	{
		return upValue<H.upValue;
	}
};

const int num = 5; //物品数量
int capacity = 10; //背包容量
int size[] = { 2, 2, 6, 5, 4 }; //物品体积
int value[] = { 6, 3, 5, 4, 6 }; //物品价值

int curSize = 0; //当前体积
int curValue = 0; //当前价值
int best = 0; //当前最优价值

bbnode *extend; //指向扩展结点的指针
int* bestx; //最优解
priority_queue<HeapNode<int, int>> H; //优先队列

//简单版的限界函数
int Bound(int i) {
	int res = curValue;
	int sum = 0;
	for (; i <= num; i++) {
		sum += value[i];
	}
	res += sum;
	return res;
}

//将一个活结点加入到子集树和优先队列中
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

//优先队列分支限界法
int MaxKnapsack() {
	H = priority_queue<HeapNode<int, int>>();
	int i = 0;
	extend = 0;
	curSize = curValue = 0;
	bestx = new int[num + 2];
	int bestValue = 0; //当前最优值
	int up = Bound(1); //计算上界
	//搜索子集空间树
	while (i != num + 1) {
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
	//构造当前最优解
	//for (int j = num; j > 0; j++) {
	//	//bestx[j] = extend->LChild;
	//	//extend = extend->parent;
	//	printf("%d ", bestx[j]);
	//}
	return curValue;
}

int main() {
	printf("%d ", MaxKnapsack());
	system("pause");
	return 0;
}