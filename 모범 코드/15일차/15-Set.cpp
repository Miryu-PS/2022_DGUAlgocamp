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
	cout<<*S.lower_bound(4)<<'\n'; // set���� ��Ÿ���� 4�̻��� ���� ���� ��
	cout<<*S.upper_bound(4)<<'\n'; // set���� ��Ÿ���� 4 �ʰ��� ���� ���� ��
	if(S.find(5) != S.end()) cout<<"*"; // 5�� S�� �����Ѵٸ� * ���
	for(auto i:S)  cout<<i; // S�� ��� ���� ���
	*/
}
