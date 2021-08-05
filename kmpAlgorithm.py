
def function(text,pattern):
    p = len(pattern)
    t = len(text)
    lps = [0]*p
    i = 0
    for j in range(1,p):
        if pattern[i] == pattern[j]:
            lps[j] = i + 1
            i += 1
        else:
            i = 0
    
    index = 0
    k = 0
    count = 0
    
    while index < t:
        flag = False
        pointer = -1
        for i in range(k,p):
            if text[index] != pattern[i]:
                flag = True
                pointer = i
                break
            index += 1
        
        if flag == False:
            count += 1
            if pointer == -1:
                k = lps[p - 1] + 1
                index += 1
        else:
            if lps[pointer - 1] == 0:
                k = 0
                index += 1
            else:
                k = lps[pointer - 1]
    
    return count
                
                
text = 'AABAACAADAABAABA'
pattern = 'AABA'
ans = function(text , pattern)
print(f"count of matching pattern is {ans}")