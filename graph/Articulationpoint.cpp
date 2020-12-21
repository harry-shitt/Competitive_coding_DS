#include<bits/stdc++.h>
#include<cmath>
#include<set>
#define mod 1000000007
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
vi adj[100];
int low[100],in[100],visited[100];
int timer=0;

void articulation(int node ,int p){
	visited[node]=1;
	
	in[node]=low[node]=timer++;
	int children=0;
	for(int i=0;i<adj[node].size();i++)	
	{
		int child = adj[node][i];
		if(child == p) continue;
		
		if(visited[child]){
			low[node]=min(low[node],in[child]);	
		}
		else
		{
			articulation(child,node);
			children++;
			low[node]=min(low[node],low[child]);
			if(low[child]>=in[node] && p!=-1)
			{
				cout<<node<<endl;
			}
		}
		
		if(p==-1 && children>1)		
		{
			cout<<node<<endl;
		}
	}
	
	
}

void solve()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		adj[a].pb(b),adj[b].pb(a);
	}
	articulation(1,-1);
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
