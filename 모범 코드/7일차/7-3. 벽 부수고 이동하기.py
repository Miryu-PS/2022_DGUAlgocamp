import sys
from collections import deque

n,m = map(int, sys.stdin.readline().rstrip().split())

arr = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    s = sys.stdin.readline().rstrip()
    idx = 0
    for j in s:
        arr[i][idx]=int(j)
        idx+=1

dx = [1,0,-1,0]
dy = [0,-1,0,1]
queue = deque()
dist1 = [[0 for i in range(m)] for j in range(n)]
dist2 = [[0 for i in range(m)] for j in range(n)]
queue.append([0,0])
dist1[0][0] = 1
while (len(queue)!=0):
    tmp = queue.popleft()
    x = tmp[0]
    y = tmp[1]
    for i in range(4):
        newx = x + dx[i]
        newy = y + dy[i]
        if (newx<0 or newy<0 or newx>n-1 or newy>m-1):
            continue
        if (dist1[newx][newy] == 0):
            dist1[newx][newy] = dist1[x][y]+1
            if (arr[newx][newy] == 0):
                queue.append([newx,newy])

dist2[n-1][m-1] = 1
queue.append([n-1,m-1])
while (len(queue)!=0):
    tmp = queue.popleft()
    x = tmp[0]
    y = tmp[1]
    for i in range(4):
        newx = x + dx[i]
        newy = y + dy[i]
        if (newx<0 or newy<0 or newx>n-1 or newy>m-1):
            continue
        if (dist2[newx][newy] == 0):
            dist2[newx][newy] = dist2[x][y]+1
            if (arr[newx][newy] == 0):
                queue.append([newx,newy])

ans = 987654321
for i in range(n):
    for j in range(m):
        if (dist1[i][j]==0 or dist2[i][j]==0):
            continue
        tmp = dist1[i][j] + dist2[i][j] -1
        ans = min(ans,tmp)

if (ans == 987654321):
    print(-1)
else:
    print(ans)
