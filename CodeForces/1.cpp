/*
problem link : https://codeforces.com/problemset/problem/1620/B
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
  long long w , h , k ,a , b , temp;
  long long ans = 0;
  cin>>w>>h;
  cin>>k;
  for(int i =1; i<=k; i++)
  {
    cin>>temp;
    if(i == 1)
    {
      a = temp;
    }
    else if(i ==k)
    {
      b =temp;
    }
  }
  if(ans < (abs(a - b)*h))
  {
    ans = (abs(a - b)*h);
  }
  cin>>k;
  for(int i =1; i<=k; i++)
  {
    cin>>temp;
    if(i == 1)
    {
      a = temp;
    }
    else if(i ==k)
    {
      b =temp;
    }
  }
  if(ans < (abs(a - b)*h))
  {
    ans = (abs(a - b)*h);
  }
  cin>>k;
  for(int i =1; i<=k; i++)
  {
    cin>>temp;
    if(i == 1)
    {
      a = temp;
    }
    else if(i ==k)
    {
      b =temp;
    }
  }
  if(ans < (abs(a - b)*w))
  {
    ans = (abs(a - b)*w);
  }
  cin>>k;
  for(int i =1; i<=k; i++)
  {
    cin>>temp;
    if(i == 1)
    {
      a = temp;
    }
    else if(i ==k)
    {
      b =temp;
    }
  }
  if(ans < (abs(a - b)*w))
  {
    ans = (abs(a - b)*w);
  }
  cout<<(int)ans<<endl;
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
