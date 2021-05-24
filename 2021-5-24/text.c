#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//实现一个函数，判断一个数是不是素数。
//利用上面实现的函数打印100到200之间的素数。
void Sushu()
{
	for (int i = 100; 1 <= 200;++i)

}
int main()
{
	Sushu();
	system("pause");
	return 0;
}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//int IsRotate(char*str, char*sub)
//{
//	assert(*str != NULL);
//	assert(*sub != NULL);
//	if (strlen(str) != strlen(sub)) 
//		return 0;
//	char*tmp = (char*)malloc(sizeof(char)*strlen(str) * 2 + 1);
//	strcat(tmp, str);    
//	char*res = strstr(tmp, sub);
//	free(tmp);
//	return 1;
//}
//int main()
//{
//	char*str = "HelloBity";
//	char*sub = "Bityhello";
//	int flag = IsRotate(str, sub);
//	if (flag)
//		printf("True");
//	else
//		printf("False");
//	return 0;
//}
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
//#define ROW 3
//#define COL 4
//	int Find(int arr[ROW][COL], int *row, int *col, int n)
//	{
//			*row = 0;
//			*col = COL - 1;
//			while ((*row < ROW) && (*col >= 0))
//			{
//				if (arr[*row][*col] > n)
//				{
//					(*col)--;
//				}
//				else if (arr[*row][*col] < n)
//				{
//					(*row)++;
//				}
//				else
//					return 1;
//			}
//			return 0;
//	}
//	int main()
//	{
//		int arr[ROW][COL] = { { 1, 2, 3, 4 }, { 5, 7, 9, 10 }, { 21, 37, 46, 98 } };
//		int input = 0;
//		int row = 0;
//		int col = 0;
//		printf("请输入一个整数：");
//		scanf("%d", &input);
//		int ret = Find(arr, &row, &col, input);
//		if (ret == 1)
//		{
//			printf("row = %d,col = %d\n", row, col);
//		}
//		else
//		{
//			printf("Not found\n");
//		}
//void bubbleSort1(int *arr, int n)
//{
//	int m, i, j;
//	for (i = 0; i<n - 1; i++)
//	for (j = 0; j<n - 1 - i; j++)
//	if (arr[j]>arr[j + 1])
//	{
//		m = arr[j];
//		arr[j] = arr[j + 1];
//		arr[j + 1] = m;
//	}
//}
//void bubbleSort2(int *arr, int n)
//{
//	int m, i, j;
//	for (i = 0; i<n - 1; i++)
//	for (j = 0; j<n - 1 - i; j++)
//	if (arr[j]<arr[j + 1])
//	{
//		m = arr[j];
//		arr[j] = arr[j + 1];
//		arr[j + 1] = m;
//	}
//}
//int a[10] = { 1, 2, 3, 4, 8, 79, 5, 45, 5, 45 };
//for (int i = 0; i < 10; i++)
//	printf("%d", a[i]);
//printf("请输入<或者>\n");
//char c = '0';
//scanf("%c", c);
//if (c == '<')
//{
//	bubbleSort2(a[10], 10);
//}
//if (c == '>')
//{
//	bubbleSort1(a[10], 10);
//}



