#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef int hh;
typedef int Datatype;
//����һ��˳���
typedef struct Seqlist
{
	Datatype* a;
	int size;//��Ч���ݵĸ���
	int capecity;//��Ч���ݵĸ���
}SL;

void SeqListInit();// ˳����ʼ��

void SeqListPrint(SL* p);//˳����ӡ

void SeqListPushBack(SL* psl, Datatype x);//˳���β��

void SeqListPopBack(SL* psl);// ˳���βɾ

void SeqListPushFront(SL* psl, Datatype x);//˳���ͷ��

void SeqListPopFront(SL* psl);// ˳���ͷɾ
