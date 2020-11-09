#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int is_prime(int n){
		for (int j = 2; j<=sqrt(n) ; j++){
			if (n%j == 0){
				return 0;
			}
	}
		return 1;
}
int main(){
	for (int i = 100; i < 200; i++){
		int m=is_prime(i);
		if (m == 1){
			printf("%d\n", i);
		}
		}
	system("pause");
	return 0;
}