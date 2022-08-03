import sys
import heapq
input = sys.stdin.readline
INF = 1000000000

V,E = map(int, input().split())
G = [[] for _ in range(V+1)]
dist = [INF] * (V+1)
vst = [False] * (V+1)
for _ in range(E):
	x,y,d = map(int, input().split())
	G[x].append((y,d))
	G[y].append((x,d))

q=[]
heapq.heappush(q, (0,1))
dist[1] = 0

while q and vst[V]==False:
	di, x = heapq.heappop(q)
	if(vst[x]):
		continue
	vst[x] = True
	for i in G[x]:
		y, cost = i
		if vst[y] or dist[y] <= dist[x]+cost:
			continue
		dist[y] = dist[x]+cost
		heapq.heappush(q, (dist[y],y))

print(dist[V])
