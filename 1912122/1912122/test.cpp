#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(string i, string j, int k);
	~Student();
	void Print();
private:
	string entrance; //׼��֤��
	string name; //����
	int Pscore; //���˳ɼ�
	static int Tscore; //�Ŷӳɼ�
};

Student::Student(string i, string j, int k)
{
	entrance = i;
	name = j;
	Pscore = k;
}

int Student::Tscore = 94;

Student::~Student()
{
}

void Student::Print() {
	cout << "׼��֤�ţ�" << entrance << endl;
	cout << "������" << name << endl;
	cout << "���˳ɼ���" << Pscore << endl;
	cout << "�Ŷӳɼ���" << Tscore << endl;
}

int main() {
	Student students[3] = { Student("002", "����", 88),
		Student("007", "����",77),
		Student("010", "����",66)
	};
	students[0].Print();
	students[1].Print();
	students[2].Print();
	system("pause");
	return 0;
}