#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

//0 - 1背包问题
int max(int x, int y) {
	return x > y ? x : y;
}
int min(int x, int y) {
	return x > y ? y : x;
}
//动态规划
void Knapsack(int* v, int* w, int c, int n, int **m) {
	int jMax = min(w[n] - 1, c);
	for (int j = 0; j < jMax; j++) {
		m[n][j] = 0;
	}
	for (int j = w[n]; j < c; j++) {
		m[n][j] = v[n];
	}
	for (int i = n - 1; i > 0; i--) {
		jMax = min(w[i] - 1, c);
		for (int j = 0; j < jMax; j++) {
			m[i][j] = m[i + 1][j];
		}
		for (int j = w[i]; j < c; j++) {
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}
	}
	m[1][c] = m[2][c];
	if (c >= w[1]){
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
	}
}

void Traceback(int **m, int* w, int c, int n, int* x){
	for (int i = 0; i < n; i++) {
		if (m[i][c] == m[i + 1][c]){
			x[i] = 0;
		}
		else {
			x[i] = 1;
			c -= w[i];
		}
		x[n] = (m[n][c]) ? 1 : 0;
	}
}

void print(int m[][10]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", m[i][j]);
		}
	}
}
//跳跃点法
//回溯法
//分支限界法


int main(){
	//物品数量
	int n = 5;
	//背包容量
	int c = 10;
	//物品重量
	int w[] = { 2, 2, 6, 5, 4 };
	//物品价值
	int v[] = { 6, 3, 5, 4, 6 };
	//m存储
	int m[][10] = { 0 };
	int x[5];
	Knapsack(v, w, c, n, (int **)m);
	Traceback((int **)m, w, c, n, x);
	print(m);
	system("pause");
	return 0;
}	