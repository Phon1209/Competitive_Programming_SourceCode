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
int pos[100005];
int val[100005];
int acc[100005];
struct Node
{
	Node *l,*r;
	int val{};
	int lz=0;
	void compute()
	{
		val = max(l->val,r->val);
	}
	void uplz(int lazy)
	{
		lz+=lazy;
		val+=lazy;
	}
	void shift()
	{
		if(lz)
		{
			l->uplz(lz);
			r->uplz(lz);
			lz=0;
		}
	}
	explicit Node (int val):val(val),l(nullptr),r(nullptr),lz(0){}
	Node(Node *l,Node *r):l(l),r(r),lz(0){
		compute();
	}
};
void update(Node *now,int l,int r,int x,int y,int val)
{
	if(y<l || x>r)return;
	if(x<=l && r<=y)
	{
		now->uplz(val);
		return;
	}
	int md=(l+r)/2;
	now->shift();
	update(now->l,l,md,x,y,val);
	update(now->r,md+1,r,x,y,val);
	now->compute();
}
Node *build(int l,int r)
{
	if(l==r)return new Node(0);
	int md=(l+r)/2;
	return new Node(build(l,md),build(md+1,r));
}

int main()
{
	sint3(n,h,l);
	for(int i=0;i<n;i++)
	{
		int2(pos[i],val[i]);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt<n && pos[cnt]-h<=pos[i])
			acc[cnt++]=i;
		if(cnt==n)break;
	}
	// acc[i] mean banner i can access from banner acc[i] to banner i
	vii v;
	Node *root=build(1,100000);
	for(int i=0;i<n;i++)
		v.pb(val[i],i);
	sort(all(v));
	cnt=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		// check on banner that has lowest height first
		while(cnt<n && v[cnt].F-l<=v[i].F)
		{
			update(root,1,100000,acc[v[cnt].S],v[cnt].S,1);
			cnt++;
		}
		ans=max(ans,root->val);
		update(root,1,100000,acc[v[i].S],v[i].S,-1);
	}
	Wl(ans);
}
/*

*/
