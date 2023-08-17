fact = list()

def comb(n, k):
    return fact[n] / (fact[k] * fact[n-k])

x = int(input())
fact.append(1)

for i in range(1,35):
    fact.append(i * fact[i-1])

ans = 0
for i in range(2, x+1):
    ans += comb(x, i)

print(int(ans))

