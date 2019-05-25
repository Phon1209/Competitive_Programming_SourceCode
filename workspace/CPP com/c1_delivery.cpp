#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int lim;
int spdis[15][15];
int dis(int x,int y)
{
	if((x<lim)^(y<lim))
	{
		return 1e9;
	}
	if(x>lim)
	{
		x-=lim;
		y-=lim;
	}
	int d=0;
	while(x!=y)
	{
		d++;
		if(y<x) x/=2;
		else y/=2;
	}
	return d;
}
int re[15];
int main()
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			spdis[i][j]=1e9;
		}
	}
	sint3(n,m,p);
	lim=(1<<n);
	for(int i=1;i<=m;i++)
	{
		int2(re[i],re[i+m]);
		spdis[i][i]=spdis[i+m][i+m]=0;
		spdis[i][i+m]=spdis[i+m][i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			spdis[i][j]=spdis[j][i]=dis(re[i],re[j]);
//			printf("%d %d %d\n",i,j,spdis[i][j]);
		}
	}
	///*
	for(int i=m+1;i<=2*m;i++)
	{
		for(int j=i+1;j<=2*m;j++)
		{
			spdis[i][j]=spdis[j][i]=dis(re[i],re[j]);
		}
	}
	//*/
	/*
	for(int i=1;i<=2*m;i++)
	{
		for(int j=1;j<=2*m;j++)
		{
			printf("%d ",spdis[i][j]);
		}
		endl;
	}pause;
	*/
	
	for(int k=1;k<=2*m;k++)
		for(int i=1;i<=2*m;i++)
		{
			for(int j=1;j<=2*m;j++)
			{
					spdis[i][j]=min(spdis[i][j],spdis[i][k]+spdis[k][j]);
			}
		}
	/*
	for(int i=1;i<=2*m;i++)
	{
		for(int j=1;j<=2*m;j++)
		{
			printf("%d ",spdis[i][j]);
		}
		endl;
	}pause;
	*/
	while(p--)
	{
		sint2(x,y);
		int ans=inf;
		if(y<x) swap(x,y);
		if(((x<lim)==(y<lim)))
		{
			ans=min(ans,dis(x,y));
			if(x<lim)
			{
				for(int i=1;i<=m;i++)
				{
					for(int j=1;j<=m;j++)
					{
						ans=min(ans,dis(re[i],x)+spdis[i][j]+dis(y,re[j]));
					}
				}
			}
			else
			{
				for(int i=m+1;i<=2*m;i++)
				{
					for(int j=m+1;j<=2*m;j++)
					{
						ans=min(ans,dis(re[i],x)+spdis[i][j]+dis(y,re[j]));
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=2*m;i++)
			{
				for(int j=1;j<=2*m;j++)
				{
					ans=min(ans,dis(re[i],x)+spdis[i][j]+dis(y,re[j]));
				}
			}
		}
		printf("%d\n",ans);
	}
}

