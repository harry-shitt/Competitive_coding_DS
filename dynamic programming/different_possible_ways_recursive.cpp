#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dp[101][101];
int n,m;

int fill(int x, int y)
{
  // cout<<x<<" "<<y<<endl;
  if(x<1 || y<1 || y>m || x>n)  return 0;

  if(dp[x][y]!=-1) return dp[x][y];

  if(x==n && y==m)
  {
    dp[x][y]=1 ;
    return 1;
  }

  dp[x][y] = fill(x+1 ,y)+ fill(x,y+1);
  cout<<"Value is dp "<<x<<" "<<y<<dp[x][y]<<endl;
  return dp[x][y];
}

void solve()
{
  cin>>n>>m;
  memset(dp , -1 , sizeof(dp));
  fill(1,1);

  for(int i=1;i<=n ; i++)
  {
    for(int j=1;j<=m ;j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
    solve();
}
