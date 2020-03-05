from itertools import combinations
def isSolvable(p, k):
  ansList = []
  div = 2
  while p>0:
      if p%div==0:
          ansList.append(div)
          p/=div
      else:
          div += 1
      if div>p:
          ansList.append(int(p))
          break
  # print(ansList)
  return not len(ansList)<k
def prod(lst):
    ans = 1
    for i in lst: ans*=i
    return ans
s,p,k=[int(i) for i in input().split()]
l=[i for i in range(1,s-1)]+[i for i in range(1,s-1)]
if not isSolvable(p, k):
  print('NO')
  exit()
comb=list(combinations(l,k))
# print('combination over')
for i in comb:
  if sum(i)==s and prod(i)==p:
    print(*i)
    exit()
print('NO')