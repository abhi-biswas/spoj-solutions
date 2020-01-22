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

int fun(int a,int b)
{
	return a+b;
}

class SparseTable
{
	vector<vector<int> > table;
	vector<int> log;
	int sz;
public:
	SparseTable(int arr[],int sz)
		: table(sz+1,vector<int>(30)),log(sz+1)
	{
		for(int i=0;i<sz;i++)
			table[i][0] = arr[i];
		calculateLog(sz);
		this->sz = sz;
	}
	SparseTable(vector<int> arr)
	{
		for(int i=0;i<arr.size();i++)
			table[i][0] = arr[i];
		calculateLog(arr.size());
		this->sz = arr.size();
	}
	void calculateLog(int n)
	{
		log[1] = 0;
		for(int i=2;i<=n;i++)
			log[i] = log[i/2] + 1;
	}

	void preprocess()
	{
		for(int j=1;j<log[sz]+2;j++)
		{
			for(int i=0;i + (1<<j) <= sz; i++)
				table[i][j] = fun(table[i][j-1],table[i+(1<<(j-1))][j-1]);
		}
	}

	void print()
	{
		for(int i=0;i<sz;i++)
		{
			for(int j=0;j<log[sz]+1;j++)
				cout << table[i][j] << " ";
			cout << endl;
		}
	}

	int RMquery(int a,int b)
	{
		int j = log[b-a+1];
		return fun(table[a][j],table[b-(1<<j)+1][j]);
	}
	int query(int a,int b)
	{
		int ans=0;

		for(int j=log[sz]+1;j>=0;j--)
		{
			if((1<<j)>b-a+1) continue;
			ans = fun(ans,table[a][j]);
			a += (1<<j);
		}
		return ans;
	}
};

int arr[50004];
int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	
	int n,m;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	cin >> m;
	SparseTable table(arr,n);

	table.preprocess();
	
	int ans = 0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		cout << table.query(a,b) <<'\n';
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