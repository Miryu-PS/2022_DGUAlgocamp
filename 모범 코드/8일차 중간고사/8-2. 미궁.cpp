#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int dist[1005][1005];
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int main()
{
	int N,M; cin>>N>>M;
	string maze[1005];
	int sx,sy,ex,ey;
	for(int i=0; i<N; i++)
	{
		cin>>maze[i];
		for(int j=0; j<M; j++)
		{
			if(maze[i][j] == 'A') sx=i, sy=j;
			if(maze[i][j] == 'B') ex=i, ey=j;
		}
	}
	queue<pii> Q;
	dist[sx][sy] = 0; Q.push({sx,sy});
	while(!Q.empty() && dist[ex][ey] == 0)
	{
		auto tmp = Q.front(); Q.pop();
		int x=tmp.first, y=tmp.second;
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(dist[nx][ny] || maze[nx][ny] == '#') continue;
			dist[nx][ny] = dist[x][y] + 1;
			Q.push({nx,ny});
		}
	}
	if(dist[ex][ey]) cout<<"YES\n"<<dist[ex][ey];
	else cout<<"NO";
}
