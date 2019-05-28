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
ii lim[1005][1005];
int g[1005];
int d[1005][1005];
vii v[1005];
int main()
{
    vi path;
    sint2(n,m);
    sint2(a,b);
    sint2(k,o);
    for(int i=0;i<o;i++)
    {
        sint(tmp);
        path.pb(tmp);
    }
    while(m--)
    {
        sint3(x,y,w);
        v[x].pb(mkp(y,w));
        v[y].pb(mkp(x,w));
        d[x][y]=d[y][x]=w;
    }
    int overall=0;
    for(int i=1;i<path.size();i++)
    {
        int x=path[i-1];
        int y=path[i];
        lim[x][y]=lim[y][x]=mkp(overall,overall+d[x][y]);
        overall+=d[x][y];
    }
    for(int i=1;i<=n;i++)g[i]=inf;
    priority_queue<pair<int,int> > pq;
    pq.push(mkp(-k,a));
    ii nothing={0,0};
    while(!pq.empty())
    {
        int w=-pq.top().F;
        int u=pq.top().S;
        pq.pop();
        if(g[u]<w)continue;
        g[u]=w;
        if(u==b)
        {
            printf("%d\n",w-k);
            break;
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            int cost=v[u][i].S;
            int nw=w;
            if(lim[u][y]!=nothing)
            {
                if(w<lim[u][y].S && w>=lim[u][y].F)nw=lim[u][y].S;
            }
            if(nw+cost<g[y])
            {
                g[y]=nw+cost;
                pq.push(mkp(-g[y],y));
            }
        }
    }
}
/*

*/
