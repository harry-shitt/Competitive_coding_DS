#include<bits/stdc++.h>


using namespace std ;

int parent[100], level[100] , visited[100];
vector< vector<int> > a(100);
void dfs(int node , int l)
{
	visited[node]= 0 ;
	level[node] = l;
	for(int i = 0 ; i <a[node].size() ; i++)
	{
		if(visited[a[node][i]]==0)
		{
			dfs(a[node][i] , l+1);
		}
	}
}

int LCA(int b ,int c)
{
	int diff = abs(level[b] - level[c]);
	if(level[b]>level[c])
	{
		while(diff>0)
		{
			b = parent[b];
			diff--;
		}
	}
	else
	{
		while(diff>0)
		{
			c= parent[c];
			diff--;
		}
	}
	
	if(c==b) return c;
	
	while(parent[b]!= parent[c])
	{
		b= parent[b];
		c= parent[c];
	}
	return parent[b];
	
}


int main(void)
{
	int n , m ,c, b; 
	parent[1]=-1;
	cin>>n>>m;

	for(int i=1;i<=m; i++)
	{
		cin>>c>>b;
		a[c].push_back(b);
		if(b!=1)
			parent[b] = c;
			
	}
	dfs(1,0);
	for(int i=1;i<=n; i++)
	{
		cout<<level[i]<<" ";
	}
	int q;
	cin>>q;
	while(q--)
	{
		int var, var1;
		cin>>var>>var1;
		cout<<LCA(var , var1)<<endl;
	}
}
