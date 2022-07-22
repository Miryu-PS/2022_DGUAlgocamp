#include<bits/stdc++.h>
using namespace std;
string arr[1005];
int M,N;
bool vst[1005][1005];
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
void dfs(int x, int y) {
	vst[x][y] = true;
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
		if(arr[nx][ny] != '0' || vst[nx][ny]) continue;
		dfs(nx,ny);
	}
}
int main()
{
	cin>>M>>N;
	for(int i=0; i<M; i++) cin>>arr[i];
	for(int i=0; i<N; i++) {
		if(arr[0][i] == '0' && vst[0][i] == false) dfs(0,i);
	}
	for(int i=0; i<N; i++) {
		if(vst[M-1][i]) {cout<<"YES"; return 0;}
	}
	cout<<"NO";
}
