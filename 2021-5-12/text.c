#include"Seqlist.h"

void SeqListText1()//Ë³Ðò±íÎ²²åµÄ²âÊÔ
{
	SL p;
	SeqListInit(&p);
	SeqListPushBack(&p, 1); 
	SeqListPushBack(&p, 2);
	SeqListPopBack(&p);
	SeqListPushFront(&p, 4);
	SeqListPopFront(&p);
	SeqListPrint(&p);
}
int main()
{
	SeqListText1();
	system("pause");
	return 0;
}