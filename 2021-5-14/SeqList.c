#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef int hh;
typedef int Datatype;
//����һ��˳���
typedef struct Seqlist
{
	Datatype* a;
	int size;//��Ч���ݵĸ���
	int capecity;//��Ч���ݵĸ���
}SL;

//����һ�������һ����ֵ��ɾȥ��������ֵΪ�ȶ���ֵ����
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

//������ʽ�������ӷ� ����asize��������a�е�Ԫ�ظ�����bͬ��a
int addplus(int *a, int asize,int *b,int bsize)

{
	int len = asize > bsize ? asize : bsize;
	//��һ���ǽ�������һ���ռ�����������������Ŀռ��1
	int *reArr = (int*)malloc(sizeof(int)*(len+1));
	int ai = asize - 1;
	int bi = bsize - 1;
	int reti = 0;
	int nextnum = 0;
	while (len--)
	{
		//���ǲ�֪�����������ĸ��������ֵ�Ƚ϶����Ժ������л�������Խ��ӵ��жϣ����Խ���ȡ0
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
		//���������������һ������û���
		reArr[reti] = ret;
		ret++;
	}
	//���ú���
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