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
int BIT1[MAX];
int BIT2[MAX];
int query(int*,int );
void update(int *,int ,int);
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int t,n,c;



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

	

	cin >> t;

	while(t--)
	{
		cin >> n >> c;
		for(int i=1;i<=n+1;i++)
		{
			BIT1[i] = BIT2[i] = 0;
		}

		while(c--)
		{
			int t,p,q,v;
			cin >> t >> p >> q;
			if(t==0)
			{
				cin >> v;
				update(BIT1,p,v);
				update(BIT1,q+1,-v);
				update(BIT2,p,-v*(p-1));
				update(BIT2,q+1,q*v);
			}
			else
			{
				cout << query(BIT1,q)*q + query(BIT2,q) - (query(BIT1,p-1)*(p-1) + query(BIT2,p-1)) << endl;
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