#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,int> > pq;
vector<pair<int,long long> > v[20];
long long a[20];
bool b[20];
long long ce(long long);
int main()
{
	int n,m;
	int s,t;
	long long w,ans;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %lld",&s,&t,&w);
		v[s].push_back(make_pair(t,w));
		v[t].push_back(make_pair(s,w));
	}
//	printf("b");
	for(int i=0;i<v[1].size();i++)
	{
		pq.push(make_pair(-v[1][i].second,v[1][i].first));
	}
	a[1]=0;
	b[1]=true;
//	printf("A");
	while(!pq.empty())
	{
		s=pq.top().second;
		w=-pq.top().first;
		pq.pop();
		if(b[s])
			continue;
		a[s]=w;
		b[s]=true;
//		printf("%d %lld\n",s,w);
		for(int i=0;i<v[s].size();i++)
		{
			if(b[v[s][i].first]==false)
			{
				pq.push(make_pair(-(w+v[s][i].second),v[s][i].first));
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		printf("%d %lld\n",i,a[i]);
	}
	*/
	printf("%lld\n",ce(a[n]));
}
long long ce(long long f)
{
	if(f%5==0)
	{
		return f/5;
	}
	else
	{
		return (f/5)+1;
	}
}
