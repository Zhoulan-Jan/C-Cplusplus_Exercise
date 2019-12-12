#define _CRT_SECURE_NO_WARNINGS 1

//�麯��
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

class Circle
{
public:
	Circle(int i);
	~Circle();
	virtual double area() = 0;
	virtual double volume()=0;
	int radius;
};

Circle::Circle(int i)
{
	radius = i;
}

Circle::~Circle()
{
}

//����
class Sphere : public Circle //Ҫ���м̳�
{
public:
	Sphere(int i);
	~Sphere();
	virtual double area(){
		return 4 * 3.14*radius *radius;
	}
	virtual double volume(){
		return 1.333333*3.14*radius*radius*radius;
	}
};

Sphere::Sphere(int i) : Circle(i)
{
}

Sphere::~Sphere()
{
}

//Բ����
class Column :public Circle 
{
public:
	Column(int i, int j);
	~Column();
	virtual double area(){
		return 2 * 3.14*radius*radius + 2 * 3.14*radius*h;
	}
	virtual double volume(){
		return 3.14*radius*radius*h;
	}
	int h; //Բ����ĸ�
};

Column::Column(int i, int j) : Circle(i)
{
	h = j;
}

Column::~Column()
{
}

//��ӡ����
void Print(Circle &s) {
	cout << "�������" << s.area() << endl;
	cout << "�����" << s.volume() << endl;
}

int main() {
	Sphere sphere(5);
	Column column(6, 7);
	Circle &pa = sphere; //Ҫ�ø����ָ�������ָ���������
	Circle &pb = column;
	Print(pa);
	Print(pb);
	system("pause");
	return 0;
}