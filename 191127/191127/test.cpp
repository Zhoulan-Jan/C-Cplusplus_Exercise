#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

#define NUM 5

void Print(vector<vector<int>> x);

//�������100����Ʒ size , value
void BuildArr(int *size, int *value, int len) {
	for (int i = 0; i < len; i++) {
		size[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < len; i++) {
		value[i] = rand() % 100 + 1;
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
vector<vector<int>> Knapsack(int capacity, int* size, int* value, int n) {
	vector <vector <int>> F;
	const int ROW = n + 1;
	const int COL = capacity + 1;
	F.resize(n+1);
	//��ʼ��ȫΪ��
	for (int i = 0; i < ROW; i++) {
		F[i].resize(COL, 0);
	}
	//״̬����
	for (int i = 1; i < ROW; i++) {  
		for (int j = 1; j < COL; j++) {
			if (size[i - 1] > j) {
				//�����Ų���
				F[i][j] = F[i - 1][j];
			}
			else { //�ŵ��� �ڷ��벻���о���
				F[i][j] = max(F[i - 1][j], F[i - 1][j - size[i - 1]] + value[i - 1]);
			}
		}
	}
	return F;
}

//���ݶ�ά״̬���� ��ӡװ�����Ʒ���
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
			capacity -= size[i - 1]; //Ҫ�ǳ�ע��
		}
	}
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == 1) {
			printf("%d ", size[i - 1]);
		}
	}
}


void Print(vector<vector<int>> x) {
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x[i].size(); j++) {
			printf("%2d ", x[i][j]);
		}
		printf("\n");
	}
}

//��Ծ�㷨
//���ݷ�
//��֧�޽編


int main(){
	srand((unsigned)time(NULL));

	//�̶�ֵ
	int num = 5; //��Ʒ����
	
	int capacity = 12; //��������
	//capacity = 10;
	
	int size[] = {1,3,14,5,2}; //��Ʒ����
	//int size[] = { 2, 2, 6, 5, 4 };
	
	int value[] = { 3,5,10,2,2}; //��Ʒ��ֵ
	//int value[] = { 6, 3, 5, 4, 6 };

	//���ֵ
	//int num = NUM;
	//int size[NUM];
	//int value[NUM];
	//BuildArr(size, value, NUM);
	//int capacity = getCap(size, NUM);

	//printf("%d %d ", num, capacity);
	//for (int i = 0; i < NUM; i++){
	//	printf("size: %d \n", size[i]);
	//	printf("value: %d \n", value[i]);
	//}

	//m�洢
	int m[][10] = { 0 };
	int x[5];

	vector<vector<int>> F;
	F.resize(num + 1);
	for (int i = 0; i < num+1; i++) {
		F[i].resize(capacity+1, 0);
	}

	//��̬�滮
	F = Knapsack(capacity, size, value, num);
	printf("״̬���ƶ�ά����\n");
	Print(F);
	Traceback(F, num, capacity, size);

	//���ݷ�

	//��֧�޽編

	system("pause");
	return 0;
}	