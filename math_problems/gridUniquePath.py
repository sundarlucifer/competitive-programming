OUTPUT_MOD = 100000000
def combination(n, r):
    return fact(n) // (fact(n-r)*fact(r))

def fact(n):
    num = 1
    for i in range(2, n+1):
        num*=i
    return num

rows,cols = map(int, input().split())
print(combination(rows+cols-2, cols-1)%OUTPUT_MOD)
