#include<bits/stdc++.h>
#include<cmath>
#include<set>
#define MOD 1000000007
#define vi vector<ll>
#define maps map<ll , ll>
#define pb push_back
#define vll vector<long long>
#define ms multiset<int>
#define fo(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define in insert
#define INF 1000000000
using namespace std;

int visited[10001][10001];
int n,m;


bool isvalid(int x, int y)
{
	if(x>n || x<1|| y>n || y<1)	return 0;
	
	if(visited[x][y]==1) return 0;
	
	
	return 0 ;
}


void dfs(int x, int y)
{
	visited[x][y]=1;
	if(isvalid(x-1,y)) dfs(x-1,y);
	else if(isvalid(x,y-1))	dfs(x,y-1);
	else if(isvalid(x+1,y)) dfs(x+1,y);
	else if (isvalid(x,y+1)) dfs(x,y+1);
}

void solve()
{
	cin>>n>>m;
	dfs(1,1);
}
 
 
 
 
 
 
 
 
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	solve();
	return 0;	
} 
