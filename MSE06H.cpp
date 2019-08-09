/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e15
#define ll long long
#define ld long double
#define int ll
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define MAX 1000009
#define pb push_back
#define mp map<int,int>
#define F first
#define S second
#define popi __builtin_popcount
#define popll __builtin_popcountll
#define grp vector<int> graph[MAX];
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//////////////////////TEMPLATE ENDS///////////////////////////////////////////////////////////////////////
ll power(ll,ll);
ll mpower(ll,ll);
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int tree[MAX];
int n,m,k;
void update(int x,int val)
{
	for(;x<=m;x+=x&-x)
		tree[x]+=val;
}

int query(int x)
{
	int sum = 0;
	for(;x>0;x-=x&-x)
		sum+=tree[x];
	return sum;
}

int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	for(int h = 1; h <= t; h++)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
			tree[i] = 0;
		vector<pii> vec;
		for(int i=0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			vec[i].pb({a,b});
		}
		sort(vec.begin(),vec.end());
		int ans = 0;
		for(int i=0;i<vec.size();i++)
		{
			set<int> s;
			int j;
			for(j=i;j<vec.size() and vec[i].F==vec[j].F;j++)
			{
				ans += query(m-vec[i].S+1+1);
				s.insert(m-vec[i].S+1);
			}

			i=j-1;
			for(auto ptr = s.begin();ptr!=s.end();ptr++)
				update(*ptr,1);
		}
		cout<<"Test case "<<h<<": "<<ans<<endl;
	}
	return 0;
}







/*_________________________________________________Utility Functions HERE_______________________________*/

ll power(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b%2==1)
		res=res*a;
		a=a*a;
		b=b/2;
	}
	return res;
}
ll mpower(ll a ,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return res;
}