/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
VER : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e15
#define ll long long
#define pii pair<int,int>
#define int ll
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int t;
int cnt[10002];

int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	int n,m,ans = INF;
	std::vector<pii> vec;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>t;
			vec.push_back({t,i+1});
		}
	}

	t = n*m;

	sort(vec.begin(), vec.end());

	int l=0,r=0;

	int len = 1;
	
	cnt[vec[0].S]++;
	
	while( l < t and r < t)
	{
		
		if( len==n )
		{
			ans = min( ans , vec[r].F - vec[l].F);
			cnt[vec[l].S]--;

			if(cnt[vec[l].S]==0)
			{
				len--;
			}
			l++;

		}

		else
		{
			r++;

			if(r>=t)
				break;
			cnt[vec[r].S]++;
			if(cnt[vec[r].S]==1)
				len++;
		}
	}

	cout<<ans<<"\n";
	
	return 0;
}



