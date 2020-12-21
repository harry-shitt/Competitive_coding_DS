#include<bits/stdc++.h>

using namespace std ; 
const int N = 100;
int lp[N+1];
vector<int> pr;

int main(void)
{

	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
	for(int i=2;i<=N;i++)
	{
		cout<<lp[i]<<endl;
	}
	
	return 0;
}
