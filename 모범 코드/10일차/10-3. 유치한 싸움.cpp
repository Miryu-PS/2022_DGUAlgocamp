#include<bits/stdc++.h>
using namespace std;
using pic = pair<int,char>;
vector<vector<pic>> G;
vector<int> color;
bool pos = true;
void dfs(int x, int c) // x¸¦ c·Î Ä¥ÇÑ´Ù.
{
	color[x] = c;
	for(auto i:G[x])
	{
		int y = i.first;
		char rel = i.second;
		if(color[y] == 0)
		{
			if(rel == 'S') dfs(y, c);
			else dfs(y, 3-c);
		}
		if(rel == 'S' && color[y] != c) pos = false;
		if(rel == 'D' && color[y] == c) pos = false;
	}
}
int main()
{
	int N,M; cin>>N>>M;
	G.resize(N+1); color.resize(N+1);
	while(M--)
	{
		char c; int x,y; cin>>c>>x>>y;
		G[x].push_back({y,c});
		G[y].push_back({x,c});
	}
	int zeronum = 0;
	for(int i=1; i<=N; i++)
	{
		if(color[i]) continue;
		zeronum++;
		dfs(i, 1);
	}
	if(pos) {
		cout<<1;
		while(zeronum--) cout<<0;
	}
	else cout<<0;
}
