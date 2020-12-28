#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int a[100] , st[400];
void build(int index ,int start ,int end)
{
	if(start == end)
  {
    st[index] = a[start];
    return;
  }


  int mid = (start + end)/2;
  build(2*index , start , mid);
  build(2*index+1 , mid+1 , end);
  st[index] = min(st[index*2] , st[index*2+1]);

}

int query(int index , int start , int end ,int ql , int qr)
{
	if(start > qr || end<ql) return INT_MAX;


  if(start <=ql && end>=qr) return st[index];


  int mid=(start+end)/2;

  int l = query(2*index , start ,mid , ql ,qr);
  int r = query(2*index+1 , mid+1 ,end , ql ,qr);
  return min(l,r);

}
int main()
{
	int n,q,l,r;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  build(1,1,n);
  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    cout<<query(1,1,n,l+1,r+1)<<endl;
  }

}
