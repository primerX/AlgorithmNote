// 选择排序
void selectSort()
{
	for(int i = 0; i <= n; i++){
		int k = i;
		for(int j = i; j <= n; j++){
			if(A[j] < A[k]){
				k = j;
			}
		}
		int temp = A[i];	//交换A[K] 与 A[i]
		A[i] = A[k];
		A[k] = temp; 
	}
}