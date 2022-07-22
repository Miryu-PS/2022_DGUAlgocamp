#include<bits/stdc++.h>
using namespace std;
int x[505], y[505];
int main()
{
	int N; cin>>N;
	for(int i=1; i<=N; i++) cin>>x[i]>>y[i];

	int maxv = 0, maxi, maxj;
	for(int i=1; i<=N; i++) // i번 콜라
		for(int j=i+1; j<=N; j++) // j번 콜라
		{
			int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			if(maxv <= dist)
			{
				maxv = dist;
				maxi = i;
				maxj = j;
			}
		}
	//가장 먼 두 콜라 사이의 거리가 maxv에 저장이 되어있을 거고
	//maxv는 maxi번과 maxj번을 골랐을 때 구해진 값이다.
	cout<<maxi<<" "<<maxj;
}
