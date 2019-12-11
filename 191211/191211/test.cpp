#define _CRT_SECURE_NO_WARNINGS 1

//�̳��Ժ�������
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
	string address; //��ַ
	int floor; //¥��
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
	int room; //����
	int area; //���
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
	string name; //�칫������
	string telephone; //�绰����
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
	House house("�㽭ʡ̨����", 118, 256, 125);
	Office office("����ʡ������", 205, "���ʴ�", "18226541122");
	house.print();
	office.print();
	system("pause");
	return 0;
}