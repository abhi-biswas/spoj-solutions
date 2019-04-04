/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
VER : AC
Approach : BINARY LIFTING

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define MAX 1009
#define pb push_back
#define mp map<int,int>
#define f first
#define s second
#define popi __builtin_popcount
#define popll __builtin_popcountll
#define grp vector<int> graph[MAX];
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ld pi=2.0*acos(0.0);
grp;
int n;
int par[MAX][40];
int lev[MAX];
void bfs(int s)
{
	queue<int> q;
	int vis[n+1];
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	lev[s]=0;
	par[s][0]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(int u: graph[v])
		{
			if(!vis[u])
			{
				q.push(u);
				vis[u]=1;
				lev[u]=lev[v]+1;
				par[u][0]=v;
			}
		}
	}
}


int lca(int a,int b)
{
	int lg;
	if(lev[a]<lev[b])
	swap(a,b);
	for(lg=0; (1LL<<lg)<=lev[a]; lg++);
	lg--;
	for(int i=lg; i>=0;i--)
	if( (lev[a]-(1LL<<i) )>= lev[b] )
	{
		a=par[a][i];
	}
	
	if(a==b)
	return b;
	
	for(int i =lg;i>=0;i--)
	{
		if(par[a][i]!=-1 and par[a][i]!=par[b][i])
		{
			a=par[a][i] ; b = par[b][i];
		}
	}
	return par[a][0];
	
}

int main()
{
	int t;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cout<<"Case "<<l<<":"<<endl;
		cin>>n;
		int in[n+1]={0};
		for(int i=1;i<=n;i++)
		{
			int m;
			cin>>m;
			for(int j=1;j<=m;j++)
			{
				int t;
				cin>>t;
				graph[i].pb(t);
				in[t]=1;
			}
		}
		int root=-1;
		for(int i=1;i<=n;i++)
		if(in[i]==0)
		{
			root=i;
			break;
		}
		int lg ;
		for(lg=0; (1LL<<lg)<=n ;)
		{
			lg++;
		}
		lg--;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=lg;j++)
		{
			par[i][j]=-1;
		}
		bfs(root);
		for(int i=1;i<=lg;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(par[j][i-1]!=-1)
				{
					par[j][i]= par[par[j][i-1]][i-1];
				}
			}
		}
		
		int q;
		cin>>q;
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			cout<<lca(u,v)<<endl;
		}
		for(int i=1;i<=n;i++)
		graph[i].clear();
	}
	return 0;
}