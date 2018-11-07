def binarySearch(list, item):
	low = 0;		# 左区间
	high = len(list) - 1	# 右区间

	while low <= high:
		mid = low + (high - low) / 2
		guess = list[mid]
		if guess == item:		# 找到元素
			return mid
		elif guess > item:		# 比数字大
			high = mid - 1
		else:					# 比数字小
			low = mid + 1
	return None		# 没有找到指定元素