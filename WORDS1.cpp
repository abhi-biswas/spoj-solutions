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
int graph[28][28];
int n;
int in[28];
int out[28];
int vis1[28];
void dfs(int v)
{
	vis1[v]=1;
	for(int u=0;u<26;u++)
	{
		if(!vis1[u] and (graph[v][u]==1 or graph[u][v]==1))
		dfs(u);
	}
}
int main() {
	fastIO
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<28;i++)
		for(int j=0;j<28;j++)
		graph[i][j]=0;
		for(int i=0;i<28;i++)
		{
			
			in[i]=0;
			out[i]=0;
			vis1[i]=0;
		}
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string temp;
			cin>>temp;
			int x= temp[0]-'a';
			int y=temp[temp.size()-1]-'a';
			graph[x][y]=1;
			in[y]++;
			out[x]++;
		}
	
	int a=0,b=0,c=0,id1=0,id2=0,g=1;
	for(int i=0;i<=25;i++)
	{
		if(in[i]==out[i]+1)
		{
			a++;
			id1=i;
		}
		else if(in[i]+1==out[i])
		{
			b++;
			id2=i;
		}
		else if(in[i]!=out[i])
		{
			g=0;
			break;
		}
		
	}
	if(g==0 or !((a==1 and b==1) or (a+b==0)) )
	{
		cout<<"The door cannot be opened."<<endl;
		continue;
	}
	dfs(id2);
	int f= 1;

	for(int i=0;i<26;i++)
	if(!vis1[i] and (in[i]>0 or out[i]>0))
	{
		f=0;
		break;
	}
	if(f==0)
	{
		cout<<"The door cannot be opened."<<endl;
	}
	else
	cout<<"Ordering is possible."<<endl;;
	}
	return 0;
}