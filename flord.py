
def floydWarshall(mat,n):
    dist = []
    for i in range(n):
        dist.append([])
        for j in range(n):
            dist[i].append(-1)
    for i in range(n):
        for j in range(n):
            if mat[i][j] != 0:
                dist[i][j] = mat[i][j]
                   
    for i in range(n):
        for j in range(n):
            for k in range(n):
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k])
    
    for i in range(n):
        for j in range(n):
            if dist[i][j] != -1:
                print(f" distance between {i} and {j} is {dist[i][j]}\n")

n = int(input())
m = int(input())
mat = []
for i in range(n):
    mat.append([])
    for j in range(n):
        mat[i].append(0)

for i in range(m):
    src = int(input())
    des = int(input())
    wt = int(input())
    mat[src][des] = wt
    mat[des][src] = wt

floydWarshall(mat,n)