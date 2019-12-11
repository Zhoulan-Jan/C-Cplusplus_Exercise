#define _CRT_SECURE_NO_WARNINGS 1

//继承性和派生类
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

class Building
{
public:
	Building(string add, int num);
	~Building();
	void print();
private:
	string address; //地址
	int floor; //楼号
};

Building::Building(string i, int j)
{
	address = i;
	floor = j;
}

void Building::print() {
	cout << "address " << address << "  ";
	cout << "floor " << floor;
	cout << endl;
}

Building::~Building()
{
}

class House : public Building
{
public:
	House(string i,int j,int k, int l);
	~House();
	void print();
private:
	int room; //房号
	int area; //面积
};

House::House(string i, int j, int k, int l) :Building(i, j)
{
	room = k;
	area = l;
}

void House::print() {
	Building::print();
	cout << "room " << room << "  ";
	cout << "area " << area;
	cout << endl;
}

House::~House()
{
}

class Office : public Building
{
public:
	Office(string i, int j, string k, string l);
	~Office();
	void print();
private:
	string name; //办公室名称
	string telephone; //电话号码
};

Office::Office(string i, int j, string k, string l) :Building(i, j)
{
	name = k;
	telephone = l;
}

void Office::print() {
	Building::print();
	cout << "name " << name <<"  ";
	cout << "telephone " << telephone;
	cout << endl;
}

Office::~Office()
{
}

int main() {
	House house("浙江省台州市", 118, 256, 125);
	Office office("陕西省西安市", 205, "国际处", "18226541122");
	house.print();
	office.print();
	system("pause");
	return 0;
}