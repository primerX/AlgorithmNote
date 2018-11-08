public Class Selection
{
	public static void sort(Comparable[] a) // 将 a 按升序排序
	{
		int N = a.length();		// N 为数组长度
		for(int i = 0; i < N; i++){
			//将 a[i] 与 a[i+1...N] 中最小的元素交换
			int min = i;		//最小元素的索引
			for(int j = i + 1; j < N; j++){
				if(a[j] < a[min]) min = j;
			}
			swap(a, i, min);		//将数组 a 中 i 与 min 互换
		}
	}

}