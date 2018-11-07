/*
快速排序算法当序列中元素的排列比较随机时，效率最高

当序列中元素接近有序时，会达到最坏时间复杂度O(n^2), 产生这种情况的主要原因在于
主元没有办法把当前区间划分为两个长度接近的子区间

解决方案: 随机选择主元，也就是对 A[left, right] 来说，不总是用 A[left] 作为主元，
而是从 A[left], A[left + 1], ... , A[right] 中随机选择一个作为主元,
(来自算法导论的结论)
这样，对任意输入的数据的期望时间复杂度都能达到 O(nlogn), 不存在一组特定的数据能使这个算法出现最坏情况
*/


// 划分区间的元素 A[left] 称为主元
// 对区间[left, right] 进行划分
int Partition(int A[], int left, int right)
{
	int temp = A[left];		// 将A[left] 存放至临时变量 temp
	/*修正之后的代码
	* int p = (round(1.0 * rand() / RAND_MAX * (right - left) + left));
	* swap(A[p], A[left]);	
	*/

	while(left < right){
		while(left < right && A[right] > temp) right--;		//反复左移right
		A[left] = A[right];		//将 A[right] 移到 A[left]
		while(left < right && A[left] <= temp) left++;		//右移 left
		A[right] = A[left];		// 将 A[left] 移到 A[right]
	}
	A[left] = temp;		//将 temp 放到 left 与 right 相遇的地方
	return left;		//返回相遇的下标
}

// 快速排序
void quickSort(int A[], int left, int right)
{
	if(left < right){		//当前区间长度大于 1
		// 将[left, right] 按 A[left] 一分为 2
		int pos = Partition(A, left, right);
		quickSort(A, left, pos - 1);		//对左子区间递归进行快速排序
		quickSort(A, pos, right);		// 对右子区间进行快速排序 
	}
}