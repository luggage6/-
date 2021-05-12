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
//建立一个顺序表
typedef struct Seqlist
{
	Datatype* a;
	int size;//有效数据的个数
	int capecity;//有效数据的个数
}SL;

void SeqListInit();// 顺序表初始化

void SeqListPrint(SL* p);//顺序表打印

void SeqListPushBack(SL* psl, Datatype x);//顺序表尾插

void SeqListPopBack(SL* psl);// 顺序表尾删

void SeqListPushFront(SL* psl, Datatype x);//顺序表头插

void SeqListPopFront(SL* psl);// 顺序表头删
