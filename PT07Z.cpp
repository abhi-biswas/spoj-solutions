/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
VER : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e15
#define ll long long
#define ld long double
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
grp;
int n;
int f[MAX],g[MAX],ans;
void dfs(int v,int p)
{
	std::vector<int> vec;
	for(int u : graph[v])
	{
		if(u==p)
			continue;
		dfs(u,v);
		vec.pb(f[u]);
	}
	sort(vec.begin(), vec.end());
	f[v]=1;
	cerr<<vec.size()<<endl;
	if(vec.size()>=1)
		f[v]+=vec.back();
	if(vec.size()==0)
		f[v]=0;
	if(vec.size()>=2)
		g[v]=2+vec[vec.size()-1]+vec[vec.size()-2];
	ans = max( ans , max(f[v],g[v]));
}
int main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		cerr<<f[i]<<" "<<g[i]<<endl;
	cout<<ans<<endl;


	
	
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