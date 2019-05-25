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
struct Node
{
    Node *l,*r;
    int val;
    void compute()
    {
        val = l->val > r->val ? l->val : r->val;
    }
    Node(int val):val(val),l(nullptr),r(nullptr){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
}*rootc,*rootd;
int c[100005];
int d[100005];
Node *build(int l,int r,int *x)
{
    if(l==r)return new Node(x[l]);
    int md=(l+r)/2;
    return new Node(build(l,md,x),build(md+1,r,x));
}
void reassign(Node *now,int l,int r,int *x)
{
    if(l==r)
    {
        now->val=x[l];
        return;
    }
    int md=(l+r)/2;
    reassign(now->l,l,md,x);
    reassign(now->r,md+1,r,x);
    now->compute();
}
int query(Node *now,int l,int r,int x,int y)
{
    // printf("%d %d %d %d %d\n",l,r,x,y,now->val);
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return now->val;
    int md=(l+r)/2;
    return max(query(now->l,l,md,x,y),query(now->r,md+1,r,x,y));
}
void _main()
{
    sint2(n,k);
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
        int1(c[i]);
    for(int i=1;i<=n;i++)
        int1(d[i]);
    ll ans=0;
    reassign(rootc,1,100000,c);
    reassign(rootd,1,100000,d);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(abs(query(rootc,1,100000,i,j)-query(rootd,1,100000,i,j))<=k)ans++;
        }
    }
    Wl(ans);
}
int main()
{
    sint(t);
    rootc=build(1,100000,c);
    rootd=build(1,100000,d);
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
