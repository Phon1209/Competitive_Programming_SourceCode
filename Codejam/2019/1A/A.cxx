#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
int n,m;
int conv(int x,int y)
{
	return m*(x-1)+(y-1);
}
vi v[406];
bitset<405> use;
vi now,ans;
vi mem[22][22];
int able[22][22];
void dfs(int u,int cnt)
{
	// debug(u);
	if(ans.size())return;
	use[u]=1;
	now.pb(u);
	if(cnt==n*m)
	{
		ans=now;
		return;
	}
	for(int y:v[u])
	{
		if(!use[y])
		{
			// printf("go to %d from %d\n",y,u);
			dfs(y,cnt+1);
		}
	}
	now.pop_back();
	use[u]=0;
}
void _main()
{
    int2(n,m);
	if(able[n][m]==0)
	{
		for(int i=0;i<n*m;i++)v[i].clear();
		use.reset();
		now.clear();
		ans.clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=n;k++)
				{
					for(int l=1;l<=m;l++)
					{
						if(i==k)continue;
						if(l==j)continue;
						if(i-j==k-l)continue;
						if(i+j==k+l)continue;
						v[conv(i,j)].pb(conv(k,l));
						// v[conv(k,l)].pb(conv(i,j));

						// debug(conv(i,j));
						// debug(conv(k,l));
					}
				}
			}
		}
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int x=conv(i,j);
				// debug((x));
				dfs(x,1);
			}
		}
		mem[n][m]=ans;
	}
	if(mem[n][m].size())
	{
		able[n][m]=1;
		printf("POSSIBLE\n");
		for(int i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i]/m +1 , ans[i]%m +1);
		}
	}
	else printf("IMPOSSIBLE\n"),able[n][m]=-1;
}
int main()
{
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
