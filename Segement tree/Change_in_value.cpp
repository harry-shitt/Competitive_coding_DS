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
int arr[100001];
// odd even
std::pair<int ,int> st[400001];
void build(int si , int ss , int se)
{
	if(ss == se)
	{
    if(arr[ss]%2==1)
    {
      st[si]= {1,0};
    }
    else
    {
      st[si] = {0,1};
    }
		return;
	}

	int mid = (ss + se)/2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);

	st[si].first = st[si*2].first + st[(si*2)+1].first;
  st[si].second = st[si*2].second+ st[(si*2)+1].second;
}

void update(int index , int start ,int end , int changeindex ,int changevalue)
{
  if(start == end)
  {
    if(changevalue%2==1)
    {
      st[index] = {1,0};
    }
    else
    {
      st[index] = {0,1};
    }
    arr[start]=changevalue;
    return;
  }
  int mid =(start+end)/2;
  if(changeindex <= mid) update(2*index , start ,mid , changeindex, changevalue);
  else update(2*index+1 , mid+1 ,end , changeindex, changevalue);


  st[index].first = st[2*index].first + st[2*index+1].first;
  st[index].second = st[2*index].second + st[2*index+1].second;
}

int getEven(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	 return st[si].ss;

	int mid = (ss + se) / 2;

	int l = getEven(2*si , ss , mid , qs , qe);
	int r = getEven(2*si+1 , mid+1 , se , qs , qe);

	return l+r;
}


int getOdd(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;

	if(ss >= qs && se <= qe)
	return st[si].ff;

	int mid = (ss + se) / 2;

	int l = getOdd(2*si , ss , mid , qs , qe);
	int r = getOdd(2*si+1 , mid+1 , se , qs , qe);

	return l+r;
}


int main()
{
	int n , q;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>arr[i];
	cin>>q;
	build(1 , 1 , n);
	while(q--)
	{
		int code,x,y;
    cin>>code;
    if(code==0)
    {
      cin>>x>>y;
      if((y%2) != (arr[x]%2))
      {
        update(1,1,n,x,y);
      }
    }
    else if(code==1)
    {
          cin>>x>>y;
          cout<<getEven(1,1,n,x,y)<<endl;
    }
    else if(code ==2)
    {
      cin>>x>>y;
      cout<<getOdd(1,1,n,x,y)<<endl;
    }
	}
}
