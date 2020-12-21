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

int visited[10001][10001], d[10001][10001];
int n,m;
queue<pair<int ,int> > q;
int dx[]= {-1,0,1,0},dy[]={0,1,0,-1};


bool isvalid(int x, int y)
{
	if(x>n || x<1|| y>m || y<1)	return 0;
	if(visited[x][y]==1) return 0;
	return 1 ;
}


void bfs(int x, int y)
{
	visited[x][y]=1;
	d[x][y]=0;
	q.push({x,y});
	while(!q.empty())
	{
		int currentx =q.front().first;
		int currenty =q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(isvalid(currentx+dx[i], currenty+dy[i] ))
			{
				int newx = currentx+dx[i];
				int newy = currenty+dy[i];
				q.push({newx,newy});
				visited[newx][newy]=1;
				d[newx][newy]=d[currentx][currenty]+1;
			}
		}
	}
	fo(i,1,n) 
	{
		fo(j,1,n) 
			cout<<d[i][j];
		cout<<endl;
	}
}

void solve()
{
	int x,y;
	cin>>n>>m;
	cin>>x>>y;
	bfs(x,y);
}
 
 
 
 
 
 
 
 
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	solve();
	return 0;	
} 
