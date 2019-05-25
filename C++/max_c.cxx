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
    int val;
    Node *l,*r;
    void compute()
    {
        val = l->val + r->val;
    }
    Node(Node *x):l(x->l),r(x->r),val(x->val){}
    Node(int val):val(val){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
};
Node *build(int l,int r)
{
    if(l==r)return new Node(0);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
Node *upt(Node *now,int l,int r,int pos,int val)
{
    Node *New = new Node(now);
    int md=(l+r)/2;
    if(l==r)
    {
        New->val+=val;
        return New;
    }
    if(pos<=md)New->l=upt(now->l,l,md,pos,val);
    else New->r=upt(now->r,md+1,r,pos,val);
    New->compute();
    return New;
}
int query(Node *a,Node *b,int l,int r,int k)
{
    debug(l);
    debug(r);
    if(l==r)return l;
    int md=(l+r)/2;
    int u=a->l->val - b->l->val;
    debug(u);
    debug(k);
    if(k<=u)return query(a->l,b->l,l,md,k);
    return query(a->r,b->r,md+1,r,k-u);
}
Node *ver[100005];
int a[100005];
map<int,int> re,rev;
int main()
{
    sint2(n,q);
    vii v;
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
        v.pb(mkp(a[i],i));
    }
    sort(all(v));
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        re[v[i].F]=++cnt;
        rev[cnt]=v[i].F;
    }
    ver[0]=build(1,n);
    for(int i=0;i<n;i++)
    {
        ver[i+1]=upt(ver[i],1,n,re[a[i]],1);
    }
    while(q--)
    {
        sint3(x,y,k);
        k=((y-x+1)-k+1);
        debug(k);
        Wl(rev[query(ver[y],ver[x-1],1,n,k)]);
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
