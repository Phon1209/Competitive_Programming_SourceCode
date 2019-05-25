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
#define IN( x )
#define OUT( x )
#else
#define IN( x ) freopen(x,"r",stdin);
#define OUT( x ) freopen(x,"w",stdout);
#endif
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
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

int now, use;
vector<pair<ii, int> > v[2];
int rnk[200005];

inline void suffix_array(const string &s )
{
	for(int i = 0 ; i < s.size() ; i++)
	{
		v[ 0 ].pb(mkp(0, s[ i ] - 'a'), i);
	}
	sort(all(v[ 0 ]));
	int cnt = 0;
	for(int i = 0 ; i < v[ 0 ].size() ; i++)
	{
		int u = v[ 0 ][ i ].S;
		rnk[ u ] = (i != 0 && v[ 0 ][ i ].F == v[ 0 ][ i - 1 ].F)? cnt : ++cnt;
	}
	now = 0;
	for(int t = 1 ; t <= s.size() ; t <<= 1)
	{
		now ^= 1;
		v[ now ].clear();
		for(int i = 0 ; i < s.size() ; i++)
		{
			int u = v[ now ^ 1 ][ i ].S;
			v[ now ].pb(mkp(rnk[ u ], rnk[ u + t ]), u);
		}
		sort(all(v[ now ]));
		cnt = 0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			int u = v[ now ][ i ].S;
			rnk[ u ] = (i != 0 && v[ now ][ i ].F == v[ now ][ i - 1 ].F)? cnt : ++cnt;
		}
		use = now;
		if(cnt == s.size())break;
	}
}
int prv[100005];
inline void genprev(int n)
{
	prv[v[use][0].S]=-1;
	for(int i=1;i<n;i++)
	{
		prv[v[use][i].S]=v[use][i-1].S;
	}
}
int lcp[100005];
int main()
{
	sstring(s);
	suffix_array(s);
	genprev(s.size());
	int l=0;
	for(int i=0;i<s.size();i++)
	{
		if(prv[i]==-1)continue;
		while((i+l<s.size() && prv[i]+l<s.size()) && s[i+l]==s[prv[i]+l])l++;
		lcp[i]=l;
		l=max(l-1,0);
	}
	sint(q);
	while(q--)
	{
		sint(tmp);
		int ans=0,cnt=0;
		for(int i=0;i<v[use].size();i++)
		{
			if(lcp[v[use][i].S]>=tmp)cnt++;
			else cnt=0;
			ans=max(ans,cnt);
		}
		Wl(ans+1);
	}
}
/*

*/