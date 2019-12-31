#define _CRT_SECURE_NO_WARNINGS 1

//��֧�޽編���������ۻ�Ա����

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
							{ 0, 951, 900, 266, 0, 230, 0, 707, 0 } };//���е��ڽӾ���//0��ʾ�ޱ�
int curCost = 0; //��ǰ����
int bestc = 63335; //��ǰ����ֵ ��С����
int bestx[num + 1] = { 0 };

template<class T>
class HeapNode{
public:
	int lcost; //�������õ��½�
	T curCost; //��ǰ����
	int rcost; //������С���ú�
	int s; //���ڵ㵽��ǰ����·��
	int *x; //��Ҫ��һ�������Ķ�����x[s+1:n-1]
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

	MinSum = 0; //��С���߷��ú�                                            
	MinOut = new int[num + 1];  //����MinOut[i]=����i����С���߷���                               
	for (i = 1; i <= num; i++)
	{
		MinOut[i] = 0;
		for (j = 1; j <= num; j++)
		if (a[i][j] != 0 && (a[i][j] < MinOut[i] || MinOut[i] == 0))
			MinOut[i] = a[i][j];
		if (MinOut[i] == 0)  //�޻�·                           
			return -1;
		MinSum += MinOut[i];
	}
	//��ʼ��
	E.s = 0;
	E.curCost = 0;
	E.rcost = MinSum;
	E.x = new int[num];
	for (i = 0; i < num; i++)
		E.x[i] = i + 1;
	bestc = 0;
	//�������пռ���
	while (E.s < num - 1)  //��Ҷ���                                      
	{
		if (E.s == num - 2)  //��ǰ��չ�����Ҷ���ĸ���� �ټ�2���߹��ɻ�·                                    
		{  //�����ɻ�·�Ƿ����ڵ�ǰ���Ž�                                                 
			if (a[E.x[num - 2]][E.x[num - 1]] != 0 && a[E.x[num - 1]][1] != 0 &&
				(E.curCost + a[E.x[num - 2]][E.x[num - 1]] + a[E.x[num - 1]][1] < bestc || bestc == 0))
			{
				//���ø�С��·
				bestc = E.curCost + a[E.x[num - 2]][E.x[num - 1]] + a[E.x[num - 1]][1];
				E.curCost = bestc;
				E.lcost = bestc;
				E.s++;
				pq.push(E);
			}
			else
				delete[]E.x;  //������չ���                             
		}
		else //������ǰ��չ�����ӽ��                                               
		{
			for (i = E.s + 1; i < num; i++)
			if (a[E.x[E.s]][E.x[i]] != 0)
			{
				//���ж��ӽ��
				cc = E.curCost + a[E.x[E.s]][E.x[i]]; //��ǰ����       
				rcost = E.rcost - MinOut[E.x[E.s]]; //������С���߷��ú�  
  				b = cc + rcost;  //�½�                       
				if (b < bestc || bestc == 0)  //�������ܺ����Ž� ��������С��      
				{
					N.s = E.s + 1;
					N.curCost = cc;
					N.lcost = b;
					N.rcost = rcost;
					N.x = new int[num];
					for (j = 0; j < num; j++)
						N.x[j] = E.x[j];
					N.x[E.s + 1] = E.x[i];  //����µ�·��              
					N.x[i] = E.x[E.s + 1];
					pq.push(N); //�������ȶ���                        
				}
			}

			delete[]E.x; //��ɽ����չ                                  
		}
		if (pq.empty())  //���ѿ�                                    
			break;
		E = pq.top();  //ȡ��һ��չ���                                     
		pq.pop();
	}

	if (bestc == 0)  //�޻�·                                   
		return -1;
	for (i = 0; i < num; i++)  //�����Ž⸴�Ƶ�v[1:n]                                
		bestx[i + 1] = E.x[i];
	while (pq.size())  //�ͷ���С�������н��                                      
	{
		E = pq.top();
		pq.pop();
		delete[]E.x;
	}

	return bestc;
}

int main() {
	clock_t run_start = clock();
	printf("���·����%d \n", BBTSP());
	clock_t run_end = clock();
	printf("·��Ϊ��");
	for (int i = 1; i <= num; i++) {
		cout << bestx[i] << " ";
	}
	cout << bestx[1] << endl;
	double runtime = ((double)run_end - (double)run_start) / CLOCKS_PER_SEC;
	printf("Run Time: %.3f s \n", runtime);
	system("pause");
	return 0;
}