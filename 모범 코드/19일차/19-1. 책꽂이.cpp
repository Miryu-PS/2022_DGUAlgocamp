#include<bits/stdc++.h>
using namespace std;
int h[33],n,B,mini=INT_MAX;
void dfs(int x,int value) // ���� x���� �� ���ʰ�, ���ݱ��� �� ���� value�̴�.
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
