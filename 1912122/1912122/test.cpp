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
	string entrance; //准考证号
	string name; //姓名
	int Pscore; //个人成绩
	static int Tscore; //团队成绩
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
	cout << "准考证号：" << entrance << endl;
	cout << "姓名：" << name << endl;
	cout << "个人成绩：" << Pscore << endl;
	cout << "团队成绩：" << Tscore << endl;
}

int main() {
	Student students[3] = { Student("002", "张三", 88),
		Student("007", "王五",77),
		Student("010", "赵六",66)
	};
	students[0].Print();
	students[1].Print();
	students[2].Print();
	system("pause");
	return 0;
}