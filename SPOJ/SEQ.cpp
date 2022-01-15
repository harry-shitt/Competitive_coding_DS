#include<bits/stdc++.h>
#define mod 1000000000

using namespace std;


void solve()
{
  int k , n;
  cin>>k;
  vector<long long> avector , bvector(k) , cvector(k);
  for(int i=0 ;i<k;i++)cin>>bvector[i] , avector.push_back(bvector[i]);
  for(int i= 0 ;i<k;i++)cin>>cvector[i];
  cin>>n;
  if(n<=k){cout<<avector[n]<<endl;return;}

  long long powermatrix[k][k];
  memset(powermatrix , 0 , sizeof(powermatrix));
  for(int i=1;i<k;i++)
  {
    powermatrix[i][i-1] = 1;
  }
  for(int i=0;i<k;i++)
  {
    powermatrix[i][k-1] = cvector[i];
  }
  // for(int i =0 ;i <k;i++){for(int j =0 ;j <k;j++)cout<<powermatrix[i][j]<<" ";cout<<endl;}

  int power = n-k;
  long long finalmatrix[k][k] , temp[k][k];
  memset(finalmatrix , 0 , sizeof(finalmatrix));
  for(int i=0; i<k;i++) {finalmatrix[i][i]=1;}

  while(power!=0)
  {
    if(power%2==0)
    {
      for(int i=0;i<k;i++)
      {
        for(int j=0;j<k;j++)
        {
          temp[i][j] = 0;
          for(int l=0;l<k;l++)
          {
            temp[i][j] += ((powermatrix[i][l]%mod)*(powermatrix[l][j]%mod))%mod;
            temp[i][j] %= mod;
          }
        }
      }
      for(int i=0;i<k;i++){for(int j=0;j<k;j++){powermatrix[i][j] = temp[i][j];}}
      power /= 2;
    }
    else
    {
      for(int i=0;i<k;i++)
      {
        for(int j=0;j<k;j++)
        {
          temp[i][j] = 0;
          for(int l=0;l<k;l++)
          {
            temp[i][j] += ((powermatrix[i][l]%mod)*(finalmatrix[l][j]%mod))%mod;
            temp[i][j] %= mod;
          }
        }
      }
      for(int i=0;i<k;i++){for(int j=0;j<k;j++){finalmatrix[i][j] = temp[i][j];}}
      power--;
    }
  }
  long long ans =0 ;
   for(int i =0 ;i <k;i++)
   {
     ans += (avector[k-i]%mod)*(finalmatrix[i][k-1]%mod)%mod;
     ans %= mod;
   }
   for(int i =0 ;i <k;i++){for(int j =0 ;j <k;j++)cout<<finalmatrix[i][j]<<" ";cout<<endl;}
   // cout<<ans<<endl;

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
