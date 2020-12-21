#include<bits/stdc++.h>


using namespace std ; 


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n+1];
		bool dp[m+1];
		for(int i=1 ; i <= n ;i++)
		{
			cin>>a[i];
		}
		dp[0]=1;
		for(int i=1 ; i<=n; i++)
		{
			int element = a[i];
			for(int j = m ; j>=element ; j--)
			{
				if(dp[j]==0 && dp[j-element]==1)
				{
					dp[j]=1;
				}
			}
		}
		for(int i=0; i <= m ;i++)
		{
			cout<<dp[i]<<" ";
		}
		cout<<endl;
		if(dp[m]==1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
