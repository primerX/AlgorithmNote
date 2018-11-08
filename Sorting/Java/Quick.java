public Class Quick
{
	public static void sort(Comparable[] a)
	{
		StdRandom.shuffle(a);		//消除对输入的依赖
		sort(a, 0, a.length-1);
	}

	private static void sort(Comparable[] a, int low, int high)
	{
		if(high <= low) return;
		int j = partition(a, low, high);	//切分，划定主元
		sort(a, low, j-1);			//将左半部分a[low,...,high] 排序
		sort(a, j+1, high);			// 将右半部分a[j+1,...high] 排序
	}

	private static int partition(Comparable[] a, int low, int high)
	{	//将数组切分为 a[low,..., i-1], a[i], a[i+1, ..., high]
		int i = low, j = high+1;	//左右扫描指针
		Comparable v = a[low];		//切分元素, 主元
		while(1)		//扫描左右，检查扫描是否结束，并交换元素
		{
			while(a[++i] < v) if(i == high) break;
			while(v < a[--j]) if(j == low) break;
			if(i >= j) break;
			swap(a, i, j);
		}
		swap(a, low, high);		// 将 v = a[j] 放入正确的位置
		return j;
	}
}