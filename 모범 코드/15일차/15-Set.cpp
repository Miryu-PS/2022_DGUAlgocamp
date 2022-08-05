#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N; cin>>N;
	set<int> S;
	for(int i=0; i<N; i++)
	{
		int x; cin>>x; S.insert(x);
	}
	cout<<S.size();
	/*
	cout<<*S.lower_bound(4)<<'\n'; // set에서 나타나는 4이상의 가장 작은 수
	cout<<*S.upper_bound(4)<<'\n'; // set에서 나타나는 4 초과의 가장 작은 수
	if(S.find(5) != S.end()) cout<<"*"; // 5가 S에 존재한다면 * 출력
	for(auto i:S)  cout<<i; // S의 모든 원소 출력
	*/
}
