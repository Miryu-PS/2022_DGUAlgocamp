#include<bits/stdc++.h>
using namespace std;
int dp[75][75][75];
// dp[x][y][z] = x명이 y개를 z개 이상으로 나누는 방법
// dp[x][y][z] = sum(dp[x-1][y-i][i]) (i>=z)

int main()
{
	int N,K; cin>>N>>K;
	for(int i=1; i<=N; i++) dp[0][0][i] = 1;
	for(int i=1; i<=K; i++) for(int j=1; j<=N; j++) for(int k=1; k<=j; k++)
	{
		dp[i][j][k] = 0;
		for(int t=k; t<=j; t++) dp[i][j][k] += dp[i-1][j-t][t];
	}
	cout<<dp[K][N][1];
}
