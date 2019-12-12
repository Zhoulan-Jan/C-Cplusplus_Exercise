#define _CRT_SECURE_NO_WARNINGS 1

//虚函数
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

//球体
class Sphere : public Circle //要公有继承
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

//圆柱体
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
	int h; //圆柱体的高
};

Column::Column(int i, int j) : Circle(i)
{
	h = j;
}

Column::~Column()
{
}

//打印函数
void Print(Circle &s) {
	cout << "表面积：" << s.area() << endl;
	cout << "体积：" << s.volume() << endl;
}

int main() {
	Sphere sphere(5);
	Column column(6, 7);
	Circle &pa = sphere; //要用父类的指针或引用指向子类对象
	Circle &pb = column;
	Print(pa);
	Print(pb);
	system("pause");
	return 0;
}