#define _CRT_SECURE_NO_WARNINGS 1

//�û��ݷ���01��������
//1.��������Ľ�ռ�
//2.ȷ�������Ľ�ռ�ṹ �����������Ӽ�����
//3.�Ӹ��ڵ㿪ʼ������������ȵķ�ʽ
//������ռ��֦���ԣ�Լ���������޽纯��

#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iostream>
#include<ctime>
using namespace std;
//�����Ӽ���

//const int num = 5; //��Ʒ����
//int capacity = 10; //��������
//int size[] = { 2, 2, 6, 5, 4 }; //��Ʒ���
//int value[] = { 6, 3, 5, 4, 6 }; //��Ʒ��ֵ

const int num = 100; //��Ʒ����
int capacity; //��������
int size[num]; //��Ʒ���
int value[num]; //��Ʒ��ֵ

int curSize = 0; //��ǰ���
int curValue = 0; //��ǰ��ֵ
int best = 0; //��ǰ���ż�ֵ

//�������100����Ʒ size , value
void BuildArr(int *size, int *value, int len) {
	for (int i = 0; i < len; i++) {
		size[i] = rand() % 10 + 1;
	}
	for (int i = 0; i < len; i++) {
		value[i] = rand() % 10 + 1;
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

//(̰�ģ��޽纯��
int Bound(int i) {
	int cleft = capacity - curSize; //�õ�������ʣ������
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

//���򵥣��޽纯��
int  Bound2(int i) {
	//��ǰ��ֵ + ʣ���ֵ֮��
	int res = curValue;
	int sum = 0; //ʣ���ֵ֮��
	for (; i <= num; i++) {
		sum += value[i];
	}
	res += sum;
	return res;
}

//���ݷ��󱳰�
void Backtrack(int i) {
	if (i > num) {
		best = curValue;
		return;
	}
	if (curSize + size[i] <= capacity) { //����������
		curSize += size[i];
		curValue += value[i];
		Backtrack(i + 1);
		curSize -= size[i];
		curValue -= value[i];
	}
	if (Bound2(i + 1) > best) { //����������
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
	printf("����ֵ��%d ", best);
	system("pause");
	return 0;
}


//class Solution {
//public:
//	//�޽纯��
//	int Bound() {
//
//	}
//	//�����㷨�󱳰�
//	void Backtrack() {
//
//	}
//};

//const int manx = 100;
//int w[manx]; //��Ʒ����
//int v[manx]; //��Ʒ��ֵ
//int x[manx]; //��Ʒѡ�Ͳ�ѡ
//int n, c; //��Ʒ�����ͱ�������
//int Cweight = 0; //������Ʒ��������
//int Cvalue = 0; //������Ʒ���ܼ�ֵ
//int BestValue = 0; //����ֵ
//int Best[manx]; //���Ž�
////��ʼ��
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
////�������
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
////���ݺ���
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

