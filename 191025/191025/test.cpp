#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
//
//面向过程的方式书写
////圆形游泳池
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

//面向对象的方式书写
class pool{
public:
	//得到半径长度
	void getRadius();
	//栅栏总价
	double getFenceTotal();
	//过道总价
	double getAisleTotal();
private:
	int aisle = 3; // 过道宽度
	int radius; //游泳池宽度
	int fencePri = 35;//栅栏价格
	int aislePri = 20;//过道造价
};

void pool::getRadius() {
	cout<< "请输入游泳池的半径：";
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
	printf("过道的价格为：%f \n", p.getAisleTotal());
	printf("栅栏的价格为：%f \n", p.getFenceTotal());
	system("pause");
	return 0;
}