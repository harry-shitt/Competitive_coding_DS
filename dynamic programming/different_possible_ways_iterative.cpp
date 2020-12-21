#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dp[101][101];
void solve()
{
  int n,m;
  cin>>n>>m;
  memset(dp , -1 , sizeof(dp));
  for(int i=1;i<=n ;i++)
  {
    dp[i][m]=1;
  }
  for(int i=1;i<=m ;i++)
  {
    dp[n][i]=1;
  }
  for(int i=n-1;i>=1;i--)
  {
    for(int j=m-1;j>=1;j--)
    {
      dp[i][j] = dp[i+1][j] + dp[i][j+1];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
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
