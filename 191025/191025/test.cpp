#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
//
//������̵ķ�ʽ��д
////Բ����Ӿ��
//#define pi 3.14
//double *Price(int radius) {
//	double *result = (double *)malloc(sizeof(double)*2);
//	double area = pi*(radius + 3)*(radius + 3) - pi*(radius)*(radius);
//	double peri = 2 * pi*(radius + 3);
//	result[0] = area * 20;
//	result[1] = peri * 35;
//	return result;
//}
//int main() {
//	double *ans = Price(3);
//	printf("%f\n", ans[0]);
//	printf("%f\n", ans[1]);
//	system("pause");
//	return 0;
//}

//�������ķ�ʽ��д
class pool{
public:
	//�õ��뾶����
	void getRadius();
	//դ���ܼ�
	double getFenceTotal();
	//�����ܼ�
	double getAisleTotal();
private:
	int aisle = 3; // �������
	int radius; //��Ӿ�ؿ��
	int fencePri = 35;//դ���۸�
	int aislePri = 20;//�������
};

void pool::getRadius() {
	cout<< "��������Ӿ�صİ뾶��";
	cin >> radius;
}

double pool::getFenceTotal() {
	return 2 * 3.14*(radius + aisle)*fencePri;
}

double pool::getAisleTotal() {
	double x = (3.14*(radius + 3)*(radius + 3) - 3.14*(radius*radius));
	return x*aislePri;
}

int main() {
	pool p;
	p.getRadius();
	printf("�����ļ۸�Ϊ��%f \n", p.getAisleTotal());
	printf("դ���ļ۸�Ϊ��%f \n", p.getFenceTotal());
	system("pause");
	return 0;
}