#include<bits/stdc++.h>
#include<cmath>
#include<set>
#define mod 1000000007
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
int a[2][2] = {{0,1},{1,1}},I[2][2]={{1,0},{0,1}};


void mul()
{
	int res[2][2] = {{0,0},{0,0}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;i<2;j++)
		{
			for(int k=0;k<2;k++) res[i][j] += I[i][k]*a[k][j];
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			I[i][j]=res[i][j];
		}
	}
}





ll power(ll n)
{
	while(n--)
	{
		if(n%2)
		{
			mul();
			n--;
		}
		else
		{
			mul();
			n/=2;
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=I[i][j];
		}
	}
	return a[0][1]+a[1][1];
}




void solve()
{
	int n;
	cin>>n;
	if(n>2)
	{
		cout<<n<<endl;
	}
	else
		cout<<power(n-2)<<endl;
}



int main (void)
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
