#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;


//0 - 1�������� �������������ֵ��װ����Ʒ���
int max(int x, int y) {
	return x > y ? x : y;
}
int min(int x, int y) {
	return x > y ? y : x;
}
//��̬�滮 ���ϴ��� �������� ��������
//void Knapsack(int* v, int* w, int c, int n, int **m) {
//	int jMax = min(w[n] - 1, c);
//	for (int j = 0; j < jMax; j++) {
//		m[n][j] = 0;
//	}
//	for (int j = w[n]; j < c; j++) {
//		m[n][j] = v[n];
//	}
//	for (int i = n - 1; i > 0; i--) {
//		jMax = min(w[i] - 1, c);
//		for (int j = 0; j < jMax; j++) {
//			m[i][j] = m[i + 1][j];
//		}
//		for (int j = w[i]; j < c; j++) {
//			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
//		}
//	}
//	m[1][c] = m[2][c];
//	if (c >= w[1]){
//		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
//	}
//}
//
//void Traceback(int **m, int* w, int c, int n, int* x){
//	for (int i = 0; i < n; i++) {
//		if (m[i][c] == m[i + 1][c]){
//			x[i] = 0;
//		}
//		else {
//			x[i] = 1;
//			c -= w[i];
//		}
//		x[n] = (m[n][c]) ? 1 : 0;
//	}
//}



//bit�̵Ķ�̬�滮�󱳰�
//�������� ��������
int Knapsack(int capacity, int* weight, int* value, int n) {
	vector <vector <int>> F;
	const int ROW = n + 1;
	const int COL = capacity + 1;
	F.resize(ROW);
	//��ʼ��ȫΪ��
	for (int i = 0; i < ROW; i++) {
		F[i].resize(COL, 0);
	}
	//״̬����
	for (int i = 1; i < ROW; i++) {  
		for (int j = 1; j < COL; j++) {
			if (weight[i - 1] > j) {
				//�����Ų���
				F[i][j] = F[i - 1][j];
			}
			else { //�ŵ��� �ڷ��벻���о���
				F[i][j] = max(F[i - 1][j], F[i - 1][j - weight[i - 1]] + value[i - 1]);
			}
		}
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("%2d  ", F[i][j]);
		}
		printf("\n");
	}
	//Traceback(F, n, capacity, weight);
	return F[ROW - 1][COL - 1];
}

//���ݶ�ά״̬���� ��ӡװ����Ʒ���
void Traceback(vector<vector<int>> F, int num, int capacity, int *weight) {
	const int NUM = num;
	vector<int> x(NUM, 0);
	for (int i = num; i > 0; i--) {
		if (F[i][capacity] == F[i - 1][capacity]) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
			capacity -= weight[i];
		}
	}
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == 1) {
			printf("%d \n", x[i]);
		}
	}
}


void print(int m[][10]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", m[i][j]);
		}
	}
}
//��Ծ�㷨
//���ݷ�
//��֧�޽編


int main(){
	
	int num = 5; //��Ʒ����
	
	int capacity = 12; //��������
	
	int weight[] = {1,3,14,5,2}; //��Ʒ����
	
	int value[] = { 3,5,10,2,2}; //��Ʒ��ֵ

	//m�洢
	int m[][10] = { 0 };
	int x[5];

	//��̬�滮
	printf("%d ",Knapsack(capacity, weight, value, num));

	//Knapsack(v, w, c, n, (int **)m);
	//Traceback((int **)m, w, c, n, x);
	//print(m);

	//���ݷ�

	//��֧�޽編

	system("pause");
	return 0;
}	