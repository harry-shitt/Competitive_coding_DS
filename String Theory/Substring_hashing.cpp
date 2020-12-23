#include<bits/stdc++.h>

using namespace std;
long long inverse[1001] , dp[1001];
int mod =1000009;

long long power(long long a ,long long n)
{
  long long res=1;
  while(n)
  {
    // cout<<a<<" "<<res<<" "<<n<<endl;
    if(n%2==0)
    {
      n/=2;
      a = ((a%mod)*(a%mod))%mod;;
    }
    else
    {
      n--;
      res  =  ((res%mod)*(a%mod))%mod;
    }
  }
  return res;
}

long long subhash(int l ,int r)
{
  long long result;
  result = dp[r]-dp[l];
  result = (result*inverse[l])%mod;
  return result;
}

hash_value(string s)
{
  long long p = 53;
  long long int p_power=1;
  dp[0] = s[0]-'a'+ 1;
  inverse[0]=1;
  for(int i=1;i < s.size();i++)
  {
      char c = s[i];
      p_power = (p_power%mod * p%mod)%mod;
      // cout<<power(p_power , mod-2)<<endl;;
      inverse[i] = power(p_power , mod-2);
      dp[i] = dp[i-1] + ((c-'a'+1)*p_power)%mod;
  }
}


int main(void)
{
  int t,l,r;
  cin>>t;
  string s;
  while(t--)
  {
    cin>>s;
    hash_value(s);
    // for(int i=0;i<=s.size() ; i++)
    // {
    //   cout<<inverse[i]<<" ";
    // }
    cin>>l>>r;
    long long sub_hash = subhash(l,r);
    cout<<sub_hash<<endl;
  }

  return 0;
}
