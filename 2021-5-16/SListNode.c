#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#pragma warning (disable:4996)

typedef int SLDatatype;
//结点
typedef struct SListNode
{
	SLDatatype data;
	struct SListNode* next;
}SListNode;


//反转链表（迭代或者递归）
SListNode* Relistnode(SListNode* phead)
{
	//建立一个空链表
	if (phead == NULL || phead->next==NULL)
	{
		return phead;
	}
	SListNode* n1 = NULL, *n2 = phead, *n3 = phead->next;
	while (n2)
	{
		//反转
		n2->next = n1;
		//递归
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
		return n1;
	}
}

  //头插做法
SListNode* Relistnode(SListNode* phead)
{
	SListNode* cur = phead, *next = cur->next, *pst = NULL;
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->next = NULL;
	while (next == NULL)
	{
		cur->next = newnode;
		newnode = cur;
		cur = next;
		next = cur->next;
	}
}

//移除链表中的指定元素
struct SListNode* removeElements(struct SListNode* head, int val)
{
	SListNode* cur = NULL, *prev = head;
	cur = prev->next;
	if (prev == NULL)
	{
		return;
	}
	while (cur==NULL)
	{
		if (prev->data = val)
		{
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else
		{
			prev = prev->next;
			cur = cur->next;
		}
	}
	return head;
}

//返回链表的中间结点(只遍历一次)
//用到快慢指针，快指针一次走两个，慢指针一次走一个
struct SListNode* returnElements(struct SListNode* head)
{
	SListNode* fast = head;
	SListNode* slow = head;
	//如果是奇数个，fast就不能为NULL
	//如果是偶数个 fast->next就不能为NULL
	while (fast && fast->next)//因为是继续这个函数，所以说是要进行且或判断在这里用的是且
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//输入一个链表，输出这个链表倒数第k个结点(只遍历一次)
struct SListNode* putsNode(struct SListNode* head, int k)
{
	struct SListNode* cur = head;
	struct SListNode* pst = head;
	for (int i = 0; i < k; ++i)
	{
		//特殊情况，这个就是当k大于链表长度时会出现的情况
		if (pst)
			pst = pst->next;
		else
			return;
	}
	while (pst->next)
	{
		cur = cur->next;
		pst = pst->next;
	}
	return cur;
}

//合并两个有序链表
struct SListNode* addNode(struct SListNode*head, struct SListNode * phead)
{
	struct SListNode *pst = head;
	struct SListNode *cur = phead;
	struct SListNode *newhead = NULL;
	struct SListNode *last = newhead;
	//分三种情况
	//相等
	//第一个大于第二个
	//第二个大于第一个
	if (head == NULL)
	{
		return phead;
	}
	if (phead == NULL)
	{
		return head;
	}
	if(pst->data > cur->data)
	{
		last->next = cur;
		cur->next = pst;
		last = pst;
	}
	else
	{
		last->next = pst;
		pst->next = cur;
		last = cur;
	}
	return newhead;
}

int main()
{
	//建立一个新的头指针
	SListNode *phead = NULL;
	
}