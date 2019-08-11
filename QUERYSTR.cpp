/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
ALGORITHM : Z ALGORITHM
VERDICT : AC
*/

#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

void computeZ(string& str,std::vector<int>& z)
{

	int left = 0, right = 0,k1;
	z[0] = str.size();
	for(int i=1;i<str.size();i++)
	{
		if(i>right)
		{
			left = right = i;
			while(right<str.size() and str[right]==str[right-left])
				right++;
			z[i] = right-left;
			right--;
		}
		else
		{
			int k1 = i + z[i-left] - 1;
			if(k1<right)
				z[i] = z[i-left];
			else
			{
				left = i;
				while(right<str.size() and str[right]==str[right-left])
					right++;
				z[i] = right-left;
				right--;
			}
		}
	}

}


int32_t main() {
	fastIO
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		std::vector<int> z(str.size()+1,0);
		reverse(str.begin(),str.end());
		computeZ(str,z);
		int q;
		cin>>q;
		while(q--)
		{
			int id;
			cin>>id;
			cout<<z[str.size()-id]<<endl;
		}
	}

	return 0;
}
