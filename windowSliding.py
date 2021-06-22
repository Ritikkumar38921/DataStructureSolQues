
import sys

def minsum(array,k):
	sum1 = 99999
	for i in range(0,len(array)-k+1):
		s = 0
		for j in range(i,i+k):
			s += array[j]
		if sum1 > s:
			sum1 = s
	return sum1

def minSumOfKelements(array,k):
	minSum = 99999 

	for i in range(1,len(array)):
		s = array[i-1] + array[i]
		array[i] = s
		if i >= k:
			temp = array[i] - array[i-k]
			if minSum > temp:
				minSum = temp
	return minSum

array = [-2,10,1,3,2,-1,4,5]
k = 3
res1 = minsum(array,k)
ans = minSumOfKelements(array,k)
print(f"{res1}  ->  {ans}")