//��ջʵ�ֶ���
//����������ջ�����ж��е�ʵ�֣�һ��ջ��ר��д�����ݣ�һ��ջ���������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ջ������
//1.����к���ȳ�������ĺ���
typedef int datatype;


typedef struct Stack
{
	datatype *_a;
	int _top; //ջ��
	int _capticy;

}Stack;
//��ʼ��
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (datatype*)malloc(sizeof(datatype)* 5);
	pst->_top = 0;
	pst->_capticy = 4;
}
//ɾ��ջ
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_capticy = pst->_top = 0;
}
//����ֵ
void Stackpush(Stack* pst, datatype x)
{
	assert(pst);
	//����ڴ治�� ��Ҫ���ڴ�
	if (pst->_top == pst->_capticy)
	{
		pst->_capticy *= 2;
		datatype* tmp = (datatype*)realloc(pst->_a, sizeof(datatype)*pst->_capticy);
		if (tmp == NULL)
		{
			printf("�ڴ治��");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}
//ɾ��ֵ
void Stackpop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	--pst->_top;
}
//��ջ��Ԫ�ظ���
int Stacksize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//����1�ǿշ���0�Ƿǿ�
int Stackempty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}
//��ȡջ��������
datatype Stacktop(Stack* pst)
{
	return pst->_a[pst->_top];
}


//���еĶ���
typedef struct
{
	Stack push;
	Stack pop;
}myqueue;

myqueue* myqueueCreate()
{
	myqueue* q = (myqueue*)malloc(sizeof(myqueue));
	StackInit(&q->push);
	StackInit(&q->pop);
}

void myqueuepush(myqueue* obj, int x)
{
	Stackpush(&obj->push, x);
}


int myQueuePop(myqueue* obj)
{
	int front = myqueuepeek(obj);
	Stackpop(&obj->pop);
	return front;
}

int myQueuePop(myqueue* obj)
{
	if (Stackempty(&obj->pop))
	{
		return Stacktop(&obj->pop);
	}
	else
	{
		while (!Stackempty(&obj->push))
		{
			Stackpush(&obj->pop, Stacktop(&obj->push));
			Stackpop(&obj->push);
		}
	}
	return Stacktop(&obj->pop);
}
 