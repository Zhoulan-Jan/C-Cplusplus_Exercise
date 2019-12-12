#define _CRT_SECURE_NO_WARNINGS 1

#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main() {
	//文件输出流 向流中添加数据
	//1.创建一个文件输出流对象，通过构造函数指定磁盘文件名
	//1.1打开某个写文件
	ofstream ostrm("f1.txt");
	//2.通过文件输出流对象，写入若干行文字
	ostrm << "钢铁侠" << endl;
	ostrm << "绯红女巫" << endl;
	//3.关闭文件输出流对象，然后观察磁盘文件内容
	ostrm.close();

	//1.2使用open函数创建文件输出流 追加内容
	ofstream ostrm2;
	ostrm2.open("f1.txt",ios::app);
	ostrm2 << "美国队长" << endl;
	ostrm2 << "黑寡妇" << endl;
	ostrm2 << "绿巨人" << endl;
	ostrm2.close();

	//文件输入流 从流中获取数据
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