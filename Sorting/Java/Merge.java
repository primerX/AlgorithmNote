public Class Merge		//自顶向下的归并排序,(递归)
{
	private static Comparable[] aux;	// 归并所需的辅助数组

	public static void sort(Comparable[] a)		
	{
		aux = new Comparable[a.length];		//一次性分配空间
		sort(a, 0, a.length - 1);
	}

	private static void sort(Comparable[] a, int low, int high)
	{	//将数组 a[low, ..., high] 排序 
		if(high < low) return;
		int mid = low + (high - low) / 2;
		sort(a, low, mid);		//将左半边排序
		sort(a, mid+1, high);	//将右半边排序
		merge(a, low, mid, mid+1, high);		//归并结果
	}

	public static void merge(Comparable[] a, int low, int mid, int high)
	{	//将 a[low,..mid] 和 a[mid+1,...,high] 归并
		int i = low, j = mid + 1;
		for(int k = low; k <= high; k++)	//将a[low,..,high] 复制到aux[low,...,high] 中
		{
			aux[k] = a[k];
		}

		for(int k = low; k <= high; k++)	//归并回到 a[low,...,high]
		{
			if(j > mid)		a[k] = aux[j++];
			else if(j > hi) a[k] = aux[i++];
			else if(aux[j] < aux[i]){
				a[k] = aux[j++];
			}else{
				a[k] = aux[i++];
			}
		}
	}
}