// 已知一颗树的先序遍历和中序遍历，重建这棵树


//当前先序序列的区间为[preL, preR], 中序序列的区间为[inL, inR]
// 返回根结点的地址
node* create(int preL, int preR, int inL, int inR)
{
	if(preL > preR){		//先序序列长度 <= 0时
		return NULL;
	}
	node* root = new node;	//创建一个根结点
	root->data = pre[preL];		//根结点的值
	int k;
	for(k = inL; k < inR; k++){
		if(in[k] == pre[preL]){		//在中序序列中找到根结点的位置
			break;
		}
	}
	int numLeft = k - inL;		//左子树的结点个数

	//左子树的先序区间为[preL+1, preL+numLeft], 中序区间为[inL, k-1]
	//返回左子树的根结点，赋值给根结点的左指针
	root->left = create(preL + 1, preL + numLeft, inL, k-1);

	//右子树的先序区间为[pre + numLeft + 1, preL],中序区间为[k+1, inR]
	// 返回右子树的根结点，赋值给根结点的右指针
	root->right = create(preL + numLeft + 1, preR, k + 1, inR);

	return root;		//返回根结点地址
}