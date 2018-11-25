// 采用 DFS 法遍历图
const int MAXV = 1000;		// 最大顶点数
const int INF = 1e10;		// INF 为一个很大的数 1^10

// 邻接矩阵版 DFS 遍历图
int n, G[MAXV][MAXV];		// n 为顶点数, MAXV 为最大顶点数
// 如果顶点 i 已被访问，则 vis[i] == true, 初始为 false
bool vis[MAXV] = {false};	

void DFS(int u, int depth)	// u 为当前访问的顶点编号，depth 为深度
{
	// 设置顶点 u 已被访问
	vis[u] = true;
	/* 如果需要对顶点 u 进行操作
	   可以在这里进行 */
	// 下面对所有从 u 出发能到达的分支顶点进行枚举
	for(int v = 0; v < n; v++)		// 对于每个顶点 v
	{
		// 如果 v 没有被访问，且 u 可以到达 v
		if(vis[v] == false && G[u][v] != INF)
		{
			DFS(v, depth + 1);		// 访问 v，深度加 1
		}
	}
}

// 遍历图 G
void DFSTrave()
{
	// 对于每个顶点 u
	for(int u = 0; u < n; i++)
	{
		// 如果 u 未被访问
		if(vis[u] == false)
		{
			// 访问 u 和 u 所在的连通块，1 表示初始为第一层
			DFS(u, 1);
		}
	}
}


// 邻接表版 DFS 遍历图
vector<int> Adj[MAXV];		// 图 G 的邻接表
int n;		// n 为顶点数
// 如果顶点 i 已被访问，则 vis[i] == true, 初始为 false
bool vis[MAXV] = {false};

void DFS(int u, int depth)	// u 为当前访问的顶点编号，depth 为深度
{
	// 设置 u 已被访问
	vis[u] = true;
	/* 如果需要对 u 进行操作，可以在此进行*/

	// 对从 u 出发可以到达的所有顶点 v
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][v];
		// 如果 v 未被访问
		if(vis[v] == false)
		{
			// 访问 v，深度加 1
			DFS(v, depth + 1);
		}
	}
}

// 遍历图 G
void DFSTrave()
{
	// 对每个顶点 u
	for(int u = 0; u < n; u++)
	{
		// 如果 u 未被访问
		if(vis[u] == false)
		{
			// 访问 u 和 u 所在的连通块，1表示初始为 1 层
			DFS(u, 1);
		}
	}
}