#include"Seqlist.h"
#define N 4

void SeqListInit(SL* p)// ˳����ʼ��
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

void SeqListPushBack(SL* p, Datatype x)//˳���β��
{
	assert(p);//�ж����p�ǲ��ǿ�ָ�룬����ǵĻ�ֱ�ӽ���
	//���������Ҫ����
	if (p->size >= p->capecity)
	{
		p->capecity *= 2;
		p->a = (Datatype*)realloc(p->a, sizeof(Datatype)*p->capecity);
	}
 	p->a[p->size] = x;
	p->size++;
}

void SeqListPrint(SL* p)//˳����ӡ
{
	int end = p->size - 1;
	for (int i = 0; i <= end; i++)
		printf(" %d", p->a[i]);
	printf("\n");
}
void SeqListPopBack(SL* p)// ˳���βɾ
{
	assert(p);
	p->size--;
}

void SeqListPushFront(SL* p, Datatype x)//˳���ͷ��
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

void SeqListPopFront(SL* p)// ˳���ͷɾ
{
	assert(p);
	int end = p->size - 1;
	for (int i = 1; i <= end;i++)
	{
		p->a[i-1] = p->a[i];
	}
	p->size--;

}