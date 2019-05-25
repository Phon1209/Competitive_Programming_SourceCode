#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
char a[35][35];
int mu[]={1,0,0,-1},me[]={0,-1,1,0};
int main()
{
	sint2(n,m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='#')
			{
				if(a[i-1][j]=='.')
					a[i-1][j]='S';
				if(a[i+1][j]=='.')
					a[i+1][j]='S';	
				if(a[i][j+1]=='.')
					a[i][j+1]='S';
				if(a[i][j-1]=='.')					
					a[i][j-1]='S';
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
	*/
	queue<ii> q;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='.')
			{
//				printf("A\n");
				a[i][j]='A';
				int cnt=0;
				q.push(mkp(i,j));
				while(!q.empty())
				{
					int x,y;
					x=q.front().F;
					y=q.front().S;
					q.pop();
//					printf("%d\n",q.size());
//					printf("%d %d\n",x,y);
//					printf("B\n");
					cnt++;
					for(int k=0;k<4;k++)
					{
						if(a[x+mu[k]][y+me[k]]=='.' && (x+mu[k]>=0 && x+mu[k]<n && y+me[k]>=0 && y+me[k]<m))
						{
//							printf("C\n");
							a[x+mu[k]][y+me[k]]='A';
							q.push(mkp(x+mu[k],y+me[k]));
						}
					}
//					system("pause");
				}
				ans=max(ans,cnt);
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
	//*/
	printf("%d\n",ans);
}

