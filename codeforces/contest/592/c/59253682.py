from fractions import gcd

n,a,b = map(int,raw_input().split())
"""
// Simulate some testcases (10, 3, 2) (10, 2, 4) (21, 4, 5)
// Observation
// let x = (min(a, b) - 1)
// N / LCM + (N / lcm) * x + Y
// or Using(common term)
// N / LCM(x + 1) + Y
"""
lcm = int(a * b / gcd(a, b))
l = int(n // lcm)
m = min(a, b) - 1
y = min(m, n % lcm)
ans = l * (m + 1) + y
 
g = int(gcd(ans, n))
ans = ans // g
n = n // g
print'{}/{}'.format(ans, n)
#print(int(ans), "/", int(n))
