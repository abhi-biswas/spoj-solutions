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

int tree1[MAX],tree2[MAX];
int n,q;

void update(int tree[],int x,int val)
{
	for(; x<=n; x+=x&-x)
		tree[x]+=val;
}

int query(int tree[],int x)
{
	int sum = 0;
	for(;x>0;x-=x&-x)
		sum += tree[x];
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
	while(t--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)
		{
			tree1[i]=tree2[i]=0;
		}
		while(q--)
		{
			int t,a,b;
			cin>>t>>a>>b;
			if(t==0)
			{
				int v;
				cin>>v;
				update(tree1,a,v),update(tree1,b+1,-v);
				update(tree2,a,-v*(a-1)),update(tree2,b+1,b*v);
			}
			else
			{
				int l = a, r=b;
				int ans = r*query(tree1,r) + query(tree2,r) - ((l-1)*query(tree1,l-1) + query(tree2,l-1));
				cout<<ans<<endl;
			}
		}
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