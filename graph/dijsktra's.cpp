#include<bits/stdc++.h>
#include<cmath>
#define MOD 1000000007
#define vi vector<int>
#define maps map<int , int>
#define pb push_back
#define vll vector<long long>
#define ms multiset<int>
#define fo(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define in insert
#define INF 100000000
using namespace std;

vector<pair<int ,int>> adj[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,a,b,w;
	cin>>n>>m;
	 while(m--)
	 {
		 cin>>a>>b>>w;
		 adj[a].pb({b,w});
		 adj[b].pb({a,w});
	 }
	 priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int,int>> > pq;


	 vector<int> distance(n+1 ,INF);
	 pq.push({0,1});
	 distance[1]=0;
	 while(!pq.empty())
	 {
		  int current = pq.top().second;
			int curr_d = pq.top().first;
			pq.pop();
			for( pair<int ,int> edge : adj[current] )
			{
				if(curr_d + edge.second < distance[edge.first])
				{
					distance[edge.first] = curr_d + edge.second;
					pq.push({distance[edge.first] , edge.first});
				}
			}
	 }
	 for(int i=1;i<=n;i++)
	 {
		 cout<<distance[i]<<" ";
	 }
	 cout<<endl;
	return 0;
}
