/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
ALGO : RMQ with Sparse Table
VERDICT : AC
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int logg[MAX];
int table[MAX][32];
int arr[MAX],n,q;

int main(int argc, char const *argv[])
{
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif

	cin>>n;
	logg[1] = 0;
	for (int i = 2; i <= n; ++i) logg[i] = logg[i/2] + 1; 
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++) table[i][0] = arr[i]; 

	for(int j=1; j<32; j++)
	
		for(int i=0; i + (1LL<<j) <= n; i++)
			table[i][j] = min( table[i][j-1] , table[ i + (1LL<<(j-1)) ][j-1] );

	cin>>q;

	while(q--)
	{
		int a , b;
		cin>>a>>b;
		int l = logg[b-a+1];
		cout << min ( table[a][l] , table[ b - (1LL<<l) + 1 ][l] ) << endl;
	}
	return 0;
}