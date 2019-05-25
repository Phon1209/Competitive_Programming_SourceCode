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
#define MOD (1ll*1000000007)
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
    ll hsh,val,ans;
    int x,y;
    Node *l,*r;
    void compute()
    {
        val = l->val + r->val;
        hsh = l->hsh * 13 + r->hsh;
        int md=(x+y)/2;
        // debug(l->ans);
        // debug(r->ans);
        ans = (l->ans + ((r->ans)*(1ll<<(md-x+1))%MOD)%MOD)%MOD;
    }
    void copy(Node *a)
    {
        l=a->l;
        r=a->r;
        hsh = a->hsh;
        ans = a->ans;
        val = a->val;
        x = a->x;
        y = a->y;
    }
    Node(int val,int x,int y):l(nullptr),r(nullptr),x(x),y(y){
        ans=this->val=hsh=val;
    }
    Node(Node *l,Node *r):l(l),r(r){
        x=l->x;
        y=r->y;
        compute();
    }
    Node(Node *a):l(a->l),r(a->r){
        x=a->x;
        y=a->y;
        compute();
    }
    bool operator <(Node &a);
};
Node *zero,*one;
Node *build(int l,int r,int val)
{
    if(l==r)return new Node(val,l,r);
    int md=(l+r)/2;
    return new Node(build(l,md,val),build(md+1,r,val));
}
bool cmp(Node *a,Node *b,int l,int r)
{
    if(l==r)
        return (a->hsh < b->hsh);
    int md=(l+r)/2;
	debug(a->r->hsh);
	debug(b->r->hsh);
    if(a->r->hsh == b->r->hsh)return cmp(a->l,b->l,l,md);
    return cmp(a->r,b->r,md+1,r);
}
int sum(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return now->val;
    int md=(l+r)/2;
    return sum(now->l,l,md,x,y)+sum(now->r,md+1,r,x,y);
}
Node *setzero(Node *now,int l,int r,int x,int y,Node *zero)
{
    if(y<l || x>r)return now;
    Node *New=new Node(now);
    if(x<=l && r<=y)
        return zero;
    int md=(l+r)/2;
    New->l=setzero(now->l,l,md,x,y,zero->l);
    New->r=setzero(now->r,md+1,r,x,y,zero->r);
    New->compute();
    return New;
}
Node *setone(Node *now,int l,int r,int pos,Node *zero)
{
    if(l==r)return new Node(1,l,r);
    Node *New=new Node(now);
    int md=(l+r)/2;
    if(pos>l)
    {
        if(pos<=md)
        {
            if(sum(now,l,r,pos,md)!=(md-pos+1))
            {
                New->l=setone(now->l,l,md,pos,zero->l);
            }
            else
            {
                New->l=setzero(now->l,l,md,pos,md,zero->l);
                New->r=setone(now->r,md+1,r,pos,zero->r);
            }
        }
        else
        {
            New->r=setone(now->r,md+1,r,pos,zero->r);
        }
    }
    else
    {
        if(New->l->val!=md-l+1)
        {
            New->l=setone(now->l,l,md,pos,zero->l);
        }
        else
        {
            New->l=setzero(now->l,l,md,l,md,zero->l);
            New->r=setone(now->r,md+1,r,pos,zero->r);
        }
    }
    New->compute();
    // printf("%d %d\n",l,r);
    // Wl(New->val);
    // Wl(New->ans);
    return New;
}
bool Node::operator < (Node &a)
{
    return cmp(this,&a,0,200000);
}
vii v[100005];
Node *g[100005];
int p[100005];
int main()
{
    sint2(n,m);
    zero = build(0,200000,0);
    one = build(0,200000,1);
    for(int i=0;i<=100000;i++)g[i]=one;
    for(int i=0;i<m;i++)
    {
        sint3(x,y,w);
        v[x].pb(y,w);
        v[y].pb(x,w);
    }
    sint2(s,t);
    priority_queue<tuple<Node*,int> > pq;
    pq.push(mkt(zero,s));
    while(!pq.empty())
    {
        Node *w;
        int u;
        tie(w,u)=pq.top();
        pq.pop();
        debug(u);
		debug(w->ans);
		debug(w->val);
		debug(g[u]->ans);
		debug(g[u]->val);
        if(cmp(g[u],w,0,200000))continue;
        g[u]=w;
        if(u==t)
        {
            Wl(w->ans);
            break;
        }
        debug((1));
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            int cost=v[u][i].S;
            debug(y);
            debug(cost);
            Node *tmp=setone(w,0,200000,cost,zero);
            debug(tmp->ans);
            debug(tmp->val);
            debug(2);
			pause;
			debug(g[y]->ans);
			debug(g[y]->val);
            if(cmp(tmp,g[y],0,200000))
            {
                debug(3);
                g[y]=tmp;
                p[y]=u;
                pq.emplace(g[y],y);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("p[%d] = %d\n",i,p[i]);
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
