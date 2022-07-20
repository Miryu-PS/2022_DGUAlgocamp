import sys
from collections import deque

N,M = map(int,sys.stdin.readline().split())
graph = [list(map(int,sys.stdin.readline().strip())) for _ in range(N)]
visited = [[0]*M for _ in range(N)]

q = deque()
q.append([0,0])
dx = [0,1,0,-1]
dy = [1,0,-1,0]
while q:
	a,b = q.popleft()
	for i in range(4):
		nx = a + dx[i]
		ny = b + dy[i]
		if nx>=0 and ny>=0 and nx<N and ny<M:
			if visited[nx][ny] == 0 and graph[nx][ny] == 1:
				visited[nx][ny] =  visited[a][b] + 1
				q.append([nx,ny])

if visited[N-1][M-1] == 0:
    print(-1)
else:
    print(visited[N-1][M-1]+1)
