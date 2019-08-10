/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
VERDICT : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int tree[100004],p[100004];
int n;

void update(int x,int val)
{
	for( ; x <= 100000; x += x & -x )
		tree[x] += val;
}

int query(int x)
{
	int sum = 0;
	for( ; x>0 ; x -= x & -x )
		sum += tree[x];
	return sum;
}


int32_t main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin >> l >> r;
		int a = query(l),b=query(r);
		cout << a+b - p[l] - p[r] << endl;
		p[l] = a;
		p[r] = b;
		update(l+1,1);
		update(r,-1);
	}
	return 0;
}