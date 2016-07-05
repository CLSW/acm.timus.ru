n, m, y = map(int, input().split())
cnt = 0
for i in range(0, m):
    if pow(i, n, m) == y:
        print(i, end = ' ')
        cnt = 1
if cnt == 0:
    print(-1)
