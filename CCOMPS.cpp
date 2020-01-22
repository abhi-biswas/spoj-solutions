
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
int BIT[MAX];
int query(int );
void update(int ,int);
//////////////////////////////////////////////////////////////////////////////////////////////////////////


int vis[MAX];
grp;


void dfs(int v)
{
	stack<int> s;
	s.push(v);



	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		if(vis[v])
			continue;
		vis[v] = 1;
		for(int u : graph[v])
		{
			if(!vis[u])
				s.push(u);
		}
	}
}


int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	int n,m;

	cin >> n >> m;

	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	int ans = -1;

	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}







/*_________________________________________________Utility Functions HERE_______________________________*/

void update(int x, int delta)
{
      for(; x < MAX; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

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