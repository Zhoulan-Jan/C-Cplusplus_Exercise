#define _CRT_SECURE_NO_WARNINGS 1

#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main() {
	//�ļ������ �������������
	//1.����һ���ļ����������ͨ�����캯��ָ�������ļ���
	//1.1��ĳ��д�ļ�
	ofstream ostrm("f1.txt");
	//2.ͨ���ļ����������д������������
	ostrm << "������" << endl;
	ostrm << "糺�Ů��" << endl;
	//3.�ر��ļ����������Ȼ��۲�����ļ�����
	ostrm.close();

	//1.2ʹ��open���������ļ������ ׷������
	ofstream ostrm2;
	ostrm2.open("f1.txt",ios::app);
	ostrm2 << "�����ӳ�" << endl;
	ostrm2 << "�ڹѸ�" << endl;
	ostrm2 << "�̾���" << endl;
	ostrm2.close();

	//�ļ������� �����л�ȡ����
	ifstream istrm("f1.txt");
	char s[80];
	while (!istrm.eof()){
		istrm.getline(s, sizeof(s));
		cout << s << endl;
	}
	istrm.close();
	system("pause");
	return 0;
}