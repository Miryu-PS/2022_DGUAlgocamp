#include<bits/stdc++.h>
using namespace std;
int h[33],n,B,mini=INT_MAX;
void dfs(int x,int value) // 지금 x번을 볼 차례고, 지금까지 고른 합은 value이다.
{
    if(x==n+1)
    {
        if(value>=B) mini=min(mini,value);
        return ;
    }
    dfs(x+1,value+h[x]);
    dfs(x+1,value);
    return ;
}
int main()
{
    cin>>n>>B;
    for(int i=1;i<=n;i++) cin>>h[i];
    dfs(1,0);
    cout<<mini-B;
}
