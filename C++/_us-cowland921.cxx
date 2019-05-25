#include<bits/stdc++.h>

using namespace std;
// #define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint( a ) int a; qread(a);
#define sint2( a, b ) int a,b; qread(a),qread(b);
#define sint3( a, b, c ) int a,b,c; qread(a),qread(b),qread(c);
#define int1( a ) qread(a);
#define int2( a, b ) qread(a),qread(b);
#define int3( a, b, c ) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all( x ) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble( a ) double a; scanf("%lf",&a);
#define slong( a ) long long a; scanf("%lld",&a);
#define cstring( a, x ) char a[x]; scanf("%s",a);
#define sstring( a ) string a;cin>>a;
#define rev( s ) reverse(all(s));
#define FOR( a, b, c ) for(int a=b;a<c;a++)
#define ROF( a, b, c ) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug( x )
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN( x ) freopen(x,"r",stdin);
#define OUT( x ) freopen(x,"w",stdout);
#endif
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;
typedef long long ll;

void qread( int &x )
{
	int neg = 1;
	x = 0;
	register char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')neg = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')x = 10 * x + c - '0', c = getchar();
	x *= neg;
}

void Wl( int x )
{
	printf("%d\n", x);
}

void Wl( double x )
{
	printf("%lf\n", x);
}

void Wl( string x )
{
	printf("%s\n", x.c_str());
}

void Wl( ll x )
{
	printf("%lld\n", x);
}

void W( int x )
{
	printf("%d ", x);
}

void W( double x )
{
	printf("%lf ", x);
}

void W( string x )
{
	printf("%s ", x.c_str());
}

void W( ll x )
{
	printf("%lld ", x);
}
vi v[100005];
int a[100005];
int cost[100005];
int depth[100005];
int ff[100005],lf[100005],cnt=0;
int found[200005],p[20][100005];
void dfs(int u,int dep=1,int par=0)
{
	lf[u]=ff[u]=++cnt;
	found[cnt]=u;
	depth[u]=dep;
	p[0][u]=par;
	for(int i=0;i<v[u].size();i++)
	{
		int y=v[u][i];
		if(depth[y]!=0)continue;
		cost[y]=cost[u]^a[y];
		dfs(y,dep+1,u);
		found[++cnt]=u;
		lf[u]=cnt;
	}
}
int fw[200005];
void add(int x,int val)
{
	for(int i=x;i<=cnt;i+=(i&-i))fw[i]^=val;
}
int sum(int x)
{
	int ret=0;
	for(int i=x;i>0;i-=(i&-i))ret^=fw[i];
	return ret;
}
int lca(int x,int y)
{
	while(x!=y)
	{
		if(depth[x]==depth[y])
		{
			for(int i=18;i>=0;i--)
			{
				if(p[i][x]!=p[i][y])
				{
					x=p[i][x];
					y=p[i][y];
				}
			}
			if(p[0][x]==p[0][y])return p[0][x];
		}
		if(depth[x]<depth[y])swap(x,y);
		x=p[(int)log2(depth[x]-depth[y])][x];
	}
	return x;
}
int main()
{
	IN("cowland.in");
	OUT("cowland.out");
	sint2(n,m);
	for(int i=1;i<=n;i++)
	{
		int1(a[i]);
	}
	for(int i=1;i<n;i++)
	{
		sint2(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	cost[1]=a[1];
	dfs(1);
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j<=n;j++)
			p[i][j]=p[i-1][p[i-1][j]];
	for(int i=1;i<=cnt;i++)
	{
		add(i,cost[found[i]]);
		add(i+1,cost[found[i]]);
	}
	/*
	for(int i=1;i<=cnt;i++)
	{
		printf("at %d found %d and cost %d in sum %d\n",i,found[i],cost[found[i]],sum(i));
	}
	 */
	while(m--)
	{
		sint(cmd);
		sint2(x,y);
		if(cmd==1) // change node x to val y
		{
			add(ff[x],a[x]^y);
			add(lf[x]+1,a[x]^y);
			a[x]=y;
		}
		if(cmd==2) // query from node x to node y
		{
			int LCA=lca(x,y);
			Wl(sum(ff[x])^sum(ff[y])^sum(ff[p[0][LCA]])^sum(ff[LCA]));
		}
		/*
		for(int i=1;i<=cnt;i++)
		{
			printf("at %d found %d and cost %d in sum %d\n",i,found[i],cost[found[i]],sum(i));
		}
		 */
	}
}
/*

*/
