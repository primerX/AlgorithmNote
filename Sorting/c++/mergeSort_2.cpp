// 归并排序--迭代方式

// 数组A 的下标从 1 开始
void mergeSort(int A[])
{
	// step 为组内元素个数， step / 2 为左子区间元素个数，注意，等号不可取
	for(int step = 2; step / 2 <= n; step *= 2){
		// 每 step 个元素一组，组内前 step / 2 和后 step / 2 个元素合并
		for(int i = 1; i <= n; i += step){	//对每一组
			int mid = i + step / 2 - 1;		//左子区间元素个数为 step / 2
			if(mid + 1 <= n){		//右子区间存在元素则合并
				//左子区间[1, mid], 右子区间[mid+1, min(i+step-1, n)]
				merge(A, i, mid, mid+1, min(i + step - 1), n);
			}
		}
	}
}


// 可以使用c++ 中 sort 来代替 merge
void mergeSort(int A[])
{
	// step 为组内元素个数
	for(int step = 2; step / 2 <= n； step *= 2){
		// 每 step 个元素一组，对组内[i, min(i + step, n+1)] 进行排序
		for(int i = 1; i <= n; i += step){
			sort(A + i, A + min(i + step, n + 1));
		}
		// 此处可以输出归并排序的某一趟结束的序列
	}
}