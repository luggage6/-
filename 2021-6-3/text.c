#include<stdio.h>
#include<stdlib.h>
typedef int BTDataType;

 typedef struct BinaryTreeNode
{
	struct BinTreeNode* _Left; // ָ��ǰ�ڵ�����
	struct BinTreeNode* _Right; // ָ��ǰ�ڵ��Һ���
	BTDataType _data; // ��ǰ�ڵ�ֵ��
 }BTNode;



 //ǰ�����
 void PrevOrder(BTNode* root)
 {
	 if (root == NULL)
	 {
		 return;
	 }
	 printf("%d", root->_data);
	 PrevOrder(root->_Left);
	 PrevOrder(root->_Right);
 }
 //�������
 void InOrder(BTNode* root)
 {
	 if (root == NULL)
	 {
		 return;
	 }
	 InOrder(root->_Left);
	 printf("%d", root->_data);
	 InOrder(root->_Right);
 }

 //�������
 void lastOrder(BTNode* root)
 {
	 if (root == NULL)
	 {
		 return;
	 }
	 lastOrder(root->_Left);
	 lastOrder(root->_Right);
	 printf("%d", root->_data);
 }

 //�������Ľ�����
 int size;
 int TreeSize(BTNode* root)
 {
	 if (root == NULL)
	 {
		 return 0;
	 }
	 ++size;
	 TreeSize(root->_Left);
	 TreeSize(root->_Right);
	 return size;
 }
int main()
{
	return 0;
}