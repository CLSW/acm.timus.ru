f = [0] * 50
f[0] = 1
f[1] = 1
for i in range(2, 50):
    f[i] = f[i - 1] * i
n = int(input())
ans = 0
for i in range(2, n + 1):
    ans += f[n] // f[n - i]
print(ans)
