#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int dist[55][55];
bool chk[55][55];
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int main()
{
	int N; cin>>N;
	string s[N];
	for(int i=0; i<N; i++) cin>>s[i];
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) dist[i][j] = INT_MAX;

	priority_queue<piii,vector<piii>,greater<piii>> pq;
	dist[0][0] = '1' - s[0][0];
	pq.push({dist[0][0], {0,0}});
	while(!pq.empty() && chk[N-1][N-1] == false)
	{
		auto tmp = pq.top(); pq.pop();
		int di=tmp.first, x=tmp.second.first, y=tmp.second.second;
		if(chk[x][y]) continue;
		chk[x][y] = true;
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N) continue;
			int cost = '1' - s[nx][ny];
			if(chk[nx][ny] || dist[nx][ny] <= dist[x][y] + cost) continue;
			dist[nx][ny] = dist[x][y] + cost;
			pq.push({dist[nx][ny], {nx,ny}});
		}
	}
	cout<<dist[N-1][N-1];
}
