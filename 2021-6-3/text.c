#include<stdio.h>
#include<stdlib.h>
typedef int BTDataType;

 typedef struct BinaryTreeNode
{
	struct BinTreeNode* _Left; // 指向当前节点左孩子
	struct BinTreeNode* _Right; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
 }BTNode;



 //前序遍历
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
 //中序遍历
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

 //后序遍历
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

 //求其树的结点个数
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