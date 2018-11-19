// (AVL)平衡二叉树的基本操作

struct node
{	//v 为节点权值，height 用来记录以当前结点为根结点的子树的高度
	int v, height;
	node *lchild, *rchild;	//左右孩子结点的地址
};

// 生成一个新结点, v 为其权值
node* newNode(int v)
{
	node* Node = new node;	//申请一个 node 型变量的地址空间
	Node->v = v;
	Node->height = 1;		// 结点高度初始为 1
	Node->lchild = Node->rchild = NULL;	//初始状态下没有左右孩子
	return Node;		//返回新建结点的地址
}

// 获取以 root 为根结点的子树的当前高度
int getHeight(node* root)
{
	if(root == NULL) return 0;	//空节点高度为 0
	return root->height;
}

// 计算结点的平衡因子
int getBalanceFactor(node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

// 更新结点 root 的 height
void updateHeight(node *root)
{
	return max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//-----以下是平衡二叉树的基本操作-------

// 查找操作
// search 函数查找 AVL 树中数据域为 x 的结点
void search(node* root, int x)
{
	if(root == NULL){	//空树，查找失败
		printf("search failed\n", );
		return;
	}
	if(root->v > x){
		search(root->lchild, x);
	}else{
		search(root->rchild, x);
	}
}

// 左旋操作(Left Rotation)
void LR(node* &root)	//注意要加 &
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// 右旋操作(Right Rotation)
void RR(node* &root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(temp);
	updateHeight(root);
	root = temp;
}

// 插入权值为 v 的结点
void insert(node* root, int v)
{
	if(root == NULL){	//到达空节点，即插入的位置
		root = newNode(v);
		return;
	}
	if(v < root->v){	//v 比根结点的权值小
		insert(root->lchild, v);	//往左子树插入
		updateHeight(root);		//更新树的高度
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){	//LL 型
				RR(root);		//右旋
			}else if(getBalanceFactor(root->lchild) == -1){	//LR型
				LL(root->lchild);
				RR(root);
			}
		}
	}else{		// v 比根结点的权值大
		insert(root->rchild, v);	// 往右子树插入
		updateHeight(root);			//更新树高
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->rchild) == -1){	//RR 型
				LR(root);		//左旋
			}else if(getBalanceFactor(root->rchild) == 1){	//RL型
				RR(root->rchild);
				LR(root);
			}
		}
	}
}

// AVL 树的建立
node* create(int data[], int n)
{
	node* root = NULL;	//新建空节点 root
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	}
	return root;	//返回根结点地址
}