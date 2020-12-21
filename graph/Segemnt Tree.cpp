#include<bits/stdc++.h>
#include<set>
#define MOD 1000000007
#define vi vector<ll>
#define maps map<ll , ll>
#define pb push_back
#define vll vector<long long>
#define ms multiset<int>
#define fo(i,a,n) for(long long i=a;i<=n;i++)
#define ll long long
#define in insert
#define INF 1000000000;
using  namespace std;

1 2 3 4 5 6 7

chef = 1
chefu = 


int n , t[4*100];

int sum (int v, int tl , int tr ,int l , int r)
{
	if(l>r)
	{
		return 0;
	}
	if(l==tl && r==tr)
	{
		return t[v];
	}
	else
	{
		int tm = (tl +tr)/2;
		return sum(v*2 , tl , tm , l ,min(r,tm)) + sum(v*2+1 , tm+1, tr, max(tm+1 ,l) ,r);	
	}
}

void buildtree(int a[] , int vertex , int tl , int tr)
{
	if(tl==tr)
	{
		t[vertex]= a[tl];
	}
	else
	{
		int tm = (tl+ tr)/2;
		buildtree(a , 2*vertex , tl , tm);
		buildtree(a , 2*vertex+1 , tm+1 , tr);
		t[vertex] = t[vertex*2] + t[vertex*2 +1];
	}
}

int main(void)
{
	int a[] = {10 ,2 , 7, 1, 19 , 1 , 0 , 15};
	int v=1;
	buildtree( a , v , 0 , 7);
	for(int i=0  ;i <= 15 ;i++)
	{
		cout<<t[i]<<endl;
	}
	cout<<"Sum from index 2 to 5 is "<<sum(v,1,8,1,5)<<endl;
	return 0;
}
