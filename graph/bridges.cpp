#include<bits/stdc++.h>
#include<cmath>
#include<set>
#define MOD 1000000007
#define vi vector<ll>
#define maps map<ll , ll>
#define pb push_back
#define vll vector<long long>
#define ms multiset<int>
#define fo(i,a,n) for(long long i=a;i<=n;i++)
#define ll long long
#define in insert
 
#define INF 1000000000

using namespace std;

vector<vector<int> > ar(101);


int visited[101] , in[101], low[101];

int timer;



void dfs(int node ,int parent)
{
	visited[node]=1;
	in[node]=low[node]=timer;
	timer++;
	for(int i=0;i<ar[node].size();i++)				//
	{
		int child = ar[node][i];
		
		if(child == parent)
		{
			continue;
		}
		
		if(visited[child]==1)
		{
			low[node]=  min(low[node],  in[child]);
		}
		else
		{
			dfs(child , node);
			
			if(low[child]>in[node])
			{
				cout<<node<<"-"<<child<<endl;
			}
			
			
			low[node]= min(low[node],low[child]);
		}
	}
}





void solve()
{
	int n,m,a,b;
	cin>>n>>m;
	fo(i,1,m)
	{
		cin>>a>>b;
		ar[a].pb(b),ar[b].pb(a);
	}
	dfs(1,-1);
}
 
 
 
 
 
 
 
 
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
	{
    	solve();
    }
	return 0;	
} 
