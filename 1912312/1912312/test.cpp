#define _CRT_SECURE_NO_WARNINGS 1

//分支限界法求旅行商售货员问题

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<iostream>
using namespace std;

const int num = 8; 
//int a[num + 1][num + 1] = { { 0, 0, 0, 0, 0 },
//							{ 0, 0, 30, 6, 4 },
//							{ 0, 30, 0, 5, 10 },
//							{ 0, 6, 5, 0, 20 },
//							{ 0, 4, 10, 20, 0 } };
int a[num + 1][num + 1] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
							{ 0, 0, 888, 1223, 0, 0, 564, 779, 951 },
							{ 0, 888, 0, 1062, 0, 0, 0, 1325, 900 },
							{ 0, 1223, 1062, 0, 0, 164, 0, 0, 266 },
							{ 0, 0, 0, 0, 0, 1036, 978, 569, 0 },
							{ 0, 0, 0, 164, 1036, 0, 1312, 732, 230 },
							{ 0, 564, 0, 0, 978, 1312, 0, 0, 0 },
							{ 0, 779, 1325, 0, 569, 732, 0, 0, 707 },
							{ 0, 951, 900, 266, 0, 230, 0, 707, 0 } };//城市的邻接矩阵//0表示无边
int curCost = 0; //当前花费
int bestc = 63335; //当前最优值 最小费用
int bestx[num + 1] = { 0 };

template<class T>
class HeapNode{
public:
	int lcost; //子树费用的下界
	T curCost; //当前费用
	int rcost; //顶点最小费用和
	int s; //根节点到当前结点的路径
	int *x; //需要进一步搜索的顶点是x[s+1:n-1]
	bool operator < (const HeapNode &MH) const
	{
		return lcost > MH.lcost;
	}
};

int BBTSP() {
	priority_queue<HeapNode<int> > pq;
	HeapNode<int> E, N;
	int bestc, cc, rcost, MinSum, *MinOut, b;
	int i, j;

	MinSum = 0; //最小出边费用和                                            
	MinOut = new int[num + 1];  //计算MinOut[i]=顶点i的最小出边费用                               
	for (i = 1; i <= num; i++)
	{
		MinOut[i] = 0;
		for (j = 1; j <= num; j++)
		if (a[i][j] != 0 && (a[i][j] < MinOut[i] || MinOut[i] == 0))
			MinOut[i] = a[i][j];
		if (MinOut[i] == 0)  //无回路                           
			return -1;
		MinSum += MinOut[i];
	}
	//初始化
	E.s = 0;
	E.curCost = 0;
	E.rcost = MinSum;
	E.x = new int[num];
	for (i = 0; i < num; i++)
		E.x[i] = i + 1;
	bestc = 0;
	//搜索排列空间树
	while (E.s < num - 1)  //非叶结点                                      
	{
		if (E.s == num - 2)  //当前扩展结点是叶结点的父结点 再加2条边构成回路                                    
		{  //所构成回路是否优于当前最优解                                                 
			if (a[E.x[num - 2]][E.x[num - 1]] != 0 && a[E.x[num - 1]][1] != 0 &&
				(E.curCost + a[E.x[num - 2]][E.x[num - 1]] + a[E.x[num - 1]][1] < bestc || bestc == 0))
			{
				//费用更小的路
				bestc = E.curCost + a[E.x[num - 2]][E.x[num - 1]] + a[E.x[num - 1]][1];
				E.curCost = bestc;
				E.lcost = bestc;
				E.s++;
				pq.push(E);
			}
			else
				delete[]E.x;  //舍弃扩展结点                             
		}
		else //产生当前扩展结点儿子结点                                               
		{
			for (i = E.s + 1; i < num; i++)
			if (a[E.x[E.s]][E.x[i]] != 0)
			{
				//可行儿子结点
				cc = E.curCost + a[E.x[E.s]][E.x[i]]; //当前费用       
				rcost = E.rcost - MinOut[E.x[E.s]]; //更新最小出边费用和  
  				b = cc + rcost;  //下界                       
				if (b < bestc || bestc == 0)  //子树可能含最优解 结点插入最小堆      
				{
					N.s = E.s + 1;
					N.curCost = cc;
					N.lcost = b;
					N.rcost = rcost;
					N.x = new int[num];
					for (j = 0; j < num; j++)
						N.x[j] = E.x[j];
					N.x[E.s + 1] = E.x[i];  //获得新的路径              
					N.x[i] = E.x[E.s + 1];
					pq.push(N); //加入优先队列                        
				}
			}

			delete[]E.x; //完成结点扩展                                  
		}
		if (pq.empty())  //堆已空                                    
			break;
		E = pq.top();  //取下一扩展结点                                     
		pq.pop();
	}

	if (bestc == 0)  //无回路                                   
		return -1;
	for (i = 0; i < num; i++)  //将最优解复制到v[1:n]                                
		bestx[i + 1] = E.x[i];
	while (pq.size())  //释放最小堆中所有结点                                      
	{
		E = pq.top();
		pq.pop();
		delete[]E.x;
	}

	return bestc;
}

int main() {
	clock_t run_start = clock();
	printf("最短路径：%d \n", BBTSP());
	clock_t run_end = clock();
	printf("路线为：");
	for (int i = 1; i <= num; i++) {
		cout << bestx[i] << " ";
	}
	cout << bestx[1] << endl;
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	system("pause");
	return 0;
}