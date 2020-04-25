/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
Algorithm : Inclusion Exclusion Principle
VERDICT : AC
*/



#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n,k;
int hung[102];
int cumm[22];
int momo[1000007];

int solve_sieve()
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j+=hung[i])
			momo[j] = 1;
	}
	return n - accumulate(momo,momo+n,0);
}

void process(int mask)
{
	int cnt = __builtin_popcountll(mask);
	int num = 1;
	int curr = 0;
	while(mask)
	{
		if(mask&1)
		{
			num = num*hung[curr]/__gcd(hung[curr],num);
		}
		mask >>=1;
		curr++;
	}
	
	cumm[cnt] += (n-1)/num + 1;
}


int solve_inc_excl()
{
	for(int i=0;i<(1<<k);i++)
	{
		process(i);
	}
	int ans = 0;
	int sign = 1;
	for(int i=1;i<=k;i++)
	{
		ans += cumm[i]*sign;
		sign *= -1;
	}
	return n-ans;
}

int32_t main(int32_t argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	cin >> n >> k;
	
	for(int i=0;i<k;i++)
		cin >> hung[i];

	cout << ((k>20)?solve_sieve():solve_inc_excl()) << "\n";

	return 0;
}