#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<math.h>
using namespace std;
//友元
class Point
{
public:
	Point(double xx, double yy){
		x = xx;
		y = yy;
	}
	void Getxy();
	friend double Distance(Point a, Point b);  //是不是为对象的引用均可
private:
	double x, y;
};

void Point::Getxy() {
	cout << x << "," << y << endl;
}

double Distance(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

int  main() {
	Point p1(3.0, 4.0);
	Point p2(6.0, 8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1, p2);
	cout << d << endl;
	system("pause");
	return 0;
}