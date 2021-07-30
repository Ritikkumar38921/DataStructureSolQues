import math
def perfectSquare(n):
    if(n <= 0):
        return 0
    elif n > 0 and n <= 3:
        return n
    
    sq = int(math.sqrt(n))
  

    smallAns = 1 + perfectSquare(n - (sq * sq))
    return smallAns

n = int(input())
ans = perfectSquare(n)
print(f"\n minimum perfect square required to make a number is {ans}")