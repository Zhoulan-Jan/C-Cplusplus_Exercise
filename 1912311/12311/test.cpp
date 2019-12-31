#define _CRT_SECURE_NO_WARNINGS 1

//���ݷ� ���������ۻ�Ա����

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

const int num = 8; //���и���
int x[num+1]; //��ǰ��
int bestx[num + 1] = { 0 }; //��ǰ���Ž� 
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
							{0,951,900,266,0,230,0,707,0} };//���е��ڽӾ���//0��ʾ�ޱ�
int curCost = 0; //��ǰ����
int bestc = 63335; //��ǰ����ֵ

/*
�㷨�Ƿ���ڴӳ���x[n-1]������x[n]�ıߺʹӳ���x[n]��x[1]�ıߣ�
��������ڣ����ҵ�һ�������ۻ�Ա�Ļ�·�ж�������·�ķ����Ƿ���
�����ҵ��ĵ�ǰ���Ż�·����
*/
void Backtrack(int t) {
	int i;
	if (t == num)                                                         //��ǰ��չ�������������Ҷ���ĸ����
	{
		if (a[x[num - 1]][x[num]] != 0 && a[x[num]][x[1]] != 0 &&
			(bestc == 0 || curCost + a[x[num - 1]][x[num]] + a[x[num]][1] < bestc))
		{
			bestc = curCost + a[x[num - 1]][x[num]] + a[x[num]][1];                     //���µ�ǰ���Ž�bestc
			for (i = 1; i <= num; i++)                                    //���µ�ǰ���Ž�bestx
				bestx[i] = x[i];
		}
		return;
	}
	//�ɷ����x[j]����
	for (i = t; i <= num; i++)
	if (a[x[t - 1]][x[i]] != 0 && (bestc == 0 ||   //����Ƿ����һ���ӳ���x[i-1]������x[j]�ı�
		curCost + a[x[t - 1]][x[i]] < bestc))    //�жϴӸ���㵽��ǰ������㴦�Ĳ�������·�ߵķ���
		//�Ƿ�С�ڵ�ǰ�ҵ�����С��������·��
	{
		//�������Լ���������޽纯�����������Ե�ǰ�������Ϊ��������
		swap(x[t], x[i]);
		curCost += a[x[t - 1]][x[t]];
		Backtrack(t + 1);
		curCost -= a[x[t - 1]][x[t]];                          //���ݻ�ԭ
		swap(x[t], x[i]);
	}
}

int main() {
	//���ú�����������ǰҪ������x��ʼ��Ϊ{1,2,n}
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

	printf("���·����%d \n", bestc);
	printf("·��Ϊ��");
	for (int i = 1; i <= num; i++) {
		cout << bestx[i]<<" " ;
	} 
	cout << bestx[1] << endl;
	system("pause");
	return 0;
}
