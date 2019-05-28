#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
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
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void wl(int x)
{
    printf("%d\n",x);
}
void wl(double x)
{
    printf("%lf\n",x);
}
void wl(string x)
{
    printf("%s\n",x.c_str());
}
void wl(ll x)
{
    printf("%lld\n",x);
}
void w(int x)
{
    printf("%d ",x);
}
void w(double x)
{
    printf("%lf ",x);
}
void w(string x)
{
    printf("%s ",x.c_str());
}
void w(ll x)
{
    printf("%lld ",x);
}
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
        if(x>y) p[y]=x;
        else    p[x]=y;
    }
};
vi v[300005];
int in[300005];
int dp[300005];
int ans[300005];
void dfs(int u)
{
    if(v[u].size()==0)
    {
        dp[u]=1;
        return;
    }
    int mx=0;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(dp[y]==0)
            dfs(y);
        mx=max(mx,dp[y]);
    }
    mx++;
    dp[u]=mx;
    return;
}
void fillans(int u,int num=1)
{
    ans[u]=num;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(dp[y]==dp[u]-1 && ans[y]==0)
            fillans(y,num+1);
    }
}
int main()
{
    sint3(n,m,k);
    UnionFind uf(m);
    vii g;
    while(k--)
    {
        sstring(tmp);
        stringstream ss;
        ss<<tmp;
        int x,y;
        char c;
        ss>>x;
        ss>>c;
        ss>>y;
        // debug(x);
        // debug(c);
        // debug(y);
        if(c=='=')
            if(!uf.iss(x,y))
            {
                uf.us(x,y);
                // printf("%d is in same group as %d\n",x,y);
            }
        if(c=='<')
        {
            // printf("push %d %d to g\n",x,y);
            g.pb(mkp(x,y));
        }
    }
    for(int i=0;i<g.size();i++)
    {
        int x,y;
        x=g[i].F;
        y=g[i].S;
        // debug(x);
        x=uf.fs(x);
        // debug(x);
        y=uf.fs(y);
        // printf("%d heavier than %d\n",y,x);
        v[y].pb(x);
        in[x]++;
    }
    for(int i=1;i<=m;i++)
    {
        int tmp=uf.fs(i);
        // debug(i);
        // debug(tmp);
        if(in[tmp]==0)
        {
            // printf("dfs on %d\n",tmp);
            dfs(tmp);
            if(dp[tmp]==n)
                fillans(tmp);
        }
    }
    for(int i=1;i<=m;i++)
    {
        // printf("%d : dp = %d   ans = %d\n",i,dp[i],ans[i]);
        int x=ans[uf.fs(i)];
        if(x==0)printf("?\n");
        else printf("K%d\n",n-x+1);
    }
}
/*

*/
