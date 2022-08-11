#include<bits/stdc++.h>
using namespace std;
int dp[255][255]; // dp[x][y] = x명이 y개를 1개 이상으로 나누는 방법
// dp[x][y] = dp[x-1][y-1] + dp[x][y-x]
// dp[x][x] = 1
// dp[0][0] = 1
int main()
{
    int N,K; cin>>N>>K;
    dp[0][0] = 1;
    for(int i=1; i<=K; i++) for(int j=1; j<=N; j++)
    {
        dp[i][j] = dp[i-1][j-1];
        if(i<=j) dp[i][j] += dp[i][j-i];
    }
    cout<<dp[K][N];

}
