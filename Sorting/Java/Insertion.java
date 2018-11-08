public Class Insertion
{
	public static void sort(Comparable[] a)
	{	//将 a[] 按升序排序
		int N = a.length();
		for(int i = 1; i < N; i++){
			//将 a[i] 插入到 a[i-1], a[i-2], a[i-3],... 中
			for(int j = i; j > 0 && (a[j] < a[j-1]); j--){
				swap(a, j, j-1);	
			}
		}
	}
}