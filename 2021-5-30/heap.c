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
	int _size;//内部数据大小
	int _capacity;//所用空间的大小
}Heap;

//左右子树都是小堆
void adjustdown(HPdatatype* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child<n)
	{
		//找出小的孩子
		if (child+1<n&&a[child + 1] < a[child])
		{
			++child;
		}
		//如果父亲大于孩子，要进行交换
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
//初始化
void heapinit(Heap* php, HPdatatype *a, int n)
{
	php->_a = (HPdatatype*)malloc(sizeof(HPdatatype)*n);
	memcpy(php->_a, a, sizeof(HPdatatype)*n);
	php->_size = n;
	php->_capacity = n;

	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		adjustdown(php->_a, php->_size, i);
	}

}
//删除
void heapdestory(Heap* php);
//插入数
void heappush(Heap* php, HPdatatype x);
//删除数
void Heappop(Heap *php);