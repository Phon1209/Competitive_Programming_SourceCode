#include<bits/stdc++.h>
using namespace std;
vector<int> v[50005];
queue<int> q;
int a[50005];
void bfs();
bool chk=true;
int n,m;
int cnt=0,ca=0,cb=0;
int main()
{
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=0;i<=n;i++)
	{
		a[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			ca=0;cb=0;
			a[i]=1;
			q.push(i);
			bfs();
			if(ca>cb)
				cnt+=ca;
			else
				cnt+=cb;
		}
		if(!chk)
		{
			break;
		}
	}
	if(!chk)
		printf("-1\n");
	else
	{
		printf("%d\n",cnt);
	}
		
}
void bfs()
{
	int s;
	while(!q.empty())
	{
		s=q.front(); q.pop();
		/*
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",i,a[i]);
		}
		printf("\n");
		//*/
		if(a[s]==1)
			ca++;
		else if(a[s]==0)
			cb++;
		for(int i=0;i<v[s].size();i++)
		{
			if(a[v[s][i]]==-1)
			{
				a[v[s][i]]=((a[s]+1)%2);
				q.push(v[s][i]);
			}
			else if(a[v[s][i]]!=((a[s]+1)%2))
			{
				chk=false;
				break;
			}
		}
		if(!chk)
			break;
	}
}

