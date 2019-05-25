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

int st[50005];
int ed[50005];
class UnionFind{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+5,0);
        for(int i=0;i<=n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:p[i]=fs(p[i]);
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        p[fs(i)]=fs(j);
    }
};
vii v[50005];
int depth[50005];
int p[17][50005];
ll len[50005];
void dfs(int u)
{
    for(ii y:v[u])
    {
        if(y.F==p[0][u])continue;
        p[0][y.F]=u;
        depth[y.F]=depth[u]+1;
        len[y.F]=len[u]+y.S;
        dfs(y.F);
    }
}
int LCA(int x,int y)
{
    while(x!=y)
    {
        if(depth[x]<depth[y])swap(x,y);
        if(depth[x]==depth[y])
        {
            for(int i=16;i>=0;i--)
            {
                if(p[i][x]!=p[i][y])
                {
                    x=p[i][x];
                    y=p[i][y];
                }
            }
            if(p[0][x]==p[0][y])return p[0][x];
        }
        x=p[(int)log2(depth[x]-depth[y])][x];
    }
    return x;
}
// ll g[50005][2005];
int main()
{
    sint3(n,s,t);
    sint2(m,q);
    vii e;
    for(int i=0;i<m;i++)
    {
        sint3(x,y,w);
        v[x].pb(y,w);
        v[y].pb(x,w);
        e.pb(x,y);
    }
    UnionFind uf(n);
    for(int i=0;i<s;i++)
    {
        int1(st[i]);
    }
    for(int i=0;i<t;i++)
    {
        int1(ed[i]);
    }
    bool isTree=true;
    for(int i=0;i<e.size() && isTree;i++)
    {
        if(!uf.iss(e[i].F,e[i].S))
            uf.us(e[i].F,e[i].S);
        else isTree=false;
    }
    if(isTree)
    {
        dfs(1);
        for(int i=1;(1<<i)<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                p[i][j]=p[i-1][p[i-1][j]];
            }
        }
        // return 0;
        while(q--)
        {
            sint2(x,y);
            if(LCA(x,y)>n || LCA(x,y)<0)while(1);
            Wl(len[x]+len[y]-2*(len[LCA(x,y)]));
        }
        return 0;
    }
    while(q--)
    {
        // sint2(x,y);
        // priority_queue<tuple<ll,int,int> > pq;
        // pq.emplace(0,x,1);
        // while(!pq.empty())
        // {
        //     int w,u,step;
        //     tie(w,u,step);
        //     w=-w;
        //     if(g[u][step]<w)continue;
        //     g[u][step]=w;
        //     if(u==y && step>=1000)
        //     {
        //         Wl(w);
        //         break;
        //     }
        //     for(ii edge:v[u])
        //     {
        //         int y=edge.F;
        //         int cost=edge.S;
        //         if(g[y][step+1]>g[u][step]+cost)
        //         {
        //             g[y][step+1]=g[u][step]+cost;
        //             pq.emplace(-g[y][step+1],y,step+1);
        //         }
        //     }
        // }
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
