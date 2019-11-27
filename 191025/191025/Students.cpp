#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

//学生类
class student {
private:
	string AdmissionNum;
	string name;
	int score;
	static int teamScore;
public:
	void Init();
	void Print();
};

//3名学生初始化
void student::Init(student students[]) {
	//student students[3];
	students[0].AdmissionNum = "001";
	students[0].name = "Peter";
	students[0].score = 88;
	/*teamScore = 85;*/

	students[1].AdmissionNum = "002";
	students[1].name = "Lora";
	students[1].score = 99;

	students[2].AdmissionNum = "003";
	students[2].name = "Ron";
	students[2].score = 79;
}

//信息输出
void student::Print(student stu) {
	for (int i = 0; i < 3; i++) {
		cout << stu.AdmissionNum << endl;
		cout << stu.name << endl;
		cout << stu.score << endl;
	}
	cout << "成功！";
 }

int main() {
	student stu[3];
	stu.Init(stu);
	stu.Print(stu);
	system("pause");
	return 0;
}

//#include<iostream>
//using namespace std;
//class student
//{
//public:
//	student()
//	{
//
//	}
//	void print();
//	void input()//输入学生信息
//	{
//		cin >> name >> id >> grade;
//	}
//private:
//	string name;
//	string id;
//	double grade;
//};
//void student::print()
//{
//	cout << "name : " << name << ",  id : " << id << ",  grade  : " << grade << endl;
//}
//int main()
//{
//
//	//student stu[3]={student("1","2",3),student("1","2",6),student("1","2",9)};
//	student stu[3];
//	for (int i = 0; i<3; i++)//输入三个学生信息
//	{
//		stu[i].input();
//	}
//	for (int i = 0; i<3; i++)//输出三个学生信息
//	{
//		stu[i].print();
//	}
//	return 0;
//}