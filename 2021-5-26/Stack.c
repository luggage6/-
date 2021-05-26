#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int datatype;


typedef struct Stack
{
	datatype *_a;
	int _top; //栈顶
	int _capticy;

}Stack;
//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = (datatype*)malloc(sizeof(datatype)*5);
	pst->_top = 0;
	pst->_capticy = 4;
}
//删除栈
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_capticy = pst->_top = 0;
}
//加入值
void Stackpush(Stack* pst, datatype x)
{
	assert(pst);
	//如果内存不足 就要加内存
	if (pst->_top == pst->_capticy)
	{
		pst->_capticy *= 2;
		datatype* tmp = (datatype*)realloc(pst->_a,  sizeof(datatype)*pst->_capticy);
		if (tmp == NULL)
		{
			printf("内存不足");
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
//删除值
void Stackpop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
		--pst->_top;
}
//求栈的元素个数
int Stacksize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//返回1是空返回0是非空
int Stackempty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}
//获取栈顶的数据
datatype Stacktop(Stack* pst)
{
	return pst->_a[pst->_top]; 
}
int main()
{
	Stack pst;
	StackInit(&pst);
	system("pause");
	return 0;
}