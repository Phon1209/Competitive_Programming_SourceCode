#include<bits/stdc++.h>

using namespace std;
#define sint( a ) int a; scanf("%d",&a);
#define sint2( a, b ) int a,b; scanf("%d %d",&a,&b);
#define sint3( a, b, c ) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1( a ) scanf("%d",&a);
#define int2( a, b ) scanf("%d %d",&a,&b);
#define int3( a, b, c ) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
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
#define debug( x ) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN( x ) freopen(x,"r",stdin);
#define OUT( x ) freopen(x,"w",stdout);

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[100005];
struct Node{
	ll val, cnt;
	Node *l, *r;
	
	Node( ll val, ll cnt, Node *l, Node *r ):
			val(val), cnt(cnt), l(l), r(r)
	{}
	
	void compute()
	{
		val = l->val + r->val;
		cnt = l->cnt + r->cnt;
	}
};

Node *build( int l, int r )
{
	if(l == r) return new Node(0, 0, nullptr, NULL);
	int md = (l + r) / 2;
	return new Node(0, 0, build(l, md), build(md + 1, r));
}

Node *upt( Node *now, int l, int r, int pos, ll val )
{
	Node *New = new Node(now->val, now->cnt, now->l, now->r);
	if(l == r)
	{
		New->val += val;
		New->cnt += 1;
		// printf("%d %d %lld %lld\n",l,r,New->val,New->cnt);
		return New;
	}
	int md = (l + r) / 2;
	if(pos <= md)New->l = upt(now->l, l, md, pos, val);
	else New->r = upt(now->r, md + 1, r, pos, val);
	New->compute();
	// printf(">>%lld %lld\n",now->val,now->cnt);
	return New;
}

int query( Node *A, Node *B, int l, int r, double sum, int cnt, double value )
{
	if(l == r)
	{
		if(sum / cnt >= value)return 0;
		else if(((sum - ( double )(A->val - B->val)) / (cnt - (A->cnt - B->cnt))) >= value)
			return static_cast<int>(A->cnt - B->cnt);
		else return INT_MIN;
	}
	int md = (l + r) / 2;
	// debug((sum-(double)(A->l->val - B->l->val))/(cnt-( A->l->cnt - B->l->cnt )));
	if(((sum - ( double )(A->l->val - B->l->val)) / (cnt - (A->l->cnt - B->l->cnt))) >= value)
		return query(A->l, B->l, l, md, sum, cnt, value);
	else
		return static_cast<int>((A->l->cnt - B->l->cnt) + query(A->r, B->r, md + 1, r,
																sum - ( double )(A->l->val - B->l->val),
																static_cast<int>(cnt - (A->l->cnt - B->l->cnt)),
																value));
}

ll qs[100005];
int rnk[100005];
Node *R[100005];

int main()
{
	sint2(n, m);
	vii v;
	for(int i = 1 ; i <= n ; i++)
	{
		int1(a[ i ]);
		qs[ i ] = qs[ i - 1 ] + a[ i ];
		v.pb(mkp(a[ i ], i));
	}
	sort(all(v));
	for(int i = 0 ; i < n ; i++)
	{
		rnk[ v[ i ].S ] = i + 1;
	}
	R[ 0 ] = build(1, n);
	for(int i = 1 ; i <= n ; i++)
	{
		R[ i ] = upt(R[ i - 1 ], 1, n, rnk[ i ], a[ i ]);
	}
	while(m--)
	{
		sint2(x, y);
		sdouble(k);
		int ret = query(R[ y ], R[ x - 1 ], 1, n, qs[ y ] - qs[ x - 1 ], y - x + 1, k);
		printf("%d\n", ret < 0? -1 : ret);
	}
}
/*
11 3
6
5
4
3
2
1
2
3
4
5
6
1 11 3
2 10 3.55
5 8 3.5
*/
