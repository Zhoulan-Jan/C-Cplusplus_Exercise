#define _CRT_SECURE_NO_WARNINGS 1

//用动态规划问题解01背包
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

#define NUM 5

void Print(vector<vector<int>> x);

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

//0 - 1背包问题 输出背包的最大价值和装入物品序号
int max(int x, int y) {
	return x > y ? x : y;
}
int min(int x, int y) {
	return x > y ? y : x;
}

//bit教的动态规划求背包 //从上往下 从左往右
vector<vector<int>> Knapsack(int capacity, int* size, int* value, int n) {
	vector <vector <int>> F;
	const int ROW = n + 1;
	const int COL = capacity + 1;
	F.resize(n+1);
	//初始化全为零
	for (int i = 0; i < ROW; i++) {
		F[i].resize(capacity + 1, 0);
	}
	//状态递推
	for (int i = 1; i < ROW; i++) {  
		for (int j = 1; j < COL; j++) {
			if (size[i - 1] > j) {
				//背包放不下
				F[i][j] = F[i - 1][j];
			}
			else { //放得下 在放与不放中抉择
				F[i][j] = max(F[i - 1][j], F[i - 1][j - size[i - 1]] + value[i - 1]);
			}
		}
	}
	return F;
}

//根据二维状态数组 打印装入的物品序号
void Traceback(vector<vector<int>> F, int num, int capacity, int *size) {
	vector<int> x(F.size(), 0);
	//printf("%d ", F.size()); //F.size = 6;
	//Print(F);
	
	for (int i = F.size() - 1; i > 0; i--) {
		if (F[i][capacity] == F[i - 1][capacity]) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
			capacity -= size[i - 1]; //要非常注意
		}
	}
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == 1) {
			printf("%d ", size[i - 1]);
		}
	}
}


void Print(vector<vector<int>> x, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%2d ", x[i][j]);
		}
		printf("\n");
	}
}

//跳跃点法
//回溯法
//分支限界法


int main(){
	srand((unsigned)time(NULL));

	//固定值
	//int num = 5; //物品数量
	//
	//int capacity = 12; //背包容量
	////capacity = 10;
	//
	//int size[] = {1,3,14,5,2}; //物品重量
	////int size[] = { 2, 2, 6, 5, 4 };
	//
	//int value[] = { 3,5,10,2,2}; //物品价值
	////int value[] = { 6, 3, 5, 4, 6 };

	//随机值
	int num = NUM;
	int size[NUM] = { 0 };
	int value[NUM] = { 0 };
	BuildArr(size, value, num);
	int capacity = getCap(size, num);

	printf("物品数量：%d 背包容量：%d \n", num, capacity);
	printf("物品体积：\n");
	for (int i = 0; i < NUM; i++){
		printf("size: %d ", size[i]);
	}
	
	printf("\n物品价值：\n");

	for (int i = 0; i < NUM; i++){
		printf("valu: %d ", value[i]);
	}

	printf("\n");

	vector<vector<int>> F;
	F.resize(10);
	for (int i = 0; i < 10; i++) {
		F[i].resize(10, 0);
	}

	//动态规划
	F = Knapsack(capacity, size, value, num);
	printf("\n状态递推二维数组:\n");
	Print(F,num + 1, capacity + 1);
	printf("所选择的物品体积：\n");
	Traceback(F, num, capacity, size);
	printf("\n");
	//回溯法

	//分支限界法

	system("pause");
	return 0;
}	