// Verdict : AC

#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000

int isPrime[MAX];
int pre[MAX];


int main(int argc, char const *argv[])
{
	

	for(int i = 2; i < MAX; i++)
	{
		if(isPrime[i]==1) continue;
		for(int j = 1; ;j++)
		{
			int t = j*j*j*j;
			if(t>i)
				break;
			int sq = sqrt(i-t);
			if(sq*sq==(i-t))
			{
				pre[i] = 1;
				break;
			}
		}
		for(int j = 2*i;i*i<MAX and j<MAX;j+=i)
			isPrime[j]=1;
	}


	for(int i = 1;i<MAX;i++)
		pre[i] += pre[i-1];

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		cout << pre[n] << endl;
	}
	return 0;
}