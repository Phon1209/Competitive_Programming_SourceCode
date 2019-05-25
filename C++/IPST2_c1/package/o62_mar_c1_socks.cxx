#include<bits/stdc++.h>
#include"sockslib.h"
using namespace std;
// #define DEBUG
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
bitset<100005> chk;
void solve(vi g)
{
	vi g1,g2;
	if(g.size()==0)return;
	if(g.size()==2)
	{
		// std::cerr << "match " << g[0] << " and "<< g[1] << '\n';

		match(g[0],g[1]);
		return;
	}
	vii mat;
	int n=g.size();
	int md=(n/2);
	// std::cerr << "md = " << md << '\n';
	vi p;
	for(int j=md+1;j<g.size();j++)
	{
		p.pb(g[j]);
	}
	int u=ask(p);
	// std::cerr << "u = "<< u << '\n';
	// pause;
	for(int i=0;i<=md;i++)
	{
		int x=g[i];
		vi vx;
		vx=p;
		vx.pb(x);
		int yyy=ask(vx);
		// std::cerr << "yyy = "<< yyy<< '\n';
		if(yyy==u)
		{
			// std::cerr << "get in to bsearch on "<< x << '\n';
			//bsearch
			int l=md+1,r=g.size()-1;
			while(1)
			{
				// std::cerr << "l = "<< l << '\n';
				// std::cerr << "r = "<< r << '\n';
				if(l==r)
				{
					// std::cerr << "match " << x << " and "<< g[l] << '\n';
					mat.pb(x,g[l]);
					chk[x]=1;
					chk[g[l]]=1;
					break;
				}
				vi q;
				int mid=(l+r)/2;
				for(int j=l;j<=mid;j++)
				{
					q.pb(g[j]);
				}
				int expect=ask(q);
				q.pb(x);
				int get=ask(q);
				if(get==expect)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}
		}
		else
		{
			//onsame group
			continue;
		}
		// pause;
	}
	for(int i=0;i<=md;i++)
	{
		int x=g[i];
		if(!chk[x]){g1.pb(x);
			// std::cerr << "push " << x << " to g1" <<  '\n';
		}
	}
	for(int i=md+1;i<g.size();i++){
		int x=g[i];
		if(!chk[x]){g2.pb(x);
			// std::cerr << "push " << x << " to g2" <<  '\n';

		}
	}
	for(int i=0;i<mat.size();i++)
	{
		match(mat[i].F,mat[i].S);
	}
	// pause;
	solve(g1);
	solve(g2);
}
int main()
{
    int n=num();
	// std::cerr << n << '\n';
	vi g;
	// vi v={5,6,3};
	// std::cerr << ask(v) << '\n';
	for(int i=1;i<=2*n;i++)
	{
		g.pb(i);
	}
	solve(g);
}
/*

*/
