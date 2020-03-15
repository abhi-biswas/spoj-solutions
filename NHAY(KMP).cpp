#include<bits/stdc++.h>
using namespace std;


void getLPS(string& hay,int *lps)
{
	int len = lps[0] = 0;

	for(int i = 1; i<hay.size(); i++)
	{
		if(hay[i]==hay[len])
		{
			lps[i] = ++len;
		}
		else
		{
			if(len!=0)
			{
				len = lps[len-1];
				i--;
			}
			else
				lps[i] = 0;
		}
	}
}

void KMP(string& hay,string& stack)
{
	int *lps = new int[hay.size()];
	getLPS(hay,lps);
	int len = 0;
	for(int i=0;i<stack.size();i++)
	{
		if(stack[i]==hay[len])
		{
			len++;
		}
		else
		{
			if(len!=0)
			{
				len = lps[len-1];
				i--;
			}
		}
		if(len==hay.size())
		{
			cout << (i-hay.size() + 1) << "\n";
		}
	}
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	while(cin >> n)
	{
		string hay,stack;
		cin >> hay;
		cin >> stack;
		KMP(hay,stack);
		cout << "\n";
	}
	return 0;
}