//二叉树的先序遍历，递归写法
void preorder(node *root)
{
	if(node == NULL){
		return;			// 递归边界
	}
	//访问根结点
	printf("%d\n", root->data);
	//访问在左子树
	preorder(root->lchild);
	//访问右子树
	preorder(root->rchild)
}

// 二叉树的中序遍历
void inorder(node *root)
{
	if(node == NULL){
		return;
	}
	//访问左子树
	inorder(root->lchild);
	//访问根结点
	printf("%d\n", root->data);
	//访问右子树
	inorder(root->rchild);
}

// 二叉树的后序遍历
void postorder(node *root)
{
	if(root == NULL){
		return;
	}
	//访问左子树
	postorder(root->lchild);
	//访问右子树
	postorder(root->rchild);
	//访问根结点
	printf("%d\n", root->data);
}