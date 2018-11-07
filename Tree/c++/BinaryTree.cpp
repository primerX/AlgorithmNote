//二叉树的基本操作

struct Node 		// 定义二叉树的结点结构		
{
	typename data;	//数据域
	Node* lchild;	//指向左子树根结点的指针
	Node* rchild;
};

//生成一个新结点，v 为结点的数据(权值)
Node* newNode(int v)
{
	Node* node = new Node;		//申请一个 node 型变量的地址空间
	node->data = v;
	node->lchild = node->rchild = NULL;		//初始状态下没有左右儿子
	return node;		//返回新建结点的地址
}


// 二叉树结点的查找，修改
// 找到值为 x 的结点，并将其修改为 newdata
void search(Node* root, int x, int newdata)
{
	if(root == NULL) return;	//空树，递归边界
	if(root->data == x){		//找到数据域为 x 的结点，并将它修改为newdata
		root->data = newdata;
	}
	search(root->lchild, x, newdata);	//往左子树搜索 x
	search(root->rchild, x, newdata);	//往右子树搜索 x
}

// 二叉树结点的插入
// 根结点 root 要使用引用，否则插入不会成功
void insert(Node* &root, int x)
{
	if(root == NULL){		//空树，或者递归边界(插入的位置)
		root = newNode(x);
		return;
	}
	if(根据二叉树的性质和题目要求，x应该插入左子树){	//具体条件
		insert(root->lchild, x);		//往左子树插入 x
	}else{
		insert(root->rchild, x);		//往右子树插入 x
	}
}


// 二叉树的创建
Node* Create(int data[], int n)
{
	Node* root = NULL;		//创建空根结点 root
	for(int i = 0; i < n; i++){
		insert(root, data[i]);		//将data[0]~data[1] 插入二叉树中
	}
	return root;		//返回根结点
}