#include<bits/stdc++.h>
using namespace std;
int x[505], y[505];
int main()
{
	int N; cin>>N;
	for(int i=1; i<=N; i++) cin>>x[i]>>y[i];

	int maxv = 0, maxi, maxj;
	for(int i=1; i<=N; i++) // i�� �ݶ�
		for(int j=i+1; j<=N; j++) // j�� �ݶ�
		{
			int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			if(maxv <= dist)
			{
				maxv = dist;
				maxi = i;
				maxj = j;
			}
		}
	//���� �� �� �ݶ� ������ �Ÿ��� maxv�� ������ �Ǿ����� �Ű�
	//maxv�� maxi���� maxj���� ����� �� ������ ���̴�.
	cout<<maxi<<" "<<maxj;
}
