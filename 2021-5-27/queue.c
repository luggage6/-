#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#pragma warning (disable:4996)

typedef int QDatatype;
//���

typedef struct QueueNode
{
	QDatatype data;
	struct Queue* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;
//��ʼ��
void QueueInit(Queue* pst)
{
	assert(pst);
	pst->head = pst->tail = NULL;
}
//ɾ������
void QueueDestory(Queue* pst)
{
	assert(pst);
	QueueNode* cur = pst->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pst->head = pst->tail = NULL;
}
//��������
void Queuepush(Queue* pst, QDatatype x)
{
	assert(pst);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("�ڴ治��");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pst->head == NULL)
	{
		pst->head = pst->tail = newnode;
	}
	else
	{
		pst->tail->next = newnode;
		pst->tail = newnode;
	}
}
//ɾ������
void Queuepop(Queue* pst)
{
	assert(pst);
	assert(pst->head);
	QueueNode* next = pst->head->next;
	free(pst->head);
	pst->head = next;
	if (pst->head == NULL)
	{
		pst->tail = NULL;
	}
}
//��ͷ����
QDatatype QueueFront(Queue* pst)
{
	assert(pst);
	assert(pst->head);
	return pst->head->data;
}
//��β����
QDatatype Queuebehead(Queue* pst)
{
	assert(pst);
	assert(pst->head);
	return pst->tail->data;
}

