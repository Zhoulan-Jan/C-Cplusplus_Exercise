#define _CRT_SECURE_NO_WARNINGS 1

//运算符重载
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;


//重载为类
class MyString
{
public:
	MyString(char *p);
	MyString();
	~MyString();
	MyString operator +(const MyString &s);
	void print();
private:
	char* str;
	int len;
};

MyString::MyString(char *p)
{
	str = p;
}

MyString::MyString()
{
	str = NULL;
}

MyString::~MyString()
{
}

inline MyString MyString::operator + (const MyString &s) {
	/*return MyString(strcat(str, s.str));*/
	MyString str3;
	str3.len = len + s.len;
	str3.str = new char[str3.len + 1];
	strcpy(str3.str, str);
	strcat(str3.str,s.str);
	return str3;
}

void MyString::print() {
	cout << str << endl;
}

//重载为友元函数
class MyString2
{
public:
	MyString2(char * p);
	MyString2();
	~MyString2();
	friend	MyString2 operator + (const MyString2 &s1, const MyString2 &s2);
	void print();
private:
	char *str;
	int len;
};

MyString2::MyString2(char * p)
{
	str = p;
}

MyString2::MyString2(){
	str = NULL;
}

MyString2::~MyString2()
{
}

MyString2 operator + (const MyString2 &s1, const MyString2 &s2) {
	MyString2 str3;
	str3.len = s1.len + s2.len;
	str3.str = new char[str3.len + 1];
	strcpy(str3.str, s1.str);
	strcat(str3.str, s2.str);
	return str3;
}

void MyString2::print() {
	cout << str << endl;	
}

int main() {
	MyString str1("hello ");
	MyString str2("world");
	MyString str3 = str1 + str2;
	str3.print();

	MyString2 str4("harry ");
	MyString2 str5("potter");
	MyString2 str6 = str4 + str5;
	str6.print();

	system("pause");
	return 0;
}

