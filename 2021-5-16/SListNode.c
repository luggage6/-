#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#pragma warning (disable:4996)

typedef int SLDatatype;
//���
typedef struct SListNode
{
	SLDatatype data;
	struct SListNode* next;
}SListNode;


//��ת�����������ߵݹ飩
SListNode* Relistnode(SListNode* phead)
{
	//����һ��������
	if (phead == NULL || phead->next==NULL)
	{
		return phead;
	}
	SListNode* n1 = NULL, *n2 = phead, *n3 = phead->next;
	while (n2)
	{
		//��ת
		n2->next = n1;
		//�ݹ�
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
		return n1;
	}
}

  //ͷ������
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

//�Ƴ������е�ָ��Ԫ��
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

//����������м���(ֻ����һ��)
//�õ�����ָ�룬��ָ��һ������������ָ��һ����һ��
struct SListNode* returnElements(struct SListNode* head)
{
	SListNode* fast = head;
	SListNode* slow = head;
	//�������������fast�Ͳ���ΪNULL
	//�����ż���� fast->next�Ͳ���ΪNULL
	while (fast && fast->next)//��Ϊ�Ǽ����������������˵��Ҫ�����һ��ж��������õ�����
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//����һ��������������������k�����(ֻ����һ��)
struct SListNode* putsNode(struct SListNode* head, int k)
{
	struct SListNode* cur = head;
	struct SListNode* pst = head;
	for (int i = 0; i < k; ++i)
	{
		//���������������ǵ�k����������ʱ����ֵ����
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

//�ϲ�������������
struct SListNode* addNode(struct SListNode*head, struct SListNode * phead)
{
	struct SListNode *pst = head;
	struct SListNode *cur = phead;
	struct SListNode *newhead = NULL;
	struct SListNode *last = newhead;
	//���������
	//���
	//��һ�����ڵڶ���
	//�ڶ������ڵ�һ��
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
	//����һ���µ�ͷָ��
	SListNode *phead = NULL;
	
}