/* 并查集的基本操作, 并查集的每一个集合都是一棵树
   初始化，查找，合并, 路径压缩
*/

//father[i] 表示 i 的父亲结点
int father[N];	

// 1. 初始化
for(int i = 1; i <= N; i++)
{
	father[i] = i;	// 令 father[i] = -1 也可以
}

// 2. 查找
// findFather 函数返回 x 所在集合的根结点
int findFather(int x)
{
	while(x != father[x])	// 如果不是根结点，继续循环
	{
		x = father[x];		// 获得自己的父亲结点
	}
	return x;
}

// 递归写法
int findFather(int x)
{
	if(x == father[x]) return x;	// 如果找到根结点，则返回根结点的编号
	else return findFather(father[x]);	//否则，递归判断 x 的父亲结点是否为根结点
}

// 3. 合并
void Union(int a, int b)
{
	int faA = findFather(a);		// 查找 a 的根结点，记为 faA
	int faB = findFather(b);		// 查找 b 的根结点，记为 faB
	if(faA != faB){					// 如果不属于同一集合
		father[faA] = faB;			// 合并它们
	}
}

// 4. 路径压缩
int findFather(int x)
{
	// 由于 x 在下面的 while 中会变成根结点，因此先将 x 保存起来
	int a = x;
	// 寻找根结点
	while(x != father[x])
	{
		x = father[x];
	}
	// 到这里，x 为根节点
	// 下面把路径上的所有结点的 father 都改为根结点
	while(a != father[a])
	{
		int z = a;	// 保存 a 的值
		a = father[a];	// a 回溯父亲结点
		father[z] = x;	// 将原先结点 a 的父亲结点改为根结点 x
	}
	return x;		// 返回根结点
}

// 路径压缩的递归写法
int findFather(int v)
{
	if(v == father[v]) return v;	//找到根结点
	else{
		// 递归寻找 father[v] 的根结点 F
		int F = findFather(father[v]);
		father[v] = F;		// 将根结点 F 赋值给 father[v]
		return F;			// 返回根结点 F
	}
}