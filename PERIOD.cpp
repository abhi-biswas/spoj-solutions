/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
ALGORITHM : KMP FAILURE ARRAY
VERDICT : AC
*/


#include<bits/stdc++.h>
using namespace std;

void computelps(int lps[],string& p)
{
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while(i<p.size())
	{
		if(p[i]==p[len])
		{
			len++;
			lps[i++] = len;
		}
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}


void solve(string& str)
{
	int n = str.size();
	int* lps = new int[n+1];
	int a,b;
	computelps(lps,str);
	for(int i=1;i<n;i++)
	{
		
		a = (i+1) - lps[i];
		if((i+1)%a==0 and (i+1)/a>1)
		{
			cout<<i+1<<" "<<(i+1)/a<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		cout<< "Test case #" << z <<endl;
		solve(str);
		cout<<endl;
	}
	return 0;
}