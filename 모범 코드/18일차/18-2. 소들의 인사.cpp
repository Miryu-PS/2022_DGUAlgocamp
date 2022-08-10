#include<bits/stdc++.h>
using namespace std;
using pci = pair<char,int>;
vector<pci> A,B;
int main()
{
	int N,M; cin>>N>>M;
	int T = 0;
	for(int i=0; i<N; i++)
	{
		char ch; int x; cin>>x>>ch;
		A.push_back((pci){ch,T});
		T += x;
	}
	A.push_back({'F', T});
	T=0;
	for(int i=0; i<M; i++)
	{
		char ch; int x; cin>>x>>ch;
		B.push_back({ch,T});
		T += x;
	}
	B.push_back({'F', T});
	T = 0; int Am = 0, Bm = 0, Ap = 0, Bp = 0, ans = 0;
	bool bye = false;
	while(1)
	{
		if(Am < N && A[Am+1].second <= T) Am++;
		if(Bm < M && B[Bm+1].second <= T) Bm++;
		if(Am == N && Bm == M) break;
		if(A[Am].first == 'L') Ap--;
		if(A[Am].first == 'R') Ap++;
		if(B[Bm].first == 'L') Bp--;
		if(B[Bm].first == 'R') Bp++;
		if(Ap == Bp && bye) ans++, bye = false;
		if(Ap != Bp) bye = true;
		T++;
	}
	cout<<ans;
}
