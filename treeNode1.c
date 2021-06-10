
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
int treeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		return 1 + treeSize(root->left) + treeSize(root->right);
	}
}

void preorder(struct TreeNode* root, int *array, int *i)
{
	if (root == NULL)
		return;

	array[(*i)++] = root->val;

	preorder(root->left, array, i);
	preorder(root->right, array, i);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = treeSize(root);
	int* array = (int*)malloc(sizeof(int)*size);
	int i = 0;
	preorder(root, array, &i);
	*returnSize = size;
	return array;
}

//