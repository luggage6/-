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

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLDatatype x);
// �������ӡ
void SListPrint(SListNode * phead);
// ������β��
void SListPushBack(SListNode** pplist, SLDatatype x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLDatatype x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);