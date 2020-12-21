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
vi adj[10001],res;
int indegree[10001];
int timer=0;



// Kahn's Algorithm
//  iterate all the node which have 0 in-degree
//	choose a node , each outgoing edge remove all the edges
//	repeat it
//
//
//


bool kahn(int n )
{
	priority_queue<int ,vector<int> , greater<int> > pq;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			pq.push(i);
		}
	}
	while(!pq.empty())
	{
		int current =pq.top();
		res.pb(current);
		pq.pop();
		for(int i=0;i<adj[current].size();i++)
		{
			int child = adj[current][i];
			indegree[child]--;
			if(indegree[child]==0)
			{
				pq.push(child);
			}
		}
	}
	return res.size()==n;
}

void solve()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		adj[a].pb(b);
		indegree[b]++;
	}
	if(kahn(n)==0)
	{
		cout<<"Sandro fails.";
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<res[i]<<" ";
		}
	}
	cout<<endl;
}
 
 
 
 
 
 
 
 
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
	return 0;	
}  
