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
ll mon[100005];
vi v[100005][20];
int p[20][100005];
vi g[100005];
int LOG2(int x)
{
    for(int i=18;i>=0;i--)
    {
        if(x&(1<<i))return i;
    }
}
int h[100005];
void dfs(int u)
{
    if(g[u].size()==0)
    {
        h[u]=0;
        return ;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int y=g[u][i];
        dfs(y);
        h[u]=max(h[u],h[y]+1);
    }
}
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        sint(par);
        par++;
        slong(tmp);
        mon[i]=tmp;
        p[0][i]=par;
        if(par==0)continue;
        g[par].pb(i);
        v[par][0].pb(i);
    }
    for(int i=1;(1<<i)<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
            int u=p[i-1][j];
            int y=p[i-1][u];
            if(y==0)continue;
            v[y][i].pb(j);
        }
    }
    dfs(1);
    // return 0;
    /*
    for(int i=1;i<=n;i++)
    {
        debug(i);
        for(int j=0;j<=18;j++)
        {
            printf("%d | ",j);
            for(int k=0;k<v[i][j].size();k++)
            {
                printf("%d ",v[i][j][k]);
            }
            endl;
        }
    }
    */
    while(m--)
    {
        sint3(x,y,b);
        x++;
        b=-b;
        queue<ii> q;
        q.push(mkp(x,y));
        int cnt=0;
        while(!q.empty())
        {
            int u,d;
            u=q.front().F;
            d=q.front().S;
            // printf(">>%d %d\n",u,d);
            q.pop();
            if(d==0)
            {
                mon[u]-=b;
                // debug(u);
                cnt++;
                continue;
            }
            int o=LOG2(d);
            for(int i=0;i<v[u][o].size();i++)
            {
                int w=v[u][o][i];
                if(h[w]<(d-(1<<o)))continue;
                q.push(mkp(w,d-(1<<o)));
            }
        }
        mon[x]+=(b*cnt);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld\n",mon[i]);
    }
}
/*

*/
