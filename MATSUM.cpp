/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
APPROACH : 2D BIT
VERDICT : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int tree[1026][1026],arr[1026][1026];
int n;

void update(int x,int y,int val)
{
	for(;x<=n;x+=x&-x)
	{
		int y1 = y;
		for(;y1<=n;y1+=y1&-y1)
			tree[x][y1] += val;
	}
}

int query(int x,int y)
{
	int sum = 0;
	for(;x>0;x-=x&-x)
	{
		int y1 = y;
		for(;y1>0;y1-=y1&-y1)
			sum += tree[x][y1];
	}
	return sum;
}

int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	int t,a,b,c,d;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		while(true)
		{
			cin>>str;
			if(str=="END")
				break;
			if(str=="SET")
			{
				cin>>a>>b>>c;
				a++,b++;
				update(a,b,-arr[a][b]);
				arr[a][b] = c;
				update(a,b,arr[a][b]);
			}
			else
			{
				cin>>a>>b>>c>>d;
				a++,b++,c++,d++;
				cout<<(query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1))<<endl;
			}
		}
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=n+1;j++)
				tree[i][j]=arr[i][j] = 0;
		}
	}

	return 0;
}