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
int dp[300005];
vi v[300005];
ii brk; //pair to break to 2 tree
void dfs(int u)
{
    vi s;
    dp[u]=0;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(dp[y]!=-1)continue;
        if((u==brk.F && y==brk.S) || (u==brk.S && y==brk.F))continue;
        dfs(y);
        s.pb(dp[y]);
    }
    sort(all(s));
    dp[u]=s.size();
    int add=0;
    for(int i=s.size()-1;i>=0;i--)
        add=max(add,s[i]-i);
    dp[u]+=add;
}
vii path;
bool getpath(int u,int p,int target)
{
    if(u==target)
    {
        return true;
    }
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(y==p)continue;
        if(getpath(y,u,target))
        {
            path.pb(mkp(u,y));
            return true;
        }
    }
    return false;
}
int main()
{
    sint3(n,m,p);
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    getpath(m,-1,p);
    int mn=0,mx=path.size();
    int ans=inf;
    while(mn<=mx)
    {
        int md=(mn+mx)/2;
        brk.F=path[md].F;
        brk.S=path[md].S;
        memset(dp,-1,sizeof(dp));
        dfs(m);
        dfs(p);
        ans=min(ans,max(dp[m],dp[p]));
        if(dp[m]<dp[p])
            mx=md-1;
        else if(dp[m]>dp[p])
            mn=md+1;
        else break;
    }
    wl(ans);
}
/*

*/
