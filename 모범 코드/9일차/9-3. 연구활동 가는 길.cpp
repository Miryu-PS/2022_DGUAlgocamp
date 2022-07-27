#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector<pii> v[15];
int mini=INT_MAX;
bool chk[15];
int N,M,x,y,z;
void dfs(int x,int dist){ // x의 위치에 거리 dist로 도착

    if(x == N){
        mini=min(dist,mini);
        return;
    }

	for(auto i:v[x])
	{
		if(!chk[i.first])
		{
			chk[i.first] = true;
			dfs(i.first, dist+i.second);
			chk[i.first] = false;
		}
	}
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
	chk[1] = true;
	dfs(1,0);
    cout<<mini;
}
