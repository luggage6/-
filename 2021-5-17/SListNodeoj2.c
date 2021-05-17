#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#pragma warning (disable:4996)

typedef int SLDatatype;
//结点
typedef struct SListNode
{
	SLDatatype data;
	struct SListNode* next;
}SListNode;

//对于一个链表，设计一个算法，看其是否为回文结构
//返回ture or false
bool returnbook(SListNode *head)
{
	//找出中间结点
	SListNode * fast = head;
	SListNode * slow = head;
     while (fast && fast->next)
	{
		 slow = slow->next;
		 fast = fast->next->next;
	}
	 SListNode * prev = slow;
	 prev->next = NULL;
	 //进行逆置
	 if (slow == NULL || slow->next == NULL)
	 {
		 return slow;
	 }
	 SListNode* n1 = NULL, *n2 = slow, *n3 = slow->next;
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

//相交链表,编写一个程序，找到两个单链表相交的起始节点
//两个单链表，但是他们有一部分的结点是相交的
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


//判断链表里是否有环
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

//复杂链表（第一个指针指向下一个，第二个指针指向随机数）的复制



int main()
{
	//建立一个新的头指针
	SListNode *phead = NULL;

}