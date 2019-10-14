n, d = map(int, input().split())
a, b = map(int, input().split())

a2 =[]

for i in range(n):
    x, y = map(int, input().split())
    a2.append((a*x+y*b,i))

a2.sort()
ans = []

for i in range(n):
    if(a2[i][0] <= d):
        d -= a2[i][0]
        ans.append(a2[i][1])
    else:
        break

print(len(ans))
for i in ans:
    print(i+1, end = " ")
