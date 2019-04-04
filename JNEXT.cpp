/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
VER : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
//ld pi=2.0*acos(0.0);
int main() {
	fastIO
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++)
		cin>>arr[i];
		int i=n-1;
		
		while(i>=1 and arr[i]>=arr[i+1])
		{
			i--;
		}
		if(i<1)
		{
			cout<<-1<<endl;
			continue;
		}
		vector<int> vec;
		for(int j=i+1;j<=n;j++)
		{
			vec.pb(arr[j]);
		}
		reverse(vec.begin(),vec.end());
		int id = upper_bound(vec.begin(),vec.end(),arr[i])-vec.begin();
		int t = arr[i];
		
		arr[i]=vec[id];
		vec[id]=t;
		
		for(int j=i+1;j<=n;j++)
		arr[j]=vec[j-i-1];
		for(int i=1;i<=n;i++)
		cout<<arr[i];
		cout<<endl;
		
	}
	return 0;
}