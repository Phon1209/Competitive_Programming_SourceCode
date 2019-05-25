#include<bits/stdc++.h>

int mu[]={1,-1,0,0};
int me[]={0,0,1,-1};
char a[15][15];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='X')
			{
				int cnt=0;
//				printf("A");
				for(int k=0;k<4;k++)
				{
					if(a[i+mu[k]][j+me[k]]=='X' || a[i+mu[k]][j+me[k]]=='*')
					{
//						printf("A");
						cnt++;
					}
				}
				if(cnt<2)
				{
//					printf("B");
					a[i][j]='*';
				}
			}
		}
	}
	bool chk=false,chk1=false;
	int sx=0,sy=0,ex=n,ey=m;
	/*
	printf("\n");
	for(int i=sx;i<ex;i++)
	{
		for(int j=sy;j<ey;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i=0;i<n;i++)
	{
		chk=false;
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='*')
			{
				a[i][j]='.';
			}
			if(a[i][j]=='X')
			{
				chk=true;
				chk1=true;
			}
		}
		if(!chk)
		{
			if(!chk1)
			{
				sx=i+1;
//				printf("A %d\n",sx);
			}
		}
		else
		{
			ex=i+1;
//			printf("B %d\n",ex);
		}
	}
	chk1=false;
	/*
	printf("\n");
	for(int i=sx;i<ex;i++)
	{
		for(int j=sy;j<ey;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i=0;i<m;i++)
	{
		chk=false;
		for(int j=0;j<n;j++)
		{
			if(a[j][i]=='X')
			{
				chk=true;
				chk1=true;
			}
		}
		if(!chk)
		{
			if(!chk1)
			{
				sy=i+1;
//				printf("A %d\n",sy);
			}
		}
		else
		{
			ey=i+1;
//			printf("B %d\n",ey);
		}
	}
	for(int i=sx;i<ex;i++)
	{
		for(int j=sy;j<ey;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}
