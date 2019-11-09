// VERDICT : AC
// ALgorithm : OFFLINE QUERY + BIT

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
int arr[30004];
int last[1000004];
int BIT[30004];
int n,q;
void update(int x, int delta)       //add "delta" at index "x"
{
    for(; x <= n; x += x&-x)
          BIT[x] += delta;
}
int query(int x)      //returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}
int ans[200004];
std::vector<pair<pii,int>> qr[30004];

int main()
{
	cin >> n;
	for(int i=0;i<1000004;i++) last[i] = -1;
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	cin >> q;
	
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin >> a >> b;
		qr[b].pb({{a,b},i});
	}
	
	for(int i=1;i<=n;i++)
	{
		if(last[arr[i]] != -1) update(last[arr[i]],-1);
		last[arr[i]] = i;
		
		update(last[arr[i]],1);
		
		for(pair<pii,int>& u : qr[i])
		{
			ans[u.S] = query(i) - query(u.F.F-1);
		}
	}

	for(int i=1;i<=q;i++)
		cout << ans[i] << endl;
	return 0;
}