#include<bits/stdc++.h>
using namespace std;
int a[155][155],b[155][155];
int me[]={1,-1,0,0},mu[]={0,0,1,-1};
queue<pair<int,int> > q;
void bfs(int);
int m,n; // border of map;
int main()
{

	scanf("%d %d",&m,&n);
	int x,y,d,r;
	scanf("%d %d",&x,&y);
	scanf("%d %d",&d,&r);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=-1;
		}
	}
	q.push(make_pair(x,y));
	b[x][y]=1;
	b[d][r]=1;
	bfs(2);
	q.push(make_pair(d,r));
	bfs(3);
	/*
	printf("\n");
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	//*/
	bool chk1,chk2;
	int cnt=0,chk3=0,chk4=0,chk=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			chk1=false;
			chk2=false;
			chk3=0,chk4=0;
			for(int k=0;k<4;k++)
			{
				if(a[i+mu[k]][j+me[k]]==2)
				{
					chk1=true;
					if(b[i+mu[k]][j+me[k]]<chk3 || chk3==0)
						chk3=b[i+mu[k]][j+me[k]];	
				}
				if(a[i+mu[k]][j+me[k]]==3)
				{
					chk2=true;
					if(b[i+mu[k]][j+me[k]]<chk4 || chk4==0)
						chk4=b[i+mu[k]][j+me[k]];
				}
			}
			if(chk1 && chk2)
			{
				cnt++;
				if(chk==0 || (chk3+chk4+1)<chk)
					chk=chk3+chk4+1;
			}
		}
	}
	printf("%d\n%d",cnt,chk);
}
void bfs(int s)
{
	int x,y;
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		a[x][y]=s;
		for(int i=0;i<4;i++)
		{
			if((x+mu[i]<=m && x+mu[i]>0 && y+me[i]<=n && y+me[i]>0) && a[x+mu[i]][y+me[i]]==1 && b[x+mu[i]][y+me[i]]==-1)
			{
				b[x+mu[i]][y+me[i]]=b[x][y]+1;
				q.push(make_pair(x+mu[i],y+me[i]));
			}
		}
	}
}
