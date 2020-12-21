
#include<bits/stdc++.h>

using namespace std;


long long Hash(string s)
{
  long long hash_value = 0;
  long long p =53;
  long long m = 1e9+9;
  long long power=1;
  for(char c : s)
  {
    hash_value += (hash_value + (c-'a'+1)*power)%m;
    power = power*p %m;
  }
  return hash_value%m;
}



int main(void)
{
  int t;
  cin>>t;
  while(t--)
  {
    string a,b;
    cin>>a>>b;
    long long var_a =Hash(a) ;
    long long var_b = Hash(b);
    cout<<"Hash Value of String 1 is "<<var_a<<endl;
    cout<<"Hash Value of String 2 is "<<var_b<<endl;
    if(var_a == var_b)
    {
      cout<<"Strings are Equal"<<endl;
    }
    else
    {
      cout<<"Strins are not Equal"<<endl;
    }
  }
  return 0;
}
