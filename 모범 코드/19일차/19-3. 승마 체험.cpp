#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x; cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    int combi = 0, L=0, R=n-1;
    while(L<R)
    {
        if(v[L]+v[R] > x) R--;
        else combi++, L++, R--;
    }
    cout<<n-combi;
}
