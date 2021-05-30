#pragma once
typedef int HPdatatype;
#include<stdio.h>

void Swap(HPdatatype* a, HPdatatype* b)
{
	HPdatatype* tmp;
	tmp = a;
	a = b;
	b = tmp;
}
typedef struct Heap
{
	HPdatatype* _a;
	int _size;//�ڲ����ݴ�С
	int _capacity;//���ÿռ�Ĵ�С
}Heap;

//������������С��
void adjustdown(HPdatatype* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//����
	while (child<n)
	{
		//�ҳ�С�ĺ���
		if (child+1<n&&a[child + 1] < a[child])
		{
			++child;
		}
		//������״��ں��ӣ�Ҫ���н���
		if (a[parent]>a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//��ʼ��
void heapinit(Heap* php, HPdatatype *a, int n)
{
	php->_a = (HPdatatype*)malloc(sizeof(HPdatatype)*n);
	memcpy(php->_a, a, sizeof(HPdatatype)*n);
	php->_size = n;
	php->_capacity = n;

	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		adjustdown(php->_a, php->_size, i);
	}

}
//ɾ��
void heapdestory(Heap* php);
//������
void heappush(Heap* php, HPdatatype x);
//ɾ����
void Heappop(Heap *php);