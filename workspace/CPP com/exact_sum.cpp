#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
map<int,int>::iterator it;
vector<int> v;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int q;
		scanf("%d",&q);
		v.push_back(q);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mp[v[i]+v[j]]++;
		}
	}
	it=mp.begin();
	long long cnt=0;
	while(it!=mp.end())
	{
//		printf("%d\n",(*it).second);
		cnt+=(mp[m-(*it).first]*(*it).second);
		it++;
	}
	printf("%lld\n",cnt);
}
