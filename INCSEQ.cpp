/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
APPROACH : DP optimized using BIT
VERDICT : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 5000000LL
#define int long long
#define MAX 100004

int tree[51][MAX],num,n,k;

void update(int t, int x,int val)
{
	for(;x<=num;x+=x&-x)
	{
		tree[t][x]=(tree[t][x]+val);
		if(tree[t][x]>=MOD)
			tree[t][x] -= MOD;
	}
}

int query(int t,int x)
{
	int sum = 0;
	for(;x>0;x-=x&-x)
	{
		sum = (sum + tree[t][x]);
		if(sum>=MOD)
			sum -= MOD;
	}
	return sum;
}


int32_t main()
{

	cin>>n>>k;
	num = MAX-1;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		update(1,t+1,1);
		for(int j = 1; j < k; j++)
		{
			int cnt = query(j,t);
			update(j+1,t+1,cnt);
		}
	}

	cout << query(k,MAX-1)<<endl;

	return 0;
}