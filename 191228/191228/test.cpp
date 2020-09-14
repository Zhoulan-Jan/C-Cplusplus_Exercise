#define _CRT_SECURE_NO_WARNINGS 1

//用回溯法解01背包问题
//1.定义问题的解空间
//2.确定搜索的解空间结构 （排列数、子集树）
//3.从根节点开始，采用深度优先的方式
//遍历解空间剪枝策略：约束函数、限界函数

#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iostream>
#include<ctime>
using namespace std;
//采用子集树

//const int num = 5; //物品数量
//int capacity = 10; //背包容量
//int size[] = { 2, 2, 6, 5, 4 }; //物品体积
//int value[] = { 6, 3, 5, 4, 6 }; //物品价值

const int num = 100; //物品数量
int capacity; //背包容量
int size[num]; //物品体积
int value[num]; //物品价值

int curSize = 0; //当前体积
int curValue = 0; //当前价值
int best = 0; //当前最优价值

//随机产生100个物品 size , value
void BuildArr(int *size, int *value, int len) {
	for (int i = 0; i < len; i++) {
		size[i] = rand() % 10 + 1;
	}
	for (int i = 0; i < len; i++) {
		value[i] = rand() % 10 + 1;
	}
}
//生成背包容量 物品总量的0.6-0.7
int getCap(int *size, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += size[i];
	}
	return sum * 0.6;
}

//(贪心）限界函数
int Bound(int i) {
	int cleft = capacity - curSize; //得到背包的剩余容量
	int res = curValue;
	while (i <= num && size[i] <= cleft) {
		cleft -= size[i];
		res += value[i];
		i++;
	}
	if (i <= num) {
		res += value[i] * cleft / size[i];
	}
	return res;
}

//（简单）限界函数
int  Bound2(int i) {
	//当前价值 + 剩余价值之和
	int res = curValue;
	int sum = 0; //剩余价值之和
	for (; i <= num; i++) {
		sum += value[i];
	}
	res += sum;
	return res;
}

//回溯法求背包
void Backtrack(int i) {
	if (i > num) {
		best = curValue;
		return;
	}
	if (curSize + size[i] <= capacity) { //进入左子树
		curSize += size[i];
		curValue += value[i];
		Backtrack(i + 1);
		curSize -= size[i];
		curValue -= value[i];
	}
	if (Bound2(i + 1) > best) { //进入右子树
		Backtrack(i + 1);
	}
}

int main() {
	srand((unsigned)time(NULL));
	BuildArr(size, value, num);
	capacity = getCap(size, num);
	clock_t run_start = clock();
	Backtrack(0);
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	printf("最大价值：%d ", best);
	system("pause");
	return 0;
}


//class Solution {
//public:
//	//限界函数
//	int Bound() {
//
//	}
//	//回溯算法求背包
//	void Backtrack() {
//
//	}
//};

//const int manx = 100;
//int w[manx]; //物品质量
//int v[manx]; //物品价值
//int x[manx]; //物品选和不选
//int n, c; //物品个数和背包容量
//int Cweight = 0; //放入物品的总质量
//int Cvalue = 0; //放入物品的总价值
//int BestValue = 0; //最优值
//int Best[manx]; //最优解
////初始化
//void input()
//{
//	cout << "input wu pin number:" << endl;
//	cin >> n;
//	cout << "qing shu ru wu pin de zhong liang he ga zhi: (12 22)" << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> w[i] >> v[i];
//
//	}
//	cout << "qing shu ru bei bao rong liang :" << endl;
//	cin >> c;
//}
////输出函数
//void output()
//{
//	cout << "zui you zhi shi :" << BestValue << endl;
//	cout << "(";
//	for (int i = 1; i <= n; i++)
//	{
//		cout << Best[i] << " ";
//	}
//	cout << ")";
//}
////回溯函数
//void backtrack(int t)
//{
//	if (t>n)
//	{
//		if (Cvalue>BestValue)
//		{
//			BestValue = Cvalue;
//			for (int i = 1; i <= n; i++)
//			{ 
//				Best[i] = x[i];
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i <= 1; i++)
//		{
//			x[t] = i;
//			if (i == 0)
//			{
//				backtrack(t + 1);
//			}
//			else
//			{
//				if (Cweight + w[t] <= c)
//				{
//					Cweight += w[t];
//					Cvalue += v[t];
//					backtrack(t + 1);
//					Cvalue -= v[t];
//					Cweight -= w[t];
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	//input();
//	backtrack(1);
//	output();
//	system("pause");
//	return 0;
//}

