#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)
//���ֲ���,һ���������� �������ֵ�����Ƕ���
int main()
{

	int a, b, c, m, t;
	scanf("%d%d", &a, &b);
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	m = a*b;
	c = a%b;
	while(c != 0)
	{
		a = b;
		b = c;
		c = a%b;
	}
	printf("%d", b);
	/*int a[] = { 1,2,3,4,5,6,7,8 };
	int num = 0;
	int n = 0;
	num = sizeof(a) / sizeof(a[0]);
	int start = 0;
	int end = num;
	printf("��Ҫ���ҵ����֣�");
	scanf("%d", &n);
	int sum = 0;
	while(start-end)
	{
		sum = start + end;
		if (a[sum/ 2] < n)
		{
			start = a[sum / 2];
		}
		else if (a[sum / 2]>n)
			end = a[sum/ 2];
		else
			start = sum / 2;
	}
	printf("����������ڵ�λ���ǣ�%d", start);*/
	system("pause");
	return 0;
}