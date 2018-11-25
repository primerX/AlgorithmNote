// 采用广度优先搜索 BFS 法遍历图

const int MAXV = 1000;		// MAXV 为最大顶点数
const int INF = 1e10;		// INF 为一个很大的数 10^10
// 邻接矩阵版 
int n, G[MAXV][MAXV];	// n 为顶点数，MAXV 为最大顶点数
// 若顶点 i 曾入过队列，则 inq[i] == true, 初值为 false
bool inq[MAXV] = {false};

void BFS(int u)		// 遍历 u 所在的连通块
{
	queue<int> q;	// 定义队列 q
	q.push(u);		// 将初始点 u 入队
	inq[u] = true;	// 设置 u 已被加入队列
	while(!q.empty())	// 只要队列非空
	{
		int u = q.front();	//取出队首元素
		q.pop();
		// 对于所有顶点 v
		for(int v = 0; v < n; v++)
		{
			// 如果 u 的邻接点 v 未曾如果队列
			if(inq[v] == false && G[u][v] != INF)
			{
				q.push(v);	// 将 v 入队
				inq[v] = true;	// 标记 v 已经入过队
			}
		}
	}
}

// 遍历图 G
void BFSTrave()
{
	// 对于图 G 的所有顶点 u
	for(int u = 0; u < n; u++)
	{
		// 如果 u 未曾入过队列
		if(inq[u] == false)
		{
			BFS(u);		// 遍历 u 所在的连通块
		}
	}
}


// 邻接表版
// Adj[u] 存放从顶点 u 出发可以到达的所有顶点
vector<int> Adj[MAXV];
int n;		// n 为顶点数
// 若顶点 i 曾入过队列，则 inq[i] == true, 初值为 false
bool inq[MAXV] = {false};

void BFS(int u)		// 遍历顶点 u 所在的连通块
{
	queue<int> q;	// 定义队列 q
	q.push(u);		// 将初始点 u 压入队列
	inq[u] = true;	// 设置 u 已被加入队列
	while(!q.empty())	// 只要队列非空
	{
		int u = q.front();	// 取出队列首元素
		q.pop();
		// 枚举从 u 出发能到达的所有顶点 v
		for(int i = 0; i < Adj[u].size(); i++)
		{
			int v = Adj[u][i];
			// 如果 v 还未被压入队列
			if(inq[v] == false)
			{
				// 将 v 入队
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

// 遍历图 G
void BFSTrave()
{
	// 对于图 G 的所有顶点 u
	for(int u = 0; u < n; u++)
	{
		// 如果 u 未曾入过队列
		if(inq[u] == false)
		{
			BFS(u);		// 遍历 u 所在的连通块
		}
	}
}
