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
	void Print(student stu);
};

//3名学生初始化
void student::Init() {
	student students[3];
	students[0].AdmissionNum = "001";
	students[0].name = "Peter";
	students[0].score = 88;
	/*teamScore = 85;*/

	students[1].AdmissionNum = "002";
	students[1].name = "Lora";
	students[1].score = 99;

	students[2].AdmissionNum = "003";
	students[2].name = "Peter";
	students[2].score = 79;
}

//信息输出
void student::Print(student stu) {
	cout << "成功！";
	for (int i = 0; i < 3; i++) {
		cout << stu.AdmissionNum << endl;
		cout << stu.name << endl;
		cout << stu.score << endl;
	}
 }

int main() {
	student stu;
	stu.Init();
	stu.Print(stu);
	system("pause");
	return 0;
}