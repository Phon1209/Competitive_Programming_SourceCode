#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> > q;
priority_queue<int> c;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	while(n--)
	{
		int s,t;
		scanf("%d %d",&s,&t);
		q.push(make_pair(-s,-t));
	}
	while(c.size()!=m)
	{
		int x,y;
		x=-q.top().first;
		y=-q.top().second;
		c.push(-(x+y));
		q.pop();
//		printf("A\n");
	}
	long long ans=0;
	while(!q.empty())
	{
		int x,y,z;
		x=-q.top().first;
		y=-q.top().second;
		q.pop();
		z=-c.top();
		c.pop();
		ans=max((long long)z,ans);
//		printf("%lld\n",ans);
		if(z>=x)
		{
			c.push(-(z+y));
		}
		else
		{
			c.push(-(x+y));
		}
	}
	while(!c.empty())
	{
		int z=-c.top();
		ans=max((long long)z,ans);
		c.pop();
	}
	printf("%lld\n",ans);
}
