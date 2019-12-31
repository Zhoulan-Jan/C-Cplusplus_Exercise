#define _CRT_SECURE_NO_WARNINGS 1

//回溯法 解旅行商售货员问题

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

const int num = 8; //城市个数
int x[num+1]; //当前解
int bestx[num + 1] = { 0 }; //当前最优解 
/*int a[num + 1][num + 1] = { {0,0,0,0,0},
					{ 0,0, 30, 6, 4 },
					{ 0,30, 0, 5, 10 },
					{ 0,6, 5, 0, 20 },
					{ 0,4, 10, 20, 0 } }; */
int a[num + 1][num + 1] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
							{0,0,888,1223,0,0,564,779,951},
							{0,888,0,1062,0,0,0,1325,900},
							{0,1223,1062,0,0,164,0,0,266},
							{0,0,0,0,0,1036,978,569,0},
							{0,0,0,164,1036,0,1312,732,230},
							{0,564,0,0,978,1312,0,0,0},
							{0,779,1325,0,569,732,0,0,707},
							{0,951,900,266,0,230,0,707,0} };//城市的邻接矩阵//0表示无边
int curCost = 0; //当前花费
int bestc = 63335; //当前最优值

/*
算法是否存在从城市x[n-1]到城市x[n]的边和从城市x[n]到x[1]的边，
如果都存在，则找到一条旅行售货员的回路判断这条回路的费用是否优
于已找到的当前最优回路费用
*/
void Backtrack(int t) {
	int i;
	if (t == num)                                                         //当前扩展结点是排列数的叶结点的父结点
	{
		if (a[x[num - 1]][x[num]] != 0 && a[x[num]][x[1]] != 0 &&
			(bestc == 0 || curCost + a[x[num - 1]][x[num]] + a[x[num]][1] < bestc))
		{
			bestc = curCost + a[x[num - 1]][x[num]] + a[x[num]][1];                     //更新当前最优解bestc
			for (i = 1; i <= num; i++)                                    //更新当前最优解bestx
				bestx[i] = x[i];
		}
		return;
	}
	//可否进入x[j]子树
	for (i = t; i <= num; i++)
	if (a[x[t - 1]][x[i]] != 0 && (bestc == 0 ||   //检测是否存在一条从城市x[i-1]到城市x[j]的边
		curCost + a[x[t - 1]][x[i]] < bestc))    //判断从根结点到当前搜索结点处的部分周游路线的费用
		//是否小于当前找到的最小费用周游路线
	{
		//如果满足约束函数和限界函数，则搜索以当前搜索结点为根的子树
		swap(x[t], x[i]);
		curCost += a[x[t - 1]][x[t]];
		Backtrack(t + 1);
		curCost -= a[x[t - 1]][x[t]];                          //回溯还原
		swap(x[t], x[i]);
	}
}

int main() {
	//调用函数回溯搜索前要将数组x初始化为{1,2,n}
	for (int i = 1; i <= num; i++) {
		x[i] = i;
	}
	clock_t run_start = clock();
	Backtrack(2);
	clock_t run_end = clock();
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}

	printf("最短路径：%d \n", bestc);
	printf("路线为：");
	for (int i = 1; i <= num; i++) {
		cout << bestx[i]<<" " ;
	} 
	cout << bestx[1] << endl;
	system("pause");
	return 0;
}
