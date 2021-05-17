#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#pragma warning (disable:4996)

typedef int SLDatatype;
//���
typedef struct SListNode
{
	SLDatatype data;
	struct SListNode* next;
}SListNode;

//����һ���������һ���㷨�������Ƿ�Ϊ���Ľṹ
//����ture or false
bool returnbook(SListNode *head)
{
	//�ҳ��м���
	SListNode * fast = head;
	SListNode * slow = head;
     while (fast && fast->next)
	{
		 slow = slow->next;
		 fast = fast->next->next;
	}
	 SListNode * prev = slow;
	 prev->next = NULL;
	 //��������
	 if (slow == NULL || slow->next == NULL)
	 {
		 return slow;
	 }
	 SListNode* n1 = NULL, *n2 = slow, *n3 = slow->next;
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
	 }
	 while (n1)
	 {
		 if (n1->data != head->data)
		 {
			 return false;
		 }
		 n1 = n1->next;
		 head = head->next;
	 }
	 return true;
}

//�ཻ����,��дһ�������ҵ������������ཻ����ʼ�ڵ�
//��������������������һ���ֵĽ�����ཻ��
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	struct ListNode* curA = headA;
	int la = 0;
	if(headA==NULL)
	{return headA;}
	else if(headB==NULL)
	{return headB;}
	while (curA)
	{
		++la;
		curA = curA->next;
	}
	struct ListNode* curB = headB;
	int lb = 0;
	while (curB)
	{
		++lb;
		curB = curB->next;
	}
	struct ListNode*longList = headA;
	struct ListNode*shortList = headB;
	if (lb>la)
	{
		longList = headB;
		shortList = headA;
	}
	int gap = abs(la - lb);
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList)
	{
		if (longList == shortList)
			return longList;
		shortList = shortList->next;
		longList = longList->next;
	}
	return 0;
}


//�ж��������Ƿ��л�
bool hasCycle(struct ListNode *head) {
	struct ListNode * fast = head;
	struct ListNode * slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}

//����������һ��ָ��ָ����һ�����ڶ���ָ��ָ����������ĸ���



int main()
{
	//����һ���µ�ͷָ��
	SListNode *phead = NULL;

}