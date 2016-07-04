import sys
n, m = map(int, input().split())
if m % 2:
	print(0)
	sys.exit(0)
m /= 2
d = []
for i in range(n + 1):
	d.append([0] * 1001)
for i in range(10):
	d[1][i] = 1
for i in range(2, n + 1):
	for j in range(int(m) + 1):
		for dig in range(10):
			if dig > j:
				break
			d[i][j] += d[i - 1][j - dig]
print(d[int(n)][int(m)] ** 2)
