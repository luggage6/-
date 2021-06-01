#pragma once
typedef int HPdatatype;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//�ѵĽ���  (С�ѣ� �Ѿ���Ϊ�˿��ٵ��ҳ�����Сֵ
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
		if (child + 1<n&&a[child + 1] < a[child])
			//���
			//if (child+1<n&&a[child + 1] > a[child])
		{
			++child;
		}
		//������״��ں��ӣ�Ҫ���н���
		if (a[parent]>a[child])
			//���
			//if (a[parent]<a[child])
		{
			Swap(&a[child], &a[parent]);
			//����һ����׼��
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//���ϵ���
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
//��ʼ��
void heapinit(Heap* php, HPdatatype *a, int n)
{
	php->_a = (HPdatatype*)malloc(sizeof(HPdatatype)*n);
	memcpy(php->_a, a, sizeof(HPdatatype)*n);
	php->_size = n;
	php->_capacity = n;

}

//������
void heapsmall(Heap* php, HPdatatype *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		adjustdown(php->_a, php->_size, i);
	}
}


//����
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

//ɾ��
void heapdestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_capacity = NULL;
	php->_size = NULL;
}
//������
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
//ɾ����
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


	//���������������ĶԶѽ��еĴ���
	system("pause");
	return 0;
}


//��topk���һ�������е����k����
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
	int child = parent * 2 + 1;//����
	while (child<n)
	{
		//�ҳ�С�ĺ���
		if (child + 1<n&&a[child + 1] < a[child])
			//���
			//if (child+1<n&&a[child + 1] > a[child])
		{
			++child;
		}
		//������״��ں��ӣ�Ҫ���н���
		if (a[parent]>a[child])
			//���
			//if (a[parent]<a[child])
		{
			Swap(&a[child], &a[parent]);
			//����һ����׼��
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
	//��ŵ�����С��k������
	int* ret = (int*)malloc(sizeof(int)*k);
	//��ǰk�����
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