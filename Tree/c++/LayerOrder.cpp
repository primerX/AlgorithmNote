struct Node		//声明树的结点类型
{
	int data;
	int layer;		//结点的层次, 根结点为 1
	Node* lchild, *rchild;	//左右子结点
};

// 层序遍历
void LayerOrder(Node* root)
{
	//队列里面存的是地址, 如果直接存放 Node 型,
	// 就无法对原元素进行修改, 只是修改了副本
	queue<Node*> q;		
	root->layer = 1;	//根结点的层次为 1
	q.push(root);		//将根结点地址入队
	while(!q.empty())	//队列不为空时
	{
		Node* now = q.front();		//取出队首元素地址
		q.pop();
		printf("%d ", now->data);		//访问队首元素
		if(now->lchild != NULL){		//左子树非空
			now->lchild->layer = now->layer + 1;	//左孩子的层号为当前层号加 1
			q.push(now->lchild);
		}
		if(now->rchild != NULL){		//右子树非空
			now->rchild->layer = now->layer + 1;	// 右孩子的层号为当前层号加1
			q.push(now->rchild);
		}
	}
}