#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main(){
	long num, n;
	scanf("%d", &num);
	n = num;
	for (long i = 2; i < num;){
		if (num%i != 0){
			++i;
			num = n;
		}
		else{
			printf("%d ", i);
			num = num / i;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}