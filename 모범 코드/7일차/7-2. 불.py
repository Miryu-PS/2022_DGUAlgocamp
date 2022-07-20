import sys
from collections import deque

c = int(sys.stdin.readline())

for t in range(c):
    m, n = map(int, sys.stdin.readline().rstrip().split())
    queue = deque()
    firedist = [[0 for i in range(m)] for j in range(n)]
    dist = [[0 for i in range(m)] for j in range(n)]
    arr = [[0 for i in range(m)] for j in range(n)]
    dx = [1,0,-1,0]
    dy = [0,-1,0,1]
    for i in range(n):
        str = sys.stdin.readline().rstrip()
        idx = 0
        for tmp in str:
            if (tmp =='.'):
                arr[i][idx] = 1
            if (tmp == '@'):
                sx = i
                sy = idx
                arr[i][idx] = 1
            if (tmp == '*'):
                queue.append([i,idx])
                firedist[i][idx] = 1
                arr[i][idx] = 1
            idx+=1

    while (len(queue)!=0):
        tmp = queue.popleft()
        x = tmp[0]
        y = tmp[1]
        for i in range(0,4):
            newx = x+dx[i]
            newy = y+dy[i]
            if (newx<0 or newy<0 or newx >n-1 or newy>m-1):
                continue
            if (arr[newx][newy] == 1 and firedist[newx][newy] == 0):
                firedist[newx][newy] = firedist[x][y] + 1
                queue.append([newx,newy])

    queue.append([sx,sy])
    dist[sx][sy] = 1
    ans = 987654321
    while (len(queue)!=0):
        tmp = queue.popleft()
        x = tmp[0]
        y = tmp[1]
        for i in range(4):
            newx = x+dx[i]
            newy = y+dy[i]
            if (newx<0 or newy<0 or newx >n-1 or newy>m-1):
                ans = min(ans, dist[x][y] + 1)
                continue
            if (arr[newx][newy] == 1 and dist[newx][newy] == 0 and firedist[newx][newy] == 0 or firedist[newx][newy] > dist[x][y]+1):
                dist[newx][newy] = dist[x][y] +1
                queue.append([newx,newy])
    if ans == 987654321:
        print("IMPOSSIBLE")
    else:
        print(ans-1)
