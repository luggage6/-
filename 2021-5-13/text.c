#include"SeqListNode.h" 


int main()
{
	//����һ��ͷָ�� ��ʼ��ΪNULL
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