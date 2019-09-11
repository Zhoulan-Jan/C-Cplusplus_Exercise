#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//替换空格->%20
char* ReplaceBlank(char *str){
	//扫描出空格的数量 得到新的字符串长度
	char *p = str;
	int originLen = 0;
	int blank=0;
	while (*p != NULL){
		originLen++;
		if (*p == ' '){
			blank++;
		}
		p++;
	}
	int newLen = blank * 2 + originLen;
	//新指针指新字符串，旧指针指旧字符串
	int pNew = newLen ;
	int pOld = originLen ;  //不要减一
	//从后往前替换
	str[pNew] = '\0';
	while (pOld != 0){
		if (str[pOld] == ' '){
			pOld--;
			str[pNew--] = '0';
			str[pNew--] = '2';
			str[pNew--] = '%';
		}
		else{
			str[pNew--] = str[pOld--];
		}
	}

	return str;
}

int main(){
	char str[] = "we are students";
	//ReplaceBlank(str);
	printf("%s ", ReplaceBlank(str));
	system("pause");
	return 0;
}