/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
VER : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
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
int dp[1025][1025];
int ar[1025];
int b[1025];
int main() {
	int t;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		int n,m;
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)
		{
			cin>>ar[i];
		}
		memset(b,0,sizeof b);
		for(int i=1;i<=m;i++)
		{
			int t;
			cin>>t;
			b[t]=1;
		}
		
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i=1;i<=n;i++)
		{
			int a = ar[i];
			for(int j=0;j<1024;j++)
			{
				dp[i][j] = (dp[i-1][j] + dp[i-1][j^a])%MOD;
				if(dp[i][j]>=MOD)
				dp[i][j]-=MOD;
			}
		}
		int ans =0;
		for(int i=0;i<1024;i++)
		if(b[i]==0)
		ans=(ans+dp[n][i])%MOD;
		printf("Case %d: %d\n",l,ans);
	}
	return 0;
}