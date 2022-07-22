#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii,int>;
int dist[405][405]; // 해당 지점에 도착할 수 있는 최단 시간
int dir[405][405];
int dx[]={0,-1,0,1}, dy[]={1,0,-1,0};
int main()
{
	int N,M,st,sx,sy; cin>>N>>M>>st>>sx>>sy;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>dir[i][j];
	queue<piii> Q; // {좌표, 시간}
	Q.push({{sx,sy}, st}); dist[sx][sy] = st;
	while(!Q.empty()) {
		auto tmp = Q.front(); Q.pop();
		int x=tmp.first.first, y=tmp.first.second, t=tmp.second;
		// (x,y)에 t의 시간에 있다.
		if(t+1 < dist[x][y] + 4) Q.push({{x,y}, t+1}); // 도착한지 4초가 되기 전까지는 기다릴 수 있다.
		int DIR = (dir[x][y]+t)%4; // 움직인다면 DIR 방향
		int nx=x+dx[DIR], ny=y+dy[DIR];
		if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
		if(dist[nx][ny]) continue;
		dist[nx][ny] = t+1;
		Q.push({{nx,ny},t+1});
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<'\n';
	}
}
