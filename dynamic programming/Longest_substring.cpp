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
int dp[101][101] ;
// 1 2 4 8 9
void solve()
{
	int n;
	cin>>n;
	char a[n+1];
	for(int i=1; i<=n ;i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<=n;i++)
	{
		dp[0][i] =1;
		dp[1][i] =1;
	}
	
	for(int i=2 ; i<=n ;i++)
	{
		for(int j=i;j<=n ;j++)
		{
			if(a[j] == a[j-i+1] && dp[i-2][j-1]==1)	
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=0;
			}
		}
	}
	for(int i=0 ; i<=n; i++)
	{
		for(int j=0 ;j<=n; j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
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
