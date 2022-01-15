/*
problem link : https://www.codechef.com/LTIME103C/problems/MXMTRIO
*/


#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    vector<long long> a(n);
    for(int i= 0; i< n; i++) cin>>a[i];
    sort(a.begin() , a.end());
    cout<<(a[n-1] - a[0])*a[n-2]<<endl;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}
