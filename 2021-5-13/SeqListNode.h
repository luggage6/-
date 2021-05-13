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

// 动态申请一个节点
SListNode* BuySListNode(SLDatatype x);
// 单链表打印
void SListPrint(SListNode * phead);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLDatatype x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLDatatype x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);