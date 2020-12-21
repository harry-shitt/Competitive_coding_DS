#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[50][50] ,dp[50][50]={0};
solve()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=m+1;i++)
  {
    if(i==m)
    {
      dp[n+1][i] =  0;
    }
    else
    {
      dp[n+1][i]= INF;
    }
  }
  for(int i=1;i<=n+1;i++)
  {
    if(i==n)
    {
      dp[i][m+1] =  0;
    }
    else
    {
      dp[i][m+1]= INF;
    }
  }

  for(int i=n;i>=1;i--)
  {
    for(int j=m ; j>=1;j--)
    {
      dp[i][j] = a[i][j] + min(dp[i+1][j] , dp[i][j+1]);
    }
  }
  for(int i=1;i<=n; i++)
  {
    for(int j=1;j<=m; j++)
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
  solve();
}
