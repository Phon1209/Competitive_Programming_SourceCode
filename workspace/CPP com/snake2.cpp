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
#define inf 1e9
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
int a[10005];
vii v[10005];
ll g[10005][205];
int main()
{
	sint3(n,m,x);
	for(int i=1;i<=n;i++)
	{
		int1(a[i]);
	}
	for(int i=0;i<m;i++)
	{
		sint3(x,y,w);
		v[x].pb(mkp(y,w));
		v[y].pb(mkp(x,w));
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			g[i][j]=inf;
		}
	}
	priority_queue<pair<ii,ii> > pq;
	pq.push(mkp(mkp(0,1),mkp(x,0)));
	while(!pq.empty())
	{
		int u,now,delay;
		long long w=-pq.top().F.F;
		u=pq.top().F.S;
		now=pq.top().S.S;
		delay=pq.top().S.F;
		pq.pop();
		if(w>g[u][delay])
			continue;
		g[u][delay]=w;
//		printf("%d %lld %d %d\n",u,w,now,delay);
//		pause;
		if(u==n)
		{
			printf("%lld\n",w);
			break;
		}
		for(int i=0;i<v[u].size();i++)
		{
			int go=v[u][i].F;
			long long road=v[u][i].S;
//			printf(">%d %lld %d %d\n",go,road,a[go],now);
			if(delay-road>0)
			{		
				if(now==0)
				{
					if(a[go]!=2)
					{
						if(a[go]==0)
						{
							if(w+road<g[go][x])
							{
								g[go][x]=w+road;
								pq.push(mkp(mkp(-(w+road),go),mkp(x,0)));
							}
						}
						else
						{
							if(w+road<g[go][max((long long)0,delay-road)])
							{
								g[go][max((long long)0,delay-road)]=w+road;
								pq.push(mkp(mkp(-(w+road),go),mkp(max((long long)0,delay-road),0)));
							}
						}
					}
				}
				else if(now==2)
				{
					if(a[go]!=0)
					{
						if(a[go]==2)
						{
							if(w+road<g[go][x])
							{
								g[go][x]=w+road;
								pq.push(mkp(mkp(-(w+road),go),mkp(x,2)));
							}
						}
						else
						{
							if(w+road<g[go][max((long long)0,delay-road)])
							{
								g[go][max((long long)0,delay-road)]=w+road;
								pq.push(mkp(mkp(-(w+road),go),mkp(max((long long)0,delay-road),2)));
							}
						}
					}
				}
			}
			else
			{
				if(a[go]==0)
				{
					if(w+road<g[go][x])
					{
						g[go][x]=w+road;
						pq.push(mkp(mkp(-(w+road),go),mkp(x,0)));
					}
				}
				else if(a[go]==2)
				{
					if(w+road<g[go][x])
					{
						g[go][x]=w+road;
						pq.push(mkp(mkp(-(w+road),go),mkp(x,2)));
					}
				}
				else
				{
					if(w+road<g[go][0])
					{
						g[go][0]=w+road;
						pq.push(mkp(mkp(-(w+road),go),mkp(0,1)));
					}
				}
			}
		}
	}
}


