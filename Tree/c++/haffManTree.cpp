// 建立哈夫曼树
#include <iostream>
#include <queue>
using namespace std;

// 代表小顶堆的优先队列
priority_queue<long long, vector<long long>, greater<long long>> q;

int main(int argc, char const *argv[])
{
	int n;
	long long temp, x, y, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &temp);
		q.push(temp);		// 将初始权重压入优先队列
	}
	while(q.size() > 1)		// 只要优先队列中至少有两个元素
	{
		x = q.top();
		q.pop();
		y = q.top();
		y.pop();
		q.push(x + y);		// 取出堆顶的两个元素，求和后压入优先队列
		ans += x + y;		// 累计求和的结果
	}
	printf("%lld\n", ans);	// ans 即为最小带权路径长度
	return 0;
}