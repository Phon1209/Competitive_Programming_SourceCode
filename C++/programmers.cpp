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

int g[1005][1005];
int use=0;
bool ok=0;
int chk[1005];
vi v[1005];

void dfs(int u,int t,int now)
{
    chk[u]=1;
    if(u==t)
    {
        ok=1;
        use=now;
        return ;
    }
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(!g[u][y] || chk[y])continue;
        dfs(y,t,min(now,g[u][y]));
        if(ok)
        {
            g[u][y]-=use;
            g[y][u]+=use;
            return;
        }
    }
}
int flow(int s,int t)
{
    memset(chk,0,sizeof(chk));
    ok=0;
    dfs(s,t,inf);
    return ok? use:0;
}

void _main()
{
    sint2(p,s);
    sint2(c,m);
    for(int i=0;i<=1000;i++)v[i].clear();
    memset(g,0,sizeof(g));
    for(int i=1;i<=p;i++)g[0][i]=1,v[0].pb(i);
    for(int i=501;i<=500+s;i++)g[i][1000]=c,v[i].pb(1000);
    while(m--)
    {
        sint2(x,y);
        y+=500;
        v[x].pb(y);
        v[y].pb(x);
        g[x][y]++;
    }
    int mf=0;
    while(1)
    {
        int f=flow(0,1000);
        if(!f)break;
        mf+=f;
    }
    printf("%d\n",mf);
    return ;
}
int main()
{
    sint(t);
    while(t--)
    {
        _main();
    }
}
/*

*/
