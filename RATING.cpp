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
pair<pii,int> arr[MAX];
int n;
int ans[MAX];
int tree[MAX];
void update(int x)
{
	for(; x<=100000 ; x+=x&-x)
		tree[x]++;
}
int query(int x)
{
	int sum = 0;
	for(; x>0 ;x -= x&-x)
		sum += tree[x];
	return sum;
}
int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		arr[i] = {{a,b},i};
	}

	sort(arr,arr+n);

	for (int i = 0; i < n; ++i)
	{
		if(i!=0 and arr[i].F.F == arr[i-1].F.F and arr[i].F.S == arr[i-1].F.S)
		{
			ans[arr[i].S] = ans[arr[i-1].S];
			update(arr[i].F.S);
		}
		else
		{
			ans[arr[i].S] = query(arr[i].F.S);
			update(arr[i].F.S);
		}
	}

	for(int i=0;i<n;i++)
		cout<< ans[i] <<endl;



	
	
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