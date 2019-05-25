#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> v;
int main()
{
	int n,m;
	int s;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s);
		s+=999;
		mp[s]=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&s);
		if(mp.find(s)!=mp.end())
		{
			v.push_back(s);
		}
	}
	if(v.size()!=0)
		printf("%d\n",v.size());
	else
		printf("No\n");
	for(int i=0;i<v.size();i++)
	{
		printf("%d\n",v[i]);
	}
}
