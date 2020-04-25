/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
Algorithm : Inclusion Exclusion Principle
VERDICT : AC
*/

#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

void solve()
{
	int n,m,a,d;

	cin >> n >> m >> a >> d;
	auto calc = [&](int num)
	{
		return m/num - (n-1)/num;
	};
	int arr[] = { a, a+d, a+2*d, a + 3*d,a + 4*d};
	int ans = 0;

	auto process = [&](int mask)
	{
		int cnt = __builtin_popcountll(mask);
		int num = 1;
		int curr = 0;
		int f = 1;
		int sign = (cnt%2)?1:-1;
		while(mask and f)
		{
			if(mask&1)
			{
				if(num<=m and arr[curr]<=m and f)
				num = num*arr[curr]/__gcd(arr[curr],num);
				else
				{
					f=0;
					break;
				}
			}
			mask >>=1;
			curr++;
		}
		if(f)
		{
			ans += sign*calc(num);
		}
	};
	for(int i=1;i<(1<<5);i++)
	{
		process(i);
	}
	cout << (m-n+1) - ans << endl;
}



int32_t main(int32_t argc, char const *argv[])
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		solve();
	}
	return 0;
}