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

string arr[1003];
int t,r,c;
int dis[1003][1003];
pii dir[] = {{1,0},{0,1},{-1,0},{0,-1}};
int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	cin >> t;


	while(t--)
	{
		cin >> r >> c;

		for(int i=0;i<r;i++)
			cin >> arr[i];

		deque<pii> q;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				dis[i][j] = INF;
			}
		}

		dis[0][0] = 0;
		q.push_back({0,0});

		while(!q.empty())
		{
			pii u = q.front();
			//cout << u.F << " " << u.S << " " << dis[u.F][u.S] << endl;
			q.pop_front();
			for(pii d : dir)
			{

				int nx = u.F + d.F;
				int ny = u.S + d.S;
				//cout << nx << " " << ny << endl;
				if(nx <0 or nx>=r or ny<0 or ny>=c ) continue;
				if(dis[nx][ny] > (dis[u.F][u.S] + (arr[u.F][u.S] != arr[nx][ny])) )
				{
					dis[nx][ny] = (dis[u.F][u.S] + (arr[u.F][u.S] != arr[nx][ny]));
					if(arr[u.F][u.S] != arr[nx][ny])
					{
						q.pb({nx,ny});
					}
					else
					{
						q.push_front({nx,ny});
					}
				}	
			}
		}

		cout << dis[r-1][c-1] << endl;

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