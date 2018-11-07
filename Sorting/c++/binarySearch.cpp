// 二分区间为左闭右闭的 [left, right], 传入的值为[0, n-1]
int binarySearch(int A[], int left, int right, int x)
{
	int mid;	// mid 为 left 和 right 的中点
	while(left < right){
		mid = left + (right - left) / 2;		// 使用left + (right - left) 来避免溢出
		if(A[mid] == x) return mid;		//找到x， 返回下标
		else if(A[mid] > x){		//中间的数大于 x
			right = mid - 1;
		}else{					//中间的数小于 x
			left = mid + 1;
		}
	}
	return left;
}