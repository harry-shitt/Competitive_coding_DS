#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    int n , temp ,sum = 0;
    cin>>n;
    unordered_map<int , int> hash_map;
    set<int> s;
    v32 v;
    forn(i,n){
        cin>>temp , s.insert(temp);
        hash_map[temp] = i;
        }
    for(int child: s){
        sum += child;
        v.pb(child);
    }
    int dp[sum+1] = {0};

    for(int i=0;i<v.size();i++)
    {
        if(dp[v[i]] ==0){dp[v[i]] = 1;}
        for(int j=v[i]+1;j<=sum;j++)
        {
            if(dp[j-v[i]] !=0 && dp[j-v[i]] <= i+1 && j-v[i] >= 0)
            {
                dp[j] = dp[j-v[i]]+1;
            }
            if(dp[j-v[i]] == i)
            {
                break;
            }
        }
    }
    int count = -1 ;
    v32 val;
    for(int i=0;i<=sum;i++)
    {
        if(n%i==0 &&dp[i]!=0)
        {
            count==dp[i];
        }
    }
    if(count==-1)
    {
        cout<<-1<<endl;
        return;
    }
    if()
    for(int i=0;i<count;i++)
    {
        cout<<hash_map[v[i]]<<" ";
    }
    cout<<endl;
    
}


int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
     solve();
 }
 return 0;
}