#pragma once
typedef int HPdatatype;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//堆的建立  (小堆） 堆就是为了快速的找出来最小值
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
		if (child + 1<n&&a[child + 1] < a[child])
			//大堆
			//if (child+1<n&&a[child + 1] > a[child])
		{
			++child;
		}
		//如果父亲大于孩子，要进行交换
		if (a[parent]>a[child])
			//大堆
			//if (a[parent]<a[child])
		{
			Swap(&a[child], &a[parent]);
			//给下一步做准备
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//向上调整
void adjustup(HPdatatype *a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
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

}

//构建堆
void heapsmall(Heap* php, HPdatatype *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		adjustdown(php->_a, php->_size, i);
	}
}


//排序
void heapnext(Heap* php, HPdatatype *a, int n)
{
	heapsmall(&php, php->_a, n);
	int end = n - 1;
	while (end)
	{
		Swap(&a[end], &a[0]);
		adjustdown(php->_a, php->_size, php->_size - 1);
		--end;
	}
}

//删除
void heapdestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_capacity = NULL;
	php->_size = NULL;
}
//插入数
void heappush(Heap* php, HPdatatype x)
{
	assert(php);
	int end = php->_size;
	if (php->_size = php->_capacity)
	{
		php->_capacity *= 2;
		HPdatatype* tmp = (HPdatatype*)realloc(php->_a, sizeof(HPdatatype)*php->_capacity);
		php->_size = tmp;
	}
	php->_a[php->_size++] = x;

	adjustup(php->_a, php->_size, php->_size - 1);
}
//删除数
void Heappop(Heap *php)
{
	assert(php);
	swap(&php->_a[0], &php->_a[php->_size]);
	php->_size--;
	adjustdown(php->_a, php->_size, 0);
}

int main()
{
	Heap php;
	heapinit(&php, (&php)->_a, 8);


	//可在这里加入上面的对堆进行的处理
	system("pause");
	return 0;
}


//做topk求出一组数据中的最大k个数
void Swap(int* a, int* b)
{
	int* tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void adjustdown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child<n)
	{
		//找出小的孩子
		if (child + 1<n&&a[child + 1] < a[child])
			//大堆
			//if (child+1<n&&a[child + 1] > a[child])
		{
			++child;
		}
		//如果父亲大于孩子，要进行交换
		if (a[parent]>a[child])
			//大堆
			//if (a[parent]<a[child])
		{
			Swap(&a[child], &a[parent]);
			//给下一步做准备
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	*returnSize = k;
	if (k == 0)
	{
		return NULL;
	}
	//存放的是最小的k个数字
	int* ret = (int*)malloc(sizeof(int)*k);
	//键前k个大堆
	for (int i = 0; i<k; i++)
	{
		ret[i] = arr[i];
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		adjustdown(ret, k, i);
	}
	for (int j = k; j<arrSize; j++)
	{
		if (arr[j]<ret[0])
		{
			ret[0] = arr[j];
			adjustdown(ret, k, 0);
		}
	}
	return ret;
}