/*
problem link : https://www.codechef.com/LTIME103C/problems/CHEF1010
*/


#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
    int n , count_1 , count_0 , mincount;
    cin>>n;
    string s;
    cin>>s;
    count_1 = count(s.begin() , s.end() , '1');
    count_0 = count(s.begin() , s.end() , '0');
    mincount = min(count_1 , count_0);
    if(mincount == 1 || mincount == 0)
    {
      cout<<0<<endl;
    }
    else
    {
      cout<<mincount-1<<endl;
    }
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
