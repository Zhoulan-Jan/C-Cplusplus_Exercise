#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//判断一个数是否是2^k
int IsPowTow(int n){
	for (int i = 1; i <= n; i<<=1){
		if (i == n) return 1;
	}
	return 0;
}

//二进制1的个数只有一个的话，就是2^k
int IsPowTow2(int n){
	int cnt = 0;
	while (n){
		n = n&(n - 1);
		cnt++;
	}
	if (cnt == 1) return 1;
	else return 0;
}

//删除字符串的空格 首尾删除 中间留一个空格 
void DelBlank(char *str){
	int i = 0;
	int j = 0;
	int flg = 0; //未处理
	while (str[i] != '\0'){
		if (str[i] != ' ' && !flg){
			str[j++] = str[i++];
			flg = 1;
		}
		else if (str[i] != ' ' && flg){
			str[j++] = str[i++];
		}
		else if (str[i] == ' '&& !flg){
			i++;
		}
		else if (str[i] == ' ' && flg){
			str[j++] = str[i++];
			flg = 0;
		}
	}
	if (str[j-1] == ' '){
		str[j-1] = '\0';
	}
	else str[j] = '\0';
}

//字符串压缩

int main(){
	printf("%d\n", IsPowTow(32));
	printf("%d\n", IsPowTow(31));
	printf("%d\n", IsPowTow2(32)); 
	printf("%d\n", IsPowTow2(31)); 
	char string[] = "   asd  rf g     d  ";
	DelBlank(string);
	printf("%s\n", string);
	system("pause");
	return 0;
}

