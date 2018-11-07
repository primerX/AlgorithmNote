def quickSort(array):
	if len(array) < 2:	# 当元素个数为 1 或 0 退出	
		return array
	else:
		pivot = array[0]	# pivot 表示主元
		# less 用来存储小于等于主元的所有元素
		less = [i for i in array[1:] if i <= pivot]
		# greater 用来存储大于主元的所有元素
		greater = [i for i in array[1:] if i > pivot]
		return quickSort(less) + [pivot] + quickSort(greater)
