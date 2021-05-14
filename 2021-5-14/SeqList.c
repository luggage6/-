#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef int hh;
typedef int Datatype;
//建立一个顺序表
typedef struct Seqlist
{
	Datatype* a;
	int size;//有效数据的个数
	int capecity;//有效数据的个数
}SL;

//给你一个数组和一个数值，删去数组中数值为既定数值的数
int removement(int *a, int val, int numsize)
{
	int src = 0;
	int dst = 0;
	while (src<=numsize)
	{
		if (a[src] == val)
		{
			src++;
		}
		else
		{
			a[dst] = a[src];
			++src;
			dst++;
		}
		numsize++;
	}
	return *a;
}

//数组形式的整数加法 其中asize就是数组a中的元素个数，b同于a
int addplus(int *a, int asize,int *b,int bsize)

{
	int len = asize > bsize ? asize : bsize;
	//这一步是建立出来一个空间比他们两个其中最大的空间大1
	int *reArr = (int*)malloc(sizeof(int)*(len+1));
	int ai = asize - 1;
	int bi = bsize - 1;
	int reti = 0;
	int nextnum = 0;
	while (len--)
	{
		//这是不知道其中两个哪个数组的数值比较多所以害怕其中会有数组越界加的判断，如果越界就取0
		int aq = 0;
		if (ai >= 0)
		{
			aq = a[ai];
			ai--;
		}
		int bq = 0;
		if (bi >= 0)
		{
			bq = b[bi];
			bi--;
		}
		
		int ret = aq + bq+nextnum;
		if (ret > 9)
		{
			ret -= 10;
			nextnum = 1;
		}
		else
		{
			nextnum = 0;
		}
		//现在是逆置输出，一会得逆置回来
		reArr[reti] = ret;
		ret++;
	}
	//逆置函数
	int right = 0, left = reti - 1;
	while (right < left)
	{
		int temp;
		temp = reArr[right];
		reArr[right] = reArr[left];
		reArr[left] = temp;
		++right;
		--left;
	}
	return reArr; 
}



int main()
{
	int a[5] = { 1, 2, 3, 4, 3 };

	system("pause");
	return 0;
}