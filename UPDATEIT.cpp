/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
APPROACH : Difference Array
VERDICT : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int diff[10004];

int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	int t,n,u,q;
	cin>>t;
	while(t--)
	{
		cin>>n>>u;

		while(u--)
		{
			int a,b,val;
			cin>>a>>b>>val;
			diff[a]+=val;
			diff[b+1]-=val;
		}
		for(int i=1;i<n;i++)
		{
			diff[i] = diff[i] + diff[i-1];
		}
		cin>>q;
		while(q--)
		{
			int idx;
			cin>>idx;
			cout<<diff[idx]<<endl;
		}
		for(int i=0;i<=n+1;i++)
			diff[i] = 0;
	}
	return 0;
}