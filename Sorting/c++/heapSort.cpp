const int maxn = 100;	// 最大元素个数
// heap 为堆，n 为元素个数
int heap[maxn], n = 10;

// 对 heap 数组在 [low, high] 范围内进行向下调整
// 时间复杂度为 O(logn);
void downAdjust(int low, int high)
{
	// i 为欲调整结点， j 为其左孩子
	int i = low, j = i * 2;
	while(j <= high)		// 存在孩子结点
	{
		// 如果右孩子存在，且右孩子的值大于左孩子
		if(j + 1 <= high && heap[j + 1] > heap[j])
		{
			j = j + 1;		// 让 j 存储右孩子下标
		}
		// 如果孩子中最大的权值比欲调整结点 i 大
		if(heap[j] > heap[i])
		{
			// 交换最大权值的孩子结点，与欲调整结点 i
			swap(heap[j], heap[i]);
			i = j;			// 保持 i 为欲调整结点，j 为 i 的左孩子
			j = i * 2;
		}else{
			// 孩子的结点均比欲调整的结点 i 小，调整结束
			break;
		}
	}
}

// 建堆(最大堆)
// 时间复杂度为 O(n)
void createHeap()
{
	for(int i = n/2; i >= 1; i++)
	{
		downAdjust(i, n);
	}
}

// 删除堆顶元素
void deleteTop()
{
	// 用最后一个元素覆盖堆顶元素，并让元素个数减 1
	heap[1] = heap[n--];
	downAdjust(1, n);	// 向下调整堆顶元素
}

// 对 heap 数组在 [low, high] 范围进行向上调整
void upAdjust(int low, int high)
{
	// i 为欲调整的结点, j 为其父亲结点
	int i = high, j = i / 2;
	while(j >= low)		// 父亲结点在 [low, high] 范围内
	{
		// 如果父亲结点的权值小于欲调整结点 i 的值
		if(heap[j] < heap[i])
		{
			// 交换父亲结点和欲调整的结点
			swap(heap[j], heap[i]);	
			i = j;			// 保持 i 为欲调整结点，j 为 i 的父亲
			j = i / 2;
		}else{
			// 父亲结点权值比欲调整结点 i 的权值大,调整结束
			break;
		}
	}
}

// 添加元素
void insert(int x)
{
	// 让元素个数加 1，然后将数组末尾赋值为 x
	heap[n++] = x;
	upAdjust(1, n);		// 向上调整新加入的结点 x
}

// 堆排序
void heapSort()
{
	createHeap();		// 建立最大堆
	for(int i = n; i >= 1; i--)		// 倒着枚举，直到堆中只有一个元素
	{
		swap(heap[i], heap[1]);		// 交换 heap[i] 与堆顶元素
		downAdjust(1, i-1);			// 调整堆顶
	}
}