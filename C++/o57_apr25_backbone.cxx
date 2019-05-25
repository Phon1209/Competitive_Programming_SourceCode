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
int lv[205],p[10][205];
vector<tuple<int,int,int,int>> conn;
vi v[205];
vii use,ans;
int n,m;
bool die[205][205];
void solve(int idx)
{
    if(use.size()>10 || (ans.size()!=0 && use.size()>ans.size()))return;
    if(idx==m)
    {
        ans=use;
        return;
    }
    int d,l,x,y;
    tie(d,l,x,y)=conn[idx];
    int tx=x;
    while(p[0][tx]!=l && tx!=l)
    {
        if(die[tx][p[0][tx]])break;
        tx=p[0][tx];
    }
    if((p[0][tx]==l && !die[tx][l]) || tx==l)
    {
        int ty=y;
        while(p[0][ty]!=l && ty!=l)
        {
            if(die[ty][p[0][ty]])break;
            ty=p[0][ty];
        }
        if((p[0][ty]==l && !die[ty][l]) || ty==l)
        {
            if(x!=l)
            {
                die[tx][l]=1;
                use.pb(tx,l);
                solve(idx+1);
                use.pop_back();
                die[tx][l]=0;
            }
            if(y!=l)
            {
                die[ty][l]=1;
                use.pb(ty,l);
                solve(idx+1);
                use.pop_back();
                die[ty][l]=0;
            }
        }
        else solve(idx+1);
    }
    else solve(idx+1);
}
void dfs(int u,int d=1)
{
    lv[u]=d;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(lv[y]==0){
            dfs(y,d+1);
            p[0][y]=u;
        }
    }
}
int lca(int x,int y)
{
    while(x!=y)
    {
        if(lv[x]<lv[y])swap(x,y);
        if(lv[x]==lv[y])
        {
            for(int i=8;i>=0;i--)
            if(p[i][x]!=p[i][y])
            {
                x=p[i][x];
                y=p[i][y];
            }
            if(p[0][x]==p[0][y])return p[0][x];
        }
        if(lv[x]!=lv[y]) x=p[(int)log2(lv[x]-lv[y])][x];
    }
    return x;
}
int main()
{
    int2(n,m);
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)
            p[i][j]=p[i-1][p[i-1][j]];
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        int LCA=lca(x,y);
        // debug(LCA);
        // debug(1);
        conn.pb(-lv[LCA],LCA,x,y);
        // debug(2);
    }
    sort(all(conn));
    solve(0);
    Wl((int)ans.size());
    for(int i=0;i<ans.size();i++){W(ans[i].F);Wl(ans[i].S);}
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
