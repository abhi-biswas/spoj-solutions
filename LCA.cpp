/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
VER : AC
Approach : NAIVE
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
int par[MAX];
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
	par[s]=s;
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
				par[u]=v;
			}
		}
	}
}
int lca(int a,int b)
{
	int node1 ,node2;
	if(lev[a]>lev[b])
	{
		node1=a;
		node2=b;
	}
	else
	{
		node1=b;
		node2=a;
	}
	while(lev[node1]!=lev[node2])
	{
		node1=par[node1];
	}
	while(node1!=node2)
	{
		node1=par[node1];
		node2=par[node2];
	}
	return node1;
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
		bfs(root);
		//return 0;
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