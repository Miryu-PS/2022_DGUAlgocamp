#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int vst[50005], dist[50005];
vector<vector<pii>> G;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main()
{
	int N,M; cin>>N>>M;
	G.resize(N+1);
	for(int i=0; i<M; i++)
	{
		int x,y,d; cin>>x>>y>>d;
		G[x].push_back({y,d});
		G[y].push_back({x,d});
	}
	fill(dist, dist+N+1, INT_MAX);
	dist[1] = 0; pq.push({0,1}); // {거리, 정점}
	while(!pq.empty() && vst[N] == 0)
	{
		auto tmp = pq.top(); pq.pop();
		int x=tmp.second, di=tmp.first;
		if(vst[x] != 0) continue;
		vst[x] = 1;
		for(auto i:G[x])
		{
			int y=i.first, cost=i.second;
			if(vst[y] || dist[y] <= dist[x]+cost) continue;
			dist[y] = dist[x]+cost;
			pq.push({dist[y],y});
		}
	}
	cout<<dist[N];
}
