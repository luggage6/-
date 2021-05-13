#include"SeqListNode.h"

// 动态申请一个节点
 SListNode* BuySListNode(SLDatatype x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("这个结点建立失败");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// 单链表打印
void SListPrint(SListNode * phead)
{
	SListNode *cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
		
	}
}
// 创建一个新的结点
/*void CreatNode(SListNode * newnode)
{
	newnode = (SListNode *)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("这个结点建立失败");
		exit(-1);
	}
}*/
// 单链表尾插
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
		//这个是求出这个链表的结尾
		while (tail->next!=NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	

}
// 单链表的头插
void SListPushFront(SListNode** phead, SLDatatype x)
{
	SListNode * newnode;
	newnode = (SListNode *)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("这个结点建立失败");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = *phead;
}
// 单链表的尾删
void SListPopBack(SListNode** phead)
{
	//1.空
	if (*phead==NULL)
	{
		return;
	}
	//2.一个结点
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	//3.多个结点
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
// 单链表头删
void SListPopFront(SListNode** pplist);
