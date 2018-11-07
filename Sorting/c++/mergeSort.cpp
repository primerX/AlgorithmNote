// 归并排序递归实现
const int MAXN = 100;	// 元素个数的最大值

// 将数组 A 的[L1, R1] 与 [L2, R2] 区间合并为有序区间
void merge(int A[], int L1, int R1, int L2, int R2)
{
	int i = L1, j = L2;
	int temp[MAXN], index = 0;		//temp 临时存放合并后的数组，index为其下标
	while(i <= R1 && j <= R2){
		if(A[i] <= A[j]){			// 如果 A[i] <= A[j]
			temp[index++] = A[i++];	// 将A[i] 加入序列 temp 中 
		}else{
			temp[index++] = A[j++];		//如果 A[i] > A[j]
		}
	}
	while(i <= R1) temp[index++] = A[i++];	//将[L1, R1] 的剩余元素加入序列 temp 
	while(j <= R2) temp[index++] = A[j++];	//将[L2, R2] 的剩余元素加入序列 temp
	for (int i = 0; i < index; ++i)
	{
		A[L1 + i] = temp[i];		// 将合并后的序列赋值回数组 A
	}
}


// 将数组 A 当前区间[left, right] 进行归并排序
void mergeSort(int A[], int left, int right)
{
	if(left < right){		//只要 left 小于 right
		int mid = (left + right) / 2;	//取中点
		mergeSort(A, left, mid);		//递归，将左子区间[left, mid] 进行归并排序
		mergeSort(A, mid+1, right);		//递归，将右子区间[mid+1, right] 进行归并排序
		merge(A, left, mid, mid+1, right);		//将左子区间和右子区间合并
	}
}