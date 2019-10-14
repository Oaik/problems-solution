n = (int)(input());
listA = input().split(' ')
listB = input().split(" ")

indx = {}
mx = 0

for i in range(n):
    indx[listA[i]] = i+1

for i in range(n):
    t = indx[listB[i]]
    if(t > mx):
        print(t-mx, end = " ")
        mx = t
    else:
        print(0, end=" ")