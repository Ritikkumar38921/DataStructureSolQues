#Ritik kumar
length = [1,2,3,4,5,6,7,8]
prices = [1,5,8,9,10,17,17,20]
ans = 0

def maximum(cost):
    global ans
    if ans < cost:
        ans = cost

def findmaximumValue(piece,cost,lenrod,n):
    if( piece == n):
        return
    
    if lenrod < 0:
        return
    
    if lenrod == 0:        
        maximum(cost)
        return
    
    findmaximumValue(piece,cost+prices[piece],lenrod - length[piece],n) 
    findmaximumValue(piece + 1,cost,lenrod,n)

n = 8
findmaximumValue(0,0,n,n)
print(f"maximum value obtained by cutting {n} pieces is {ans}")


