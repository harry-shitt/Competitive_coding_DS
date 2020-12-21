#include<bits/stdc++.h>

using namespace std;

/*
instead of going node through node
we 'll sipmly change the parent pointer .

*/

int find(node)
{
	vector<int>  v;
	while(parent[node]>0)
	{
		v.push_back(node);
		node= parent[node];
	}
	for(int i=0 ; i<v.size() ; i++)
	{
		parent[v[i]] = a;
	}
	return a;
}



// Recursive method


int rfind(int node)
{
	if(parent[node]<0)
	{
		return a;
	}
	
	
	
	return parent[node] = rfing(parent[node]);
}

int main(void)
{
	
	return 0;
}
