#include"SeqListNode.h" 


int main()
{
	//定义一个头指针 初始化为NULL
	SListNode * phead=NULL;
	/*SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);*/
	SListPushBack( &phead,  1);
	SListPushBack( &phead,  2);
	SListPushBack( &phead,  3);
	SListPopBack(&phead);
	SListPrint(phead);

	system("pause");
	return 0;
}