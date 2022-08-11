#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int N,M,vst[55][55],dist[55][55];
string s[55];
queue<pii> Q;
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
void dfs(int x, int y)
{
	vst[x][y] = 1; dist[x][y] = 1;
	Q.push({x,y});
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0||nx>=N||ny<0||ny>=M) continue;
		if(vst[nx][ny] || s[nx][ny] != 'X') continue;
		dfs(nx,ny);
	}
}
int main()
{
	cin>>N>>M;
	for(int i=0; i<N; i++) cin>>s[i];
	bool did = false;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(s[i][j] == 'X' && did == false)
			// (i,j)와 연결된 모든 X를 Q에 넣는다.
			{
				dfs(i,j); did=true;
			}
		}
	}
	while(!Q.empty())
	{
		auto tmp=Q.front(); Q.pop();
		int x=tmp.first, y=tmp.second;
		if(vst[x][y] == 0 && s[x][y] == 'X')
		{
			cout<<dist[x][y] - 2;
			return 0;
		}
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(dist[nx][ny] == 0)
			{
				dist[nx][ny] = dist[x][y]+1;
				Q.push({nx,ny});
			}
		}
	}

}
