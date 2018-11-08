public Class Shell
{
	public static void sort(Comparable[] a)
	{	//将 a[] 升序排列
		int N = a.length();
		int h = 1;
		while(h < N/3) h = h * 3 + 1;	//h = 1, 4, 13, 40, 121, 364, ...
		while(h >= 1)	//将数组变为 h 有序
		{
			for(int i = h; i < N; i++){
				// 将 a[i] 插入到 a[i-h], a[i-2*h], a[i-3*h] ... 之中
				for(int j = i; j >= h && (a[j] < a[j-h]); j -= h){
					swap(a, i, j);
				}
			}
			h = h/3;			
		}
	}
}