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
#define inf 2e9
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
vector<pair<int,ll> > v[80005];
int pt[80005];
ll gp[80005][15];
priority_queue<pair<ll,pair<int,ii> > > pq;
int main()
{
	sint2(n,m);
	sint2(l,q);
	for(int i=0;i<m;i++)
	{
		sint2(x,y);
		slong(w);
		v[x].pb(mkp(y,w));
//		v[y].pb(mkp(x,w));
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=10;j++)
		{
			gp[i][j]=LLONG_MAX;
		}
		pt[i]=0;
	}
	for(int i=0;i<l;i++)
	{
		sint(tmp);
		pt[tmp]=1;
	}
	// w u po dk
	pq.push(mkp(0,mkp(1,mkp(0,-1))));
	gp[1][0]=0;
	while(!pq.empty())
	{
		ll w=-pq.top().F;
		int u=pq.top().S.F;
		int po=pq.top().S.S.F;
		int dk=pq.top().S.S.S;
		pq.pop();
		if(u==n)
		{
			printf("%lld\n",w);
			break;
		}
		if(gp[u][po]<w) continue;
		gp[u][po]=w;
//		printf(">%d %d %lld\n",u,po,w);
		for(int j=0;j<=pt[u];j++)
		{
			if(j>1 || (j==1 && u==dk)) break;
			if(po+j>q)break;
			for(int i=0;i<v[u].size();i++)
			{
				int d=v[u][i].F;
				ll wg=v[u][i].S;
				int tmp;
				tmp=po+j;
				tmp=(1<<tmp);
				wg/=tmp;
				int r;
				if(j==1)
					r=u;
				else
					r=dk;
				if(gp[d][po+j]>gp[u][po]+wg)
				{
					gp[d][po+j]=gp[u][po]+wg;
					// -w u po dk
					pq.push(mkp(-gp[d][po+j],mkp(d,mkp(po+j,r))));
				}
			}
		}
	}
}

