#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii,int>;
int dist[405][405]; // �ش� ������ ������ �� �ִ� �ִ� �ð�
int dir[405][405];
int dx[]={0,-1,0,1}, dy[]={1,0,-1,0};
int main()
{
	int N,M,st,sx,sy; cin>>N>>M>>st>>sx>>sy;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>dir[i][j];
	queue<piii> Q; // {��ǥ, �ð�}
	Q.push({{sx,sy}, st}); dist[sx][sy] = st;
	while(!Q.empty()) {
		auto tmp = Q.front(); Q.pop();
		int x=tmp.first.first, y=tmp.first.second, t=tmp.second;
		// (x,y)�� t�� �ð��� �ִ�.
		if(t+1 < dist[x][y] + 4) Q.push({{x,y}, t+1}); // �������� 4�ʰ� �Ǳ� �������� ��ٸ� �� �ִ�.
		int DIR = (dir[x][y]+t)%4; // �����δٸ� DIR ����
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
