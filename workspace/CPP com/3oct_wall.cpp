#include<bits/stdc++.h>
using namespace std;
int mr[]={1,-1,0,0};
int mu[]={0,0,1,-1};
int w,e;
char a[110][110];
void dfs(int x,int y)
{
	a[x][y]='A';
	/*
		for(int i=0;i<=w;i++)
		{
			printf("%s\n",a[i]);
		}
		system("pause");
	//*/
	for(int i=0;i<4;i++)
	{
		if(a[x+mr[i]][y+mu[i]]=='.')
		{
			dfs(x+mr[i],y+mu[i]);
		}
	}
}
int main()
{
	int n,m,cnt=0;
	while(1)
	{
		cnt=0;
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		/*
		w=n;
		e=m;
		//*/
		for(int i=1;i<=n;i++)
		{
			scanf("%s",a[i]);
		}
		dfs(0,0);
		/*
		for(int i=0;i<=n+1;i++)
		{
			printf("%s\n",a[i]);
		}
		//*/
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=m+1;j++)
			{
				if(a[i][j]=='H')
				{
					for(int k=0;k<4;k++)
					{
						if(a[i+mr[k]][j+mu[k]]=='A')
						{
							cnt++;
						}
					}
				}
				
			}
		}
		memset(a,0,sizeof(a));
		printf("%d\n",cnt);
	}
}

