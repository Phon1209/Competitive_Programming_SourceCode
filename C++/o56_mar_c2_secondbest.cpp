#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
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
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vector<pair<ii,ii> > v;
bitset<200005> ban;
struct Node
{
    int val;
    Node *l,*r;
    Node(int val,Node *l,Node *r):
        val(val),l(l),r(r){}
    Node(Node *a)
    {
        val=a->val;
        l=a->l;
        r=a->r;
    }
    void compute()
    {
        val=l->val+r->val;
    }
};
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+5,0);
        for(int i=1;i<=n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return (fs(i)==fs(j));
    }
    void us(int i,int j)
    {
        int x,y;
        x=fs(i);
        y=fs(j);
        p[x]=y;
    }
};
int p[20][100005];
int lv[100005],M;
vii g[100005];
Node *R[100005];
Node *build(int l,int r)
{
    if(l==r)return new Node(0,NULL,NULL);
    int md=(l+r)/2;
    return new Node(0,build(l,md),build(md+1,r));
}
Node *upt(Node *now,int l,int r,int pos,int val)
{
    Node *New=new Node(now);
    if(l==r){
        New->val+=val;
        return New;
    }
    int md=(l+r)/2;
    if(pos<=md) New->l=upt(now->l,l,md,pos,val);
    else        New->r=upt(now->r,md+1,r,pos,val);
    New->compute();
    return New;
}
int query(Node *A,Node *B,Node *C,Node *D,int l,int r)
{
    if(l==r)return l;
    int cnt=A->r->val + B->r->val - C->r->val - D->r->val;
    int md=(l+r)/2;
    if(cnt==0)return query(A->l,B->l,C->l,D->l,l,md);
    return query(A->r,B->r,C->r,D->r,md+1,r);
}
void dfs(int u,int w)
{
    lv[u]=w;
    for(int i=0;i<g[u].size();i++)
    {
        int y=g[u][i].F;
        if(lv[y])continue;
        p[0][y]=u;
        R[y]=upt(R[u],1,M,g[u][i].S,1);
        dfs(y,w+1);
    }
}
int LOG2(int x){
    for(int i=18;i>=0;i--)if(x&(1<<i))return i;
}
int LCA(int x,int y)
{
    while(x!=y)
    {
        int dif=abs(lv[x]-lv[y]);
        if(lv[x]==lv[y])
        {
            for(int i=18;i>=0;i--)
                if(p[i][x]!=p[i][y])
                {
                    x=p[i][x];
                    y=p[i][y];
                }
            if(p[0][x]==p[0][y])return p[0][x];
        }
        else if(lv[x]<lv[y]) y=p[LOG2(dif)][y];
        else x=p[LOG2(dif)][x];
    }
    return x;
}
int main()
{
    sint2(n,m);
    for(int i=0;i<m;i++)
    {
        sint3(x,y,w);
        v.pb(mkp(mkp(w,i+1),mkp(x,y)));
    }
    M=m;
    sort(all(v));
    for(int i=0;i<m;i++)
    {
        v[i].F.S=i+1;
    }
    int cnt=0;
    UnionFind uf(n);
    ll cost=0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        x=v[i].S.F;
        y=v[i].S.S;
        if(!uf.iss(x,y))
        {
            uf.us(x,y);
            cost+=v[i].F.F;
            ban[v[i].F.S]=1;
            g[x].pb(mkp(y,v[i].F.S));
            g[y].pb(mkp(x,v[i].F.S));
        }
    }
    R[0]=build(1,M);
    R[1]=R[0];
    dfs(1,1);
    for(int i=1;(1<<i)<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    ll ans=LLONG_MAX;
    for(int i=0;i<m;i++)
    {
        if(ban[v[i].F.S])continue;
        int x,y;
        x=v[i].S.F;
        y=v[i].S.S;
        int lca=LCA(x,y);
        int ret=query(R[x],R[y],R[lca],R[lca],1,M);
        debug(ret);
        debug(v[ret-1].F.F);
        ans=min(ans,ll(v[i].F.F-v[ret-1].F.F));
    }
    printf("%lld\n",cost+ans);
}
/*

*/
