
def longestContinuousSubArray(arr):
    currbest = 0
    overallbest = 0
    print(n)
    
    for i in range(n):
        print(f" {i} -> ")
        if (arr[i] + currbest) >= arr[i]:
            currbest += arr[i]
        elif arr[i] > (arr[i] + currbest):
            currbest = arr[i]        
        if overallbest < currbest:
            overallbest = currbest
        
    return overallbest
        
arr = []
n = int(input())

for i in range(n):
    a = int(input())
    arr.append(a)

ans = longestContinuousSubArray(arr)
print(f"\nlongest continuous subarray sum is {ans}")
