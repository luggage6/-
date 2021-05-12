#include"Seqlist.h"
#define N 4

void SeqListInit(SL* p)// 顺序表初始化
{
	p->a = (Datatype*)malloc(sizeof(Datatype)* N);
	if ((p->a == NULL))
	{

		printf("this pragram is error!");
		exit(-1);
	}
	p->size = 0;
	p->capecity = N;
}

void SeqListPushBack(SL* p, Datatype x)//顺序表尾插
{
	assert(p);//判断这个p是不是空指针，如果是的话直接结束
	//如果满了需要增容
	if (p->size >= p->capecity)
	{
		p->capecity *= 2;
		p->a = (Datatype*)realloc(p->a, sizeof(Datatype)*p->capecity);
	}
 	p->a[p->size] = x;
	p->size++;
}

void SeqListPrint(SL* p)//顺序表打印
{
	int end = p->size - 1;
	for (int i = 0; i <= end; i++)
		printf(" %d", p->a[i]);
	printf("\n");
}
void SeqListPopBack(SL* p)// 顺序表尾删
{
	assert(p);
	p->size--;
}

void SeqListPushFront(SL* p, Datatype x)//顺序表头插
{
	assert(p);
	int end = p->size-1;
	for (int i = end; i >=0; i--)
	{
		p->a[i+1] = p->a[i];
	}
	p->a[0] = x;
	p->size++;
}

void SeqListPopFront(SL* p)// 顺序表头删
{
	assert(p);
	int end = p->size - 1;
	for (int i = 1; i <= end;i++)
	{
		p->a[i-1] = p->a[i];
	}
	p->size--;

}