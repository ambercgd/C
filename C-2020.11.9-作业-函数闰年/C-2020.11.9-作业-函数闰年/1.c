#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int is_leap(int n){
	if ((n % 400 == 0)|| ((n % 4 == 0)&& ((n % 100) != 0))){
		return 1;
	}
	return 0;
}
int main(){
	int i = 0;
	printf("������һ��������֣�");
	scanf("%d", &i);
	int m = is_leap(i);
	if (m == 1){
		printf("�������������\n");
	}
	else{
		printf("������Ĳ�������\n");
	}
	system("pause");
	return 0;
}