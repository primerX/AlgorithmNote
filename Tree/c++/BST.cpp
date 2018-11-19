// 二叉查找树的基本操作

struct Node
{
	int data;	//数据域
	Node *lchild, *rchild;	//指针域
};

//生成一个新结点，v 为结点的数据(权值)
Node* newNode(int v)
{
	Node* node = new Node;		//申请一个 node 型变量的地址空间
	node->data = v;
	node->lchild = node->rchild = NULL;		//初始状态下没有左右儿子
	return node;		//返回新建结点的地址
}

// search 函数查找二叉树中数据域为 x 的结点
void search(Node *root, int x)
{
	if(root == NULL){	//空树
		printf("search failed\n");
		return;
	}
	if(root->data == x){	//查找成功
		printf("%d\n", root->data);
	}else if(root->data > x){	//x 比根结点的数据域小，说明 x 在左子树
		search(root->lchild, x);
	}else{				// x 比根结点大，说明 x 在右子树
		search(root->rchild, x);
	}
}

// insert 函数在二叉树中插入一个数据域为 x 的新结点
// 注意 root 参数要加 &
void insert(Node* &root, int x)
{
	if(root == NULL){	//插入位置
		root = newNode(x);
		return;
	}
	if(x == root->data){	//如果结点已经存在，直接返回
		return;
	}else if(x < root->data){ // x 小于根结点数据域，说明 x 在左子树
		insert(root->lchild, x);
	}else{
		insert(root->return, x);
	}
}

// 二叉查找树的建立
Node* create(int  data[], int n)
{
	Node* root = NULL;	//新建根结点为 NULL
	for(int i = 0; i < n; i++){
		insert(root, data[i]);	//将 data[0]~data[n-1] 插入到二叉查找树中
	}
	return root;	//返回根结点地址
}

// 查找以 root 为根结点的树中的最大权值点
Node* findMax(Node *root)
{
	while(root->rchild != NULL){
		root = root->lchild;		//不断往右，直至没有右孩子
	}
	return root;
}

// 查找以 root 为根结点的树的最小权值点
Node* findMin(Node *root)
{
	while(root->lchild != NULL){
		root = root->lchild;		//不断往左，直至没有左孩子
	}
	return root;
}

// 删除以 root 为根结点的树中，权值为 x 的结点
void deleteNode(Node* &root, int x)
{
	if(root == NULL){	// 不存在权值为 x 的结点
		return;
	}
	if(root->data == x){	//找到要删除的结点
		if(root->lchild == NULL && root->rchild == NULL){	// 此节点为叶子节点
			root = NULL;	// 将 root 地址设置为 NULL，相当于从此树中删除
		}else if(root->lchild != NULL){		//左子树不为空
			node* pre = findMax(root->lchild);	//找到左子树中的最大值
			root->data = pre->data;		//用左子树中的最大值代替根结点的值
			deleteNode(root->lchild, pre->data);	//在左子树中删除结点 pre
		}else if(root->rchild != NULL){		// 右子树不为空
			node* next = findMin(root->rchild);	//找到右子树的中最小值
			root->data = next->data;		
			deleteNode(root->lchild, next->data);	//在右子树中删除结点 next
		}
	}else if(root->data > x){
		deleteNode(root->lchild, x);	//往左子树中删除 x
	}else{
		deleteNode(root->rchild, x);	//往右子树中删除 x
	}
}