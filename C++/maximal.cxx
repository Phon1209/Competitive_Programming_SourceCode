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
#define pb push_back
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
	char c=getchar();
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
const ll MIN=-4e18;
struct Node
{
    ll pre,suf,mx,sum;
    Node *l,*r;
    void compute()
    {
        pre=max(l->pre,l->sum+r->pre);
        pre=max(MIN,pre);
        suf=max(r->suf,r->sum+l->suf);
        suf=max(MIN,suf);
        mx=max(max(pre,max(l->suf,r->pre)),max(suf,max(l->mx,max(r->mx,l->suf+r->pre))));
        mx=max(MIN,mx);
        sum=l->sum+r->sum;
        sum=max(MIN,sum);
    }
    void setval(ll val)
    {
        pre = val;
        suf = val;
        sum = val;
        mx  = val;
    }
    Node(ll val){
        setval(val);
    }
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
};
Node *build(int l,int r)
{
    if(l==r)return new Node(MIN);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void update(Node *now,int l,int r,int pos,ll val)
{
    if(l==r)
    {
        now->setval(val);
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)update(now->l,l,md,pos,val);
    else update(now->r,md+1,r,pos,val);
    now->compute();
    // printf("%d %d\n",l,r);
    // printf("%d %d %d %d\n",now->pre,now->suf,now->mx,now->sum);
}
struct Command
{
    int ask=0;
    int val;
    int idx;
    Command(int val,int idx,int ask):val(val),idx(idx),ask(ask){}
    bool operator < (const Command &a)
    {
        if(val!=a.val)return val>a.val;
        return ask<a.ask;
    }
};
ll ans[100005];
int main()
{
    vector<Command> v;
    sint2(n,m);
    Node *root=build(1,n);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb({tmp,i+1,false});
    }
    for(int i=0;i<m;i++)
    {
        sint(tmp);
        v.pb({tmp,i+1,true});
    }
    sort(all(v));
    for(int i=0;i<v.size();i++)
        if(v[i].ask)ans[v[i].idx]=(root->mx==MIN)? 0:root->mx;
        else update(root,1,n,v[i].idx,v[i].val);
    FOR(i,1,m+1)W(ans[i]);
    endl;
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
