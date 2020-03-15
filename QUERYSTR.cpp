/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
ALGORITHM : Z ALGORITHM
VERDICT : AC
*/

#include<bits/stdc++.h>
using namespace std;

void getZARR(string& str,int * zarr)
{
	zarr[0] = str.size();
	int l=0,r=0;
	for(int i=1;i<str.size();i++)
	{
		if(i>r)
		{
			l = r = i;
			while(r<str.size() and str[r]==str[r-l]) r++;
			zarr[i] = r-l;
			r--;
		}
		else
		{
			int k = i - l;
			if(zarr[k]<r-i+1)
			{
				zarr[i] = zarr[k];
			}
			else
			{
				l = i;
				while(r<str.size() and str[r]==str[r-l]) r++;
				zarr[i] = r-l;
				r--;
			}
		}
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,q;
	string str;

	cin >> t;

	while(t--)
	{
		cin >> str;
		reverse(str.begin(),str.end());
		int * zarr = new int[str.size()];
		getZARR(str,zarr);
		cin >> q;
		int n = str.size();
		while(q--)
		{
			int t;
			cin >> t;
			cout << zarr[n-t] << '\n';
		}
	}

}
