#include<bits/stdc++.h>
using namespace std;
int arr[1000005], N;
int lower_bound(int x) // x 이상의 수가 처음 등장하는 위치
{
	int L = 0, R = N;
	while(L<R)
	{
		int mid = (L+R)/2;
		if(arr[mid] < x) L=mid+1;
		else if(arr[mid] >= x) R=mid;
	}
	return L;
}
int upper_bound(int x) // x 초과의 수가 처음 등장하는 위치
{
	int L = 0, R = N;
	while(L<R)
	{
		int mid = (L+R)/2;
		if(arr[mid] <= x) L=mid+1;
		else if(arr[mid] > x) R=mid;
	}
	return L;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int M; cin>>N>>M;
	for(int i=0; i<N; i++) cin>>arr[i]; sort(arr,arr+N);
	arr[N] = INT_MAX;

	while(M--)
	{
		int a,b; cin>>a>>b;
		cout<<upper_bound(b) - lower_bound(a)<<'\n';
	}
}
