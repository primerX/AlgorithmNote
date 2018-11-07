//插入排序

int A[MAXN], n;		//n 为元素个数，数组下标为 1~n
void insertSort()
{
	for(int i = 2; i <= n; i++){	//进行 n-1 趟排序 
		int temp = A[i], j = i;		//temp 临时存放A[j], j从i开始往前枚举
		while(j > 1 && temp < A[j-1]){	//只要 temp 小于前一个元素A[j-1]
		 	A[j] = A[j - 1];	//把A[j-1] 后移一位至 A[j] 
		 	j--;
		} 
		A[j] = temp;	//插入位置为j 
	}
}
