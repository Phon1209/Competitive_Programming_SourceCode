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
int depth[100005];
int p[20][100005];
vi v[100005];
int ff[100005],lf[100005];
int found[200005];
int cnt=0;
int fw[200005];
void add(int idx,int val)
{
    while(idx<=cnt)
    {
        fw[idx]+=val;
        idx+=(idx&-idx);
    }
}
int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=fw[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
void dfs(int u,int dep=1)
{
    found[++cnt]=u;
    if(ff[u]==0)ff[u]=cnt;
    lf[u]=cnt;
    depth[u]=dep;
    debug(u);
    debug(v[u].size());
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i] ;
        if(depth[y]==0){
            dfs(y,dep+1);
            found[++cnt]=u;
            lf[u]=cnt;
        }
    }
}
int LCA(int x,int y)
{
    while(x!=y)
    {
        if(depth[x]<depth[y])swap(x,y);
        if(depth[x]==depth[y])
        {
            for(int i=18;i>=0;i--)
                if(p[i][x]!=p[i][y])
                {
                    x=p[i][x];
                    y=p[i][y];
                }
            if(p[0][x]==p[0][y])return p[0][x];
        }
        else x=p[(int)log2(depth[x]-depth[y])][x];
    }
    return x;
}
int main()
{
    sint(n);
    p[0][1]=0;
    for(int i=2;i<=n;i++)
    {
        sint(tmp);
        p[0][i]=tmp;
        debug(tmp);
        debug(i);
        v[tmp].pb(i);
    }
    dfs(1);
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)
            p[i][j]=p[i-1][p[i-1][j]];
            /*
    for(int i=1;i<=cnt;i++)
        W(found[i]);
    endl;
    for(int i=1;i<=n;i++)
    {
        debug(i);
        debug(ff[i]);
        debug(lf[i]);
    }
    // */
    for(int i=1;i<=cnt;i++)
    {
        add(i,depth[found[i]]);
        add(i+1,-depth[found[i]]);
    }
    sint(q);
    while(q--)
    {
        sint(cmd);
        if(cmd==1) //find path
        {
            sint2(x,y);
            int lca=LCA(x,y);
            int ans=sum(ff[x]);
            ans+=sum(ff[y]);
            ans-=(2*sum(ff[lca]));
            Wl(ans);
        }
        if(cmd==2) //delete node
        {
            sint(x);
            add(ff[x],-1);
            add(lf[x]+1,1);
        }
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
