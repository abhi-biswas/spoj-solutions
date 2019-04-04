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
std::vector<int> graph[65];
ll dp[65][65];
int n,k;
ll ans ;
void dfs(int v,int p)
{
	dp[v][0]=1;
	for(int& u: graph[v])
	{
		if(u==p)
			continue;
		dfs(u,v);
		for(int i=k;i>=0;i--)
		{
			ll val = dp[v][i];
			//cerr<<v<<" ";
			for(int j=0;i+j+1<=k;j++)
			{
				dp[v][max(i,j+1)]+=(dp[u][j]*val);
			}
		}
	}
	for(int i=0;i<=k;i++)
		ans+=dp[v][i];
}
int main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cerr<<n<<" "<<k<<endl;
		for(int i=1;i<=n;i++)
			graph[i].clear();
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				dp[i][j]=0;
		//cerr<<dp[60][60]<<endl;
		ans =0;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			//cerr<<x<<" "<<y<<endl;
			x++;y++;
			graph[x].pb(y);
			graph[y].pb(x);
		}

		dfs(1,0);
		cout<<ans<<endl;
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