#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�滻�ո�->%20
char* ReplaceBlank(char *str){
	//ɨ����ո������ �õ��µ��ַ�������
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
	//��ָ��ָ���ַ�������ָ��ָ���ַ���
	int pNew = newLen ;
	int pOld = originLen ;  //��Ҫ��һ
	//�Ӻ���ǰ�滻
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