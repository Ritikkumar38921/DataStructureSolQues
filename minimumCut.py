def minimum_cut(string):
    length = len(string)
    if length == 1 or length == 0:
        return 0
    
    # check that does string is palindrome or not

    # for right string
    i = 0
    j = length - 1
    # for left string 
    while(i <= j):
        if i == j:
            i = i + 1
            j = j + 1
            break
        elif string[i] == string[j]:
            i = i + 1
            j = j - 1
        else:
            break
    if i > j:
        return 0
    m = 10000
    for i in range(1,length):
        left = string[:i]
        right = string[i:]
        m = min(m,(minimum_cut(left) + minimum_cut(right)))
    return 1 + m


string = input()
ans = minimum_cut(string)
print(f"minimum cut required to become all the part of the string {string} to be palindrome is {ans}")