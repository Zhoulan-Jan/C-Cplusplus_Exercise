#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

//显示素数
void Prime(int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j == i) {
			/*printf("%d ", i);*/   cout << i<<' ';
		}
	}
}

//冒泡排序
void BubbleSort(int *arr,int len) {
	int flg = 1;
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j]>arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flg = 0;
			}
		}
		if (flg == 1) {
			break;
		}
	}
}

#define NUMSTU 4
#define NUMCOR 3
//二维数组
//输入，
void Intput(int arr[NUMSTU][NUMCOR], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}
//打印输出，
void Print(int arr[NUMSTU][NUMCOR], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//查找，名叫xxx的xx课程成绩
void Search(int arr[NUMSTU][NUMCOR], int row, int col,string names[NUMSTU],string name,int course) {
	int i;
	for (i = 0; i < row; i++){
		if (names[i] == name) {
			break;
		}
	}
	if (i>row) {
		printf("查无此人\n");
	}
	if (course < col){
		printf("%d \n", arr[i][course]);
	}
	else {
		printf("无此成绩\n");
	}
}

//对同一门课程的不同学生成绩排序，
void Sort(int arr[NUMSTU][NUMCOR], int row, int col,int course) {
	//int score1[] = { arr[0][0], arr[1][0], arr[2][0],arr[3][0] };  //如何只取第一排的数字
	int score1[NUMSTU] = { 0 };
	int i;
	for (i = 0; i < row; i++) {
		score1[i] = arr[i][course];
	}
	printf("成绩排序前：");
	for (int i = 0; i < NUMSTU; i++){
		printf("%d ", score1[i]);
	}
	printf("\n");
	BubbleSort(score1, NUMSTU);
	printf("成绩排序后：");
	for (int i = 0; i < NUMSTU; i++){
		printf("%d ", score1[i]);
	}
	printf("\n");
}


int main(){
	//二维数组
	//m4个同学  n3门成绩
	int score[][3] = { { 88, 99, 100 },
						{ 66, 55, 44 }, 
						{ 22, 95, 77 },
						{ 75, 62, 87 } };
	
	//int NumStu = sizeof(score) / sizeof(score[0]);  //输出学生的数量
	//int NumCourse = sizeof(score[0]) / sizeof(score[0][0]);
	//printf("%d \n", NumStu);
	//printf("%d \n", NumCourse);
	string names[4] = { "Peter", "Lisa", "Lora", "Ron" };
	//int score[][NUMCOR] = { 0 };
	//Intput(score, NUMSTU, NUMCOR);
	Print(score, NUMSTU, NUMCOR);
	string name_tofind = "Peter";
	int course_tofind = 2;
	Search(score, NUMSTU, NUMCOR, names, name_tofind, course_tofind);
	int course_tosort = 1;
	Sort(score, NUMSTU, NUMCOR, course_tosort);

	Prime(100);
	printf("\n");

	int array[] = { 4, 5, 8, 9, 6, 7 };
	int len = sizeof(array) / sizeof(array[0]);
	BubbleSort(array, len);
	for (int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}

	system("pause");
	return 0;
}
