def findSmallest(arr):		# 找到数组中的最小值
	smallest = arr[0]		# 存储最小的值
	smallest_index = 0		# 存储最小元素的索引
	for i in range(1, len(arr)):
		if arr[i] < smallest:
			smallest = arr[i]
			smallest_index = i

	return smallest_index


def selectionSort(arr):		# 对数组进行排序
	newArr = [];		# 创建一个新的数组
	for i in range(len(arr)):
		smallest = findSmallest(arr) # 找出数组中的最小元素,或者使用python内置函数max()
		newArr.append(arr.pop(smallest))
	return newArr


print selectionSort([5, 3, 6, 2, 10])