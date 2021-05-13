#include"SeqListNode.h"

// ��̬����һ���ڵ�
 SListNode* BuySListNode(SLDatatype x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("�����㽨��ʧ��");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// �������ӡ
void SListPrint(SListNode * phead)
{
	SListNode *cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
		
	}
}
// ����һ���µĽ��
/*void CreatNode(SListNode * newnode)
{
	newnode = (SListNode *)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("�����㽨��ʧ��");
		exit(-1);
	}
}*/
// ������β��
void SListPushBack(SListNode ** phead, SLDatatype x)
{
	SListNode* newnode = BuySListNode(x);
	if (*phead == NULL)
	{	
		*phead = newnode;
	}
	else
	{
		SListNode * tail = *phead;
		//���������������Ľ�β
		while (tail->next!=NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	

}
// �������ͷ��
void SListPushFront(SListNode** phead, SLDatatype x)
{
	SListNode * newnode;
	newnode = (SListNode *)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("�����㽨��ʧ��");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = *phead;
}
// �������βɾ
void SListPopBack(SListNode** phead)
{
	//1.��
	if (*phead==NULL)
	{
		return;
	}
	//2.һ�����
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//3.������
	else
	{
		SListNode* tail = *phead;
		SListNode* prev = *phead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist);
