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

int arr[501][501][2];
int dp[501][501][4];
int sumr[501][501],sumc[501][501];
int n,m;
int solve(int a,int b,int t)
{
	if(a<0 or b<0 or a>n or b>m )
		return 0;
	//cerr << a << " " << b << " " << t << endl;
	int &ans = dp[a][b][t];
	if(ans!=-1)
		return ans;
	ans = 0;
	if(t==0)
	{
		for(int i=0;i<2;i++)
		{
			ans = max(ans,solve(a-1,b,i));
		}
		ans += sumr[a][b];
	}
	if(t==1)
	{
		for(int i=0;i<2;i++)
		{
			ans = max(ans,solve(a,b-1,i));
		}
		ans += sumc[a][b];
	}
	return ans;
}

int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	while(1)
	{
		
		cin >> n >> m;
		if(n==0 or m==0)
			break;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin >> arr[i][j][0];
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin >> arr[i][j][1];
		}
		for(int i=0;i<n;i++)
		{
			int curr = 0;
			for(int j=0;j<m;j++)
			{
				curr += arr[i][j][0];
				sumr[i][j] = curr;
			}
		}

		for(int j=0;j<m;j++)
		{
			int curr = 0;
			for(int i=0;i<n;i++)
			{
				curr += arr[i][j][1];
				sumc[i][j] = curr;
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<2;k++)
					dp[i][j][k] = -1;
			}
		}

		int ans = 0;
		for(int i=0;i<2;i++)
		{
			ans = max(ans,solve(n-1,m-1,i));
		} 
		cout << ans << endl;
	}


	
	
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