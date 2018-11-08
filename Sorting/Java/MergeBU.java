public Class MergeBU		//自底向上的归并排序(迭代)
{
	private static Comparable[] aux;	//归并所需的辅助数组

	public static void sort(Comparable[] a)
	{	// 进行 lgN 次两两归并
		int N = a.length();
		aux = new Comparable[N];
		for(int sz = 1; sz < N; sz += sz)	// sz 为子数组大小
		{
			for(int low = 0; low < N-sz; low += sz+sz)	//low 为子数组索引
			{
				merge(a, low, lo + sz - 1, Math.min(lo+sz+sz-1, N-1));
			}
		}
	}
}