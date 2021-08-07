
def z_algorithm(text,pattern):
    concat = pattern + "#" + text
    s_len = len(concat)
    z = [0]*s_len
    l,r = 0,0
    for i in range(1,s_len):
        if i > r:
            l = i
            r = i
            while r < s_len and concat[r - l] == concat[r]:
                r += 1
            z[i] = r - l
            r -= 1
        elif i <= r:
            z[i] = min(z[i - l],(r - i + 1))
    n = len(pattern)
    for i in range(n+1,s_len):
        if z[i] == n:
            print(f"found {pattern} at positon {i - n}\n")


text = "aabaababaaaabbaab"
pattern = "baab"
z_algorithm(text,pattern)